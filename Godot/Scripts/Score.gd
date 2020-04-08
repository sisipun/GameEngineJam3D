extends Label

var score = 0

func _ready():
	text = String(score)


func _on_bonus_collected():
	score = score + 1
	_ready()
