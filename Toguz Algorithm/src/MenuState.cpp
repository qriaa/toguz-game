#include "MenuState.h"
#include "DialogueBox.h"
#include "ObjectManager.h"

MenuState::MenuState(Application* t_app):
	State(*t_app, "Toguz Algorithm/res/wood.jpg")
{
	createGameObject(new StateButton(this, sf::Vector2f(100, 1080 / 3), sf::Vector2f(300, 100), "Play", CHC_goGame));
	createGameObject(new StateButton(this, sf::Vector2f(100, 1080 / 3 * 2), sf::Vector2f(300, 100), "Quit", CHC_quit));

	m_titleText.setFont(font);
	m_titleText.setFillColor(sf::Color::White);
	m_titleText.setCharacterSize(50);
	m_titleText.setString("Kogut Zorgool");
	m_titleText.setPosition(sf::Vector2f(100, 100));
}

MenuState::~MenuState()
{
}

void MenuState::draw(sf::RenderWindow& t_window)
{
	t_window.draw(m_backgroundSprite);
	t_window.draw(m_titleText);
	m_objectManager->drawGameObjects(t_window);
}

void MenuState::handleEvents(sf::Event& t_event)
{
	m_objectManager->handleEventsGameObjects(t_event);
}

void MenuState::update()
{
	m_objectManager->updateGameObjects();
}

void MenuState::init()
{
}
