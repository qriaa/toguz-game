#include "DragBar.h"
#include "Application.h"
#include "DialogueBox.h"

DragBar::DragBar(State* t_parentState,DialogueBox* t_parentBox, sf::Vector2f t_position, sf::Vector2f t_size):
	Button(t_parentState,t_position,t_size),
	m_parentBox(*t_parentBox),
	m_hasRelativePos(false)
{
	m_body.setOutlineThickness(-1);
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
	Button::update();
}

void DragBar::handleEvents(sf::Event& t_event)
{
	Button::handleEvents(t_event);
}

void DragBar::draw(sf::RenderWindow& t_window)
{
	Button::draw(t_window);
}

void DragBar::init()
{
}

void DragBar::setPosition(sf::Vector2f t_pos)
{
	m_body.setPosition(t_pos);
}

void DragBar::m_initActive()
{
	sf::Vector2i initPos = sf::Mouse::getPosition(m_parentState.getApp().window);
	sf::Vector2f mousePos = m_parentState.getApp().window.mapPixelToCoords(initPos);
	m_mouseRelativePos = mousePos - m_parentBox.m_mainBox.getPosition();
	m_hasRelativePos = true;
}

void DragBar::m_doOnActive()
{
	sf::Vector2i initPos = sf::Mouse::getPosition(m_parentState.getApp().window);
	sf::Vector2f mousePos = m_parentState.getApp().window.mapPixelToCoords(initPos);
	m_parentBox.setPosition(mousePos - m_mouseRelativePos);
}
