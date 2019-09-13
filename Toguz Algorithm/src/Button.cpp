#include "Button.h"
#include "Application.h"

Button::Button(State* t_state):
	m_parentState(*t_state)
{
}

Button::~Button()
{
}

void Button::update()
{
}

State* Button::handleEvents(sf::Event&)
{
	return nullptr;
}

void Button::draw()
{
}

bool Button::isMouseOver()
{
	sf::Vector2i mousePos = sf::Mouse::getPosition(m_parentState.getApp().window);
	sf::Vector2f bodyPos = m_body.getPosition();
	sf::Vector2f bodySize = m_body.getSize();

	if (mousePos.x >= bodyPos.x && mousePos.x <= bodyPos.x + bodySize.x &&		//mouse is inbetween the left and the right edge
		mousePos.y >= bodyPos.y && mousePos.y <= bodyPos.y + bodySize.y)		//mouse is inbetween the top and bottom edge
		return true;
	else return false;

}
