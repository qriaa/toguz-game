#include "MenuState.h"

MenuState::MenuState(Application* t_app):
	State(*t_app), button(this, sf::Vector2f(100,100), sf::Vector2f(100, 100))
{
	m_font.loadFromFile("res/comic.ttf");
	m_titleText.setFont(m_font);
	m_titleText.setFillColor(sf::Color::Black);
	m_titleText.setString("Kogut Zorgool");
	m_titleText.setPosition(sf::Vector2f(200, 200));
}

MenuState::~MenuState()
{
}

void MenuState::draw()
{
	m_app.window.draw(m_titleText);
	button.draw(m_app.window);
}

State* MenuState::handleEvents(sf::Event& t_event)
{
	button.handleEvents(t_event);
	return nullptr;
}

void MenuState::update()
{
	button.update();
}

void MenuState::entry()
{
}
