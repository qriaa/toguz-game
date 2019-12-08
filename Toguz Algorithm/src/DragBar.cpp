#include "DragBar.h"

DragBar::DragBar(State* t_parentState,DialogueBox* t_parentBox, sf::Vector2f t_position, sf::Vector2f t_size):
	ClickRect(t_parentState,t_position,t_size),
	m_parentBox(*t_parentBox)
{

}

DragBar::~DragBar()
{
}

void DragBar::update()
{
}

void DragBar::handleEvents(sf::Event&)
{
}

void DragBar::draw(sf::RenderWindow& t_window)
{
	t_window.draw(m_body);
}

void DragBar::init()
{
}
