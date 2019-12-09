#include "DragBar.h"
#include "Application.h"
#include "DialogueBox.h"

DragBar::DragBar(State* t_parentState,DialogueBox* t_parentBox, sf::Vector2f t_position, sf::Vector2f t_size):
	ClickRect(t_parentState,t_position,t_size),
	m_parentBox(*t_parentBox),
	m_isMouseClicked(false),
	m_hasRelativePos(false)
{

}

DragBar::~DragBar()
{
}

void DragBar::update()
{
	if (m_isMouseClicked)
	{
		sf::Vector2i initPos = sf::Mouse::getPosition(m_parentState.getApp().window);
		sf::Vector2f mousePos = m_parentState.getApp().window.mapPixelToCoords(initPos);
		if (!m_hasRelativePos)
		{
			m_mouseRelativePos = mousePos - m_parentBox.m_mainBox.getPosition();
			m_hasRelativePos = true;
		}

		m_parentBox.setPosition(mousePos - m_mouseRelativePos);
	}
	else
	{
		m_hasRelativePos = false;
	}
}

void DragBar::handleEvents(sf::Event& t_event)
{
	if (t_event.type == sf::Event::MouseButtonPressed && isMouseOver())
	{
		if (t_event.mouseButton.button == sf::Mouse::Left)
		{
			m_isMouseClicked = true;
		}
	}
	if (t_event.type == sf::Event::MouseButtonReleased)
	{
		if (t_event.mouseButton.button == sf::Mouse::Left)
		{
			m_isMouseClicked = false;
		}
	}
}

void DragBar::draw(sf::RenderWindow& t_window)
{
	t_window.draw(m_body);
}

void DragBar::init()
{
}

void DragBar::setPosition(sf::Vector2f t_pos)
{
	m_body.setPosition(t_pos);
}
