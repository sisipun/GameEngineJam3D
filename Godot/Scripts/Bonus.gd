extends Area

const ROTATION_SPEED = 90

signal bonusCollected

func _ready():
	pass
	
func _physics_process(delta):
	rotate_y(deg2rad(delta * ROTATION_SPEED))

func _on_body_entered(body):
	if body.name == "Hero":
		emit_signal("bonusCollected")
		queue_free()
