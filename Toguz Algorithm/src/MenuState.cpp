#include "MenuState.h"

MenuState::MenuState(Application* t_app):
	State(*t_app)
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
}

State* MenuState::handleEvents(sf::Event& t_event)
{
	return nullptr;
}

void MenuState::update()
{
}

void MenuState::entry()
{
}
