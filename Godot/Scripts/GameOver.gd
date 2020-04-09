extends Label

func _ready():
	pass

func _on_game_over():
	text = "You win!"


func _on_hero_dead():
	text = "You loose!"
