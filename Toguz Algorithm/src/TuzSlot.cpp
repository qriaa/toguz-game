#include "..\include\TuzSlot.h"
#include "GameState.h"

TuzSlot::TuzSlot(GameState* t_parentGame, sf::Vector2f t_position, sf::Vector2f t_size, Player_Num t_whoseTuzSlot):
	m_parentGame(*t_parentGame),
	m_whoseTuzSlot(t_whoseTuzSlot)
{
	m_body.setPosition(t_position);
	m_body.setSize(t_size);

	m_body.setFillColor(sf::Color::White);
	m_body.setOutlineThickness(-2);
	m_body.setOutlineColor(sf::Color::Black);

	switch (m_whoseTuzSlot)
	{
	case PLR_ONE:
		m_body.setFillColor(sf::Color::Red);
		break;
	case PLR_TWO:
		m_body.setFillColor(sf::Color::Blue);
		break;
	}
}

TuzSlot::~TuzSlot()
{
}

void TuzSlot::update()
{
	if (m_whoseTuzSlot == PLR_ONE)
	{
		if (m_parentGame.m_board.tuzOne == -1)
			hasTuz = true;
		else
			hasTuz = false;
	}
	else if (m_whoseTuzSlot == PLR_TWO)
	{
		if (m_parentGame.m_board.tuzTwo == -1)
			hasTuz = true;
		else
			hasTuz = false;
	}

	if (!hasTuz)
	{
		m_body.setFillColor(sf::Color::White);
	}
}

void TuzSlot::handleEvents(sf::Event&)
{
}

void TuzSlot::draw(sf::RenderWindow& t_window)
{
	t_window.draw(m_body);
}

void TuzSlot::changePlayer()
{
	switch (m_whoseTuzSlot)
	{
	case PLR_ONE:
		m_whoseTuzSlot = PLR_TWO;
		m_body.setFillColor(sf::Color::Blue);
		break;
	case PLR_TWO:
		m_whoseTuzSlot = PLR_ONE;
		m_body.setFillColor(sf::Color::Red);
		break;
	}
}
