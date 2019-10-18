#include "MenuState.h"

MenuState::MenuState(Application* t_app):
	State(*t_app, "res/wood.jpg"),
	m_gameButton(new StateButton(this, sf::Vector2f(100,1080/3), sf::Vector2f(300, 100), "Play", CHC_goGame)),
	m_quitButton(new StateButton(this, sf::Vector2f(100,1080/3 * 2), sf::Vector2f(300,100), "Quit", CHC_quit))
{
	m_titleText.setFont(font);
	m_titleText.setFillColor(sf::Color::White);
	m_titleText.setCharacterSize(50);
	m_titleText.setString("Kogut Zorgool");
	m_titleText.setPosition(sf::Vector2f(100, 100));
}

MenuState::~MenuState()
{
	delete m_gameButton;
	m_gameButton = nullptr;
	delete m_quitButton;
	m_quitButton = nullptr;
}

void MenuState::draw(sf::RenderWindow& t_window)
{
	t_window.draw(m_backgroundSprite);
	t_window.draw(m_titleText);
	m_gameButton->draw(t_window);
	m_quitButton->draw(t_window);
}

void MenuState::handleEvents(sf::Event& t_event)
{
	m_gameButton->handleEvents(t_event);
	m_quitButton->handleEvents(t_event);
}

void MenuState::update()
{
	m_gameButton->update();
	m_quitButton->update();
}

void MenuState::init()
{
}
