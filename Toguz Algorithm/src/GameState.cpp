#include "GameState.h"

GameState::GameState(Application* t_app):
	State(*t_app, "res/wood.jpg"),
	m_menuButton(new StateButton(this, sf::Vector2f(1920 - 300, 1080 - 200), sf::Vector2f(200,100),"Menu",CHC_goMenu))
{
	
}

GameState::~GameState()
{
}

void GameState::draw(sf::RenderWindow& t_window)
{
	t_window.draw(m_backgroundSprite);
	m_menuButton->draw(t_window);
}

void GameState::handleEvents(sf::Event& t_event)
{
	m_menuButton->handleEvents(t_event);
}

void GameState::update()
{
	m_menuButton->update();
}

void GameState::init()
{
}

bool GameState::makeMove(int t_hole)
{
	//hole is empty
	if (m_board.holes[t_hole] == 0) 
		return false;

	//hole has one ball
	if (m_board.holes[t_hole] == 1)
	{
		m_board.holes[t_hole] = 0;
		++m_board.holes[t_hole + 1];
		return true;
	}

	//hole has more than one balls
	int hand = m_board.holes[t_hole] - 1;
	m_board.holes[t_hole] = 1;
	
	int i = 1;
	for (; hand > 0; i++)
	{
		++m_board.holes[t_hole + i];
		--hand;
	}
	m_checkHole(i);
	return true;
}

void GameState::m_checkHole(int t_hole)
{
	if (m_activePlayer == PLR_ONE && !(t_hole <= 8))
	{
		if (m_board.holes[t_hole] % 2 == 0)
		{
			m_board.kazanOne += m_board.holes[t_hole];
			m_board.holes[t_hole] = 0;
		}
		if (m_board.tuzOne != -1 && m_board.holes[t_hole] == 3 && t_hole != 17)
		{
			m_board.tuzOne = t_hole;
		}
	}

	else if (m_activePlayer == PLR_TWO && !(t_hole >= 9))
	{
		if (m_board.holes[t_hole] % 2 == 0)
		{
			m_board.kazanOne += m_board.holes[t_hole];
			m_board.holes[t_hole] = 0;
		}
		if (m_board.tuzTwo != -1 && m_board.holes[t_hole] == 3 && t_hole != 8)
		{
			m_board.tuzTwo = t_hole;
		}
	}

	if (m_board.tuzOne != -1)
	{
		m_board.kazanOne += m_board.holes[m_board.tuzOne - 1];
		m_board.holes[m_board.tuzOne - 1] = 0;
	}
	if (m_board.tuzTwo != -1)
	{
		m_board.kazanTwo += m_board.holes[m_board.tuzTwo - 1];
		m_board.holes[m_board.tuzTwo - 1] = 0;
	}

}
