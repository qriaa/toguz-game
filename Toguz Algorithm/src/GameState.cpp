#include "GameState.h"
#include "ObjectManager.h"

GameState::GameState(Application* t_app):
	State(*t_app, "Toguz Algorithm/res/wood.jpg"),
	m_board(),
	m_activePlayer(PLR_ONE),
	m_playerChanged(false),
	m_toBeChangedFlag(false),
	m_gameFinished(false)
{
	createGameObject(new StateButton(this, sf::Vector2f(1920 - 300, 1080 - 200), sf::Vector2f(200, 100), "Menu", CHC_goMenu));
	for (int i = 0; i < 9; i++)
	{
		createGameObject(new HoleButton(this,sf::Vector2f(465 + 110 * i, 640), sf::Vector2f(100,100), i ));
	}
	for (int i = 9; i > 0; i--)
	{
		createGameObject(new HoleButton(this, sf::Vector2f(1345 - 110 * (9-i), 340), sf::Vector2f(100, 100), 18-i));
	}

	createGameObject(new Kazan(this, sf::Vector2f(575,450), sf::Vector2f(870,80), PLR_ONE));
	createGameObject(new Kazan(this, sf::Vector2f(465,550), sf::Vector2f(870,80), PLR_TWO));
	createGameObject(new TuzSlot(this, sf::Vector2f(1355,550), sf::Vector2f(80,80), PLR_ONE));
	createGameObject(new TuzSlot(this, sf::Vector2f(475,450), sf::Vector2f(80,80), PLR_TWO));
}

GameState::~GameState()
{
}

void GameState::draw(sf::RenderWindow& t_window)
{
	t_window.draw(m_backgroundSprite);

	m_objectManager->drawGameObjects(t_window);
}

void GameState::handleEvents(sf::Event& t_event)
{
	m_objectManager->handleEventsGameObjects(t_event);
}

void GameState::update() //holy fuck what a mess
{
	if (m_toBeChangedFlag == true)
	{
		m_playerChanged = true;
		m_toBeChangedFlag = false;
	}

	m_objectManager->updateGameObjects();

	m_playerChanged = false;
}

void GameState::init()
{
}

bool GameState::makeMove(int t_hole)
{
	//game finished
	if (m_gameFinished)
		return false;

	//wrong player
	if (t_hole < 9 && m_activePlayer != PLR_ONE ||
		t_hole > 8 && m_activePlayer != PLR_TWO)
		return false;

	//hole has tuz in it
	if (t_hole == m_board.tuzOne || t_hole == m_board.tuzTwo)
		return false;

	//hole is empty
	if (m_board.holes[t_hole] == 0) 
		return false;

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
		m_changeActivePlayer();
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
	m_checkForVictory();
	if (!m_gameFinished)
		m_changeActivePlayer();

	return true;
}

bool GameState::hasPlayerChanged()
{
	return m_playerChanged;
}

Player_Num GameState::getActivePlayer()
{
	return m_activePlayer;
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
		if (m_board.tuzOne == -1 && m_board.holes[t_hole] == 3 && t_hole != 17 && m_board.tuzTwo != t_hole - 9)
		{
			m_board.tuzOne = t_hole;
		}
	}

	else if (m_activePlayer == PLR_TWO && !(t_hole >= 9))
	{
		if (m_board.holes[t_hole] % 2 == 0)
		{
			m_board.kazanTwo += m_board.holes[t_hole];
			m_board.holes[t_hole] = 0;
		}
		if (m_board.tuzTwo == -1 && m_board.holes[t_hole] == 3 && t_hole != 8 && m_board.tuzOne != t_hole + 9)
		{
			m_board.tuzTwo = t_hole;
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

void GameState::m_changeActivePlayer()
{
	if (m_activePlayer == PLR_ONE)
	{
		m_activePlayer = PLR_TWO;
		m_toBeChangedFlag = true;
	}
	else if (m_activePlayer == PLR_TWO)
	{
		m_activePlayer = PLR_ONE;
		m_toBeChangedFlag = true;
	}
}

void GameState::m_checkForVictory()
{
	if (m_board.kazanOne > 81)
	{
		m_endGame(PLR_ONE);
		m_gameFinished = true;
		return;
	}
	else if (m_board.kazanTwo > 81)
	{
		m_endGame(PLR_TWO);
		m_gameFinished = true;
		return;
	}
}

void GameState::m_endGame(Player_Num t_victoriousPlayer) // TODO: add game finish window
{
	createGameObject(new GameFinishBox(this, &m_board, t_victoriousPlayer));
}
