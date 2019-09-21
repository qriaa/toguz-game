#include "Button.h"

Button::Button(State* t_state):
	ClickRect(t_state)
{
	m_body.setPosition(sf::Vector2f(100,100));
	m_body.setSize(sf::Vector2f(100, 100));
	m_body.setOutlineThickness(-2);
	m_body.setOutlineColor(sf::Color::Red);
}

Button::~Button()
{
}

void Button::update()
{
}

State* Button::handleEvents(sf::Event& t_event)
{
	return nullptr;
}

void Button::draw()
{
}
