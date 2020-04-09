extends KinematicBody

var velocity = Vector3(0, -500, 0)
var gameOver = false
var dead = false
var jump = false
var collectedBonuses = 0
const SPEED = 1000
const JUMP_SPEED  = 2000
const BONUSES_COUNT = 4

signal gameOver
signal dead

func _ready():
	pass
	
func _physics_process(delta):
	if gameOver or dead:
		return
	
	if Input.is_action_pressed("ui_left") and Input.is_action_pressed("ui_right"):
		velocity.x = 0
	elif Input.is_action_pressed("ui_right"):
		velocity.z = SPEED
	elif Input.is_action_pressed("ui_left"):
		velocity.z = -SPEED
	else:
		velocity.z = lerp(velocity.z, 0, delta * 5)
		
	if Input.is_action_pressed("ui_up") and Input.is_action_pressed("ui_down"):
		velocity.x = 0
	elif Input.is_action_pressed("ui_up"):
		velocity.x = SPEED
	elif Input.is_action_pressed("ui_down"):
		velocity.x = -SPEED
	else:
		velocity.x = lerp(velocity.x, 0, delta * 5)
		
	if Input.is_key_pressed(KEY_SPACE) and not jump:
		jump = true
		velocity.y = JUMP_SPEED
	else:
		velocity.y = lerp(velocity.y, -500, delta * 5)
	
	move_and_slide(delta * velocity)

func _on_bonus_collected():
	$BonusSound.play()
	collectedBonuses = collectedBonuses + 1
	if collectedBonuses >= BONUSES_COUNT:
		gameOver = true
		emit_signal("gameOver")

func _on_enemy_touched():
	if not gameOver:
		$DeathSound.play()
		dead = true
		emit_signal("dead")


func _on_hero_on_ground():
	jump = false
