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
	if (m_holeNumber == m_parentGame.m_board.tuzOne || m_holeNumber == m_parentGame.m_board.tuzTwo)
		setText("T");
	else
		setText(std::to_string(m_parentGame.m_board.holes[m_holeNumber]));

	Button::update();
}

void HoleButton::draw(sf::RenderWindow& t_window)
{
	t_window.draw(m_body);
	m_textBehavior->draw(t_window);
}

void HoleButton::setHoleNumber(int t_number)
{
	m_holeNumber = t_number;
}

void HoleButton::m_initActive()
{
	m_parentGame.makeMove(m_holeNumber);
}

void HoleButton::m_doOnActive()
{
}
