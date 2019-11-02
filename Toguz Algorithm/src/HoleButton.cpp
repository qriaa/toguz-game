#include "HoleButton.h"
#include "GameState.h"

HoleButton::HoleButton(GameState* t_parentGame, sf::Vector2f t_position, sf::Vector2f t_size, int t_holeNumber):
	Button(t_parentGame,t_position,t_size, std::to_string(t_holeNumber)),
	m_parentGame(*t_parentGame),
	m_holeNumber(t_holeNumber)
{
}

void HoleButton::update()
{
	setText(std::to_string(m_parentGame.m_board.holes[m_holeNumber]));
	Button::update();
}

void HoleButton::draw(sf::RenderWindow& t_window)
{
	t_window.draw(m_body);
	t_window.draw(m_text);
}

void HoleButton::m_doOnActive()
{
	m_parentGame.makeMove(m_holeNumber);
}
