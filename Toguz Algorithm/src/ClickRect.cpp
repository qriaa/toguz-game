#include "ClickRect.h"
#include "Application.h"

ClickRect::ClickRect(State* t_parentState, sf::Vector2f t_position, sf::Vector2f t_size):
	m_parentState(*t_parentState)
{
	m_body.setPosition(t_position);
	m_body.setSize(t_size);
}

ClickRect::~ClickRect()
{
}

void ClickRect::draw(sf::RenderWindow& window)
{
	window.draw(m_body);
}

void ClickRect::handleEvents(sf::Event&)
{
}

void ClickRect::update()
{
}

void ClickRect::init()
{
}

bool ClickRect::isMouseOver()
{
	sf::Vector2i initPos = sf::Mouse::getPosition(m_parentState.getApp().window);
	sf::Vector2f mousePos = m_parentState.getApp().window.mapPixelToCoords(initPos);
	sf::Vector2f bodyPos = m_body.getPosition();
	sf::Vector2f bodySize = m_body.getSize();

	if (mousePos.x >= bodyPos.x && mousePos.x <= bodyPos.x + bodySize.x &&		//mouse is inbetween the left and the right edge
		mousePos.y >= bodyPos.y && mousePos.y <= bodyPos.y + bodySize.y)		//mouse is inbetween the top and bottom edge
		return true;
	else return false;
}
