#include "HoleButton.h"

HoleButton::HoleButton(State* t_parentState,GameState* t_parentGame, sf::Vector2f t_position, sf::Vector2f t_size, std::string t_string):
	Button(t_parentState,t_position,t_size,t_string),
	m_gameRef(*t_parentGame)
{
}

void HoleButton::m_doOnActive()
{
	
}
