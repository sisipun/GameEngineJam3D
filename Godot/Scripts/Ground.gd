extends StaticBody

func _ready():
	pass

signal heroOnGround

func _on_body_entered(body):
	if body.name == "Hero":
		emit_signal("heroOnGround")
