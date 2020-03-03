#include "..\include\GameFinishBox.h"

GameFinishBox::GameFinishBox(State* t_parentState, Board* t_board, Player_Num t_victoriousPlayer):
	DialogueBox(t_parentState, sf::Vector2f(500,500)),
	m_boardPtr(t_board),
	m_victoriousPlayer(t_victoriousPlayer)
{
	m_text.setFont(t_parentState->font);

	switch (m_victoriousPlayer)
	{
	case PLR_ONE:
		m_text.setString("Player one won with " + std::to_string(m_boardPtr->kazanOne) + " points!");
		break;
	case PLR_TWO:
		m_text.setString("Player two won with " + std::to_string(m_boardPtr->kazanTwo) + " points!");
		break;
	}
	m_text.setFillColor(sf::Color::Black);
	m_text.setCharacterSize(20);

	m_text.setPosition(
		sf::Vector2f(
			m_mainBox.getPosition().x + ((m_mainBox.getSize().x / 2) - (m_text.getGlobalBounds().width / 2)),
			m_mainBox.getPosition().y + 100)
	);

	m_stateButtonPtr = new StateButton(m_parentState,
		sf::Vector2f(m_mainBox.getPosition().x + 400, m_mainBox.getPosition().y + 400),
		sf::Vector2f(50, 50),
		"main menu",
		CHC_goMenu);

	createGameObject(m_stateButtonPtr);

}

GameFinishBox::~GameFinishBox()
{
}

void GameFinishBox::draw(sf::RenderWindow& window)
{
	DialogueBox::draw(window);
	window.draw(m_text);
}

void GameFinishBox::handleEvents(sf::Event& t_event)
{
	DialogueBox::handleEvents(t_event);
}

void GameFinishBox::update()
{
	DialogueBox::update();
}

void GameFinishBox::init()
{
	DialogueBox::init();
}

void GameFinishBox::setPosition(sf::Vector2f t_pos)
{
	DialogueBox::setPosition(t_pos);
	m_text.setPosition(
		sf::Vector2f(
			m_mainBox.getPosition().x + ((m_mainBox.getSize().x / 2) - (m_text.getGlobalBounds().width / 2)),
			m_mainBox.getPosition().y + 100)
	);
	m_stateButtonPtr->setPosition(sf::Vector2f(m_mainBox.getPosition().x + 400, m_mainBox.getPosition().y + 400));
}
