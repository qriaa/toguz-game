#include "GameState.h"

GameState::GameState(Application* t_app):
	State(*t_app, "res/wood.jpg"),
	m_menuButton(new StateButton(this, sf::Vector2f(1920 - 300, 1080 - 200), sf::Vector2f(200,100),"Menu",CHC_goMenu)),
	m_board(),
	m_activePlayer(PLR_ONE)
{
	for (int i = 0; i < 9; i++)
	{
		m_holes.emplace_back(new HoleButton(this,sf::Vector2f(465 + 110 * i, 640), sf::Vector2f(100,100), i ));
	}
	for (int i = 9; i > 0; i--)
	{
		m_holes.emplace_back(new HoleButton(this, sf::Vector2f(1345 - 110 * (9-i), 340), sf::Vector2f(100, 100), 18-i));
	}

	kazanOne = new Kazan(this, sf::Vector2f(575,450), sf::Vector2f(870,80), PLR_ONE);
	kazanTwo = new Kazan(this, sf::Vector2f(465,550), sf::Vector2f(870,80), PLR_TWO);
	tuzOne = new TuzSlot(this, sf::Vector2f(1355,550), sf::Vector2f(80,80), PLR_ONE);
	tuzTwo = new TuzSlot(this, sf::Vector2f(475,450), sf::Vector2f(80,80), PLR_TWO);

}

GameState::~GameState()
{
	while (!(m_holes.empty()))
	{
		delete m_holes.back();
		m_holes.pop_back();
	}
	delete kazanOne;
	kazanOne = nullptr;
	delete kazanTwo;
	kazanTwo = nullptr;
}

void GameState::draw(sf::RenderWindow& t_window)
{
	t_window.draw(m_backgroundSprite);
	m_menuButton->draw(t_window);

	for (HoleButton* hole : m_holes)
	{
		hole->draw(t_window);
	}
	kazanOne->draw(t_window);
	kazanTwo->draw(t_window);
	tuzOne->draw(t_window);
	tuzTwo->draw(t_window);
}

void GameState::handleEvents(sf::Event& t_event)
{
	m_menuButton->handleEvents(t_event);

	for (HoleButton* hole : m_holes)
	{
		hole->handleEvents(t_event);
	}
	kazanOne->handleEvents(t_event);
	kazanTwo->handleEvents(t_event);
	tuzOne->handleEvents(t_event);
	tuzTwo->handleEvents(t_event);
}

void GameState::update()
{
	m_menuButton->update();

	for (HoleButton* hole : m_holes)
	{
		hole->update();
	}
	kazanOne->update();
	kazanTwo->update();
	tuzOne->update();
	tuzTwo->update();
}

void GameState::init()
{
}

bool GameState::makeMove(int t_hole)
{
	//hole is empty
	if (m_board.holes[t_hole] == 0) 
		return false;
	//TODO: in case of incorrect move, do not change player and repeat move


	//hole has one ball
	if (m_board.holes[t_hole] == 1)
	{
		m_board.holes[t_hole] = 0;
		if (t_hole == 17)
		{
			++m_board.holes[0];
			m_checkHole(0);
		}
		else
		{
		++m_board.holes[t_hole + 1];
		m_checkHole(t_hole + 1);
		}
		return true;
	}

	//hole has more than one balls
	int hand = m_board.holes[t_hole] - 1;
	m_board.holes[t_hole] = 1;
	
	int currentHole = t_hole;
	while (hand > 0)
	{
		++currentHole;
		if (currentHole >= 18) currentHole = 0;
		++m_board.holes[currentHole];
		--hand;
	}
	m_checkHole(currentHole);

	//TODO: change current player

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
		if (m_board.tuzOne == -1 && m_board.holes[t_hole] == 3 && t_hole != 17)
		{
			m_board.tuzOne = t_hole;
			m_holes[t_hole]->setTuz();
		}
	}

	else if (m_activePlayer == PLR_TWO && !(t_hole >= 9))
	{
		if (m_board.holes[t_hole] % 2 == 0)
		{
			m_board.kazanOne += m_board.holes[t_hole];
			m_board.holes[t_hole] = 0;
		}
		if (m_board.tuzTwo == -1 && m_board.holes[t_hole] == 3 && t_hole != 8)
		{
			m_board.tuzTwo = t_hole;
			m_holes[t_hole]->setTuz();
		}
	}

	if (m_board.tuzOne != -1)
	{
		m_board.kazanOne += m_board.holes[m_board.tuzOne];
		m_board.holes[m_board.tuzOne] = 0;
	}
	if (m_board.tuzTwo != -1)
	{
		m_board.kazanTwo += m_board.holes[m_board.tuzTwo];
		m_board.holes[m_board.tuzTwo] = 0;
	}

}
