extends KinematicBody

const SPEED = 100

signal enemyTouched

func _ready():
	pass
	
func _physics_process(delta):
	var space_state = get_world().direct_space_state
	var heroPosition = get_parent().get_parent().get_node("Hero").get_transform().origin
	var enemyPosition = get_transform().origin
	var collResult = space_state.intersect_ray(heroPosition, enemyPosition)
	if null != collResult:
		var collider = collResult["collider"]
		if null != collider:
			var colliderParent = collider.get_parent()
			if null != colliderParent and colliderParent.name == "Walls":
				return
				
	var target = delta * SPEED * (heroPosition - enemyPosition)
	target.y = 0
	move_and_slide(target)


func _on_body_entered(body):
	if body.name == "Hero":
		emit_signal("enemyTouched")
