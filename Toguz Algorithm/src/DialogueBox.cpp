#include "DialogueBox.h"
#include "Application.h"

DialogueBox::DialogueBox(State* t_parentState,sf::Vector2f t_pos, sf::Vector2f t_size):
	m_parentState(*t_parentState),
	m_dragBar(t_parentState,this,t_pos,sf::Vector2f(t_size.x,20))
{
	m_mainBox.setPosition(t_pos);
	m_mainBox.setSize(t_size);
	m_mainBox.setOutlineThickness(2);
}

DialogueBox::DialogueBox(State* t_parentState, sf::Vector2f t_size):
	m_parentState(*t_parentState),
	m_dragBar(t_parentState,this,sf::Vector2f(960 - (t_size.x/2),540 - (t_size.y/2)),sf::Vector2f(t_size.x,20))
{
	m_mainBox.setPosition(sf::Vector2f(960 - (t_size.x / 2),540 - (t_size.y / 2)));
	m_mainBox.setSize(t_size);
}

DialogueBox::~DialogueBox()
{
}

void DialogueBox::draw(sf::RenderWindow& window)
{
	window.draw(m_mainBox);
	m_dragBar.draw(window);
}

void DialogueBox::handleEvents(sf::Event& t_event)
{
	m_dragBar.handleEvents(t_event);
}

void DialogueBox::update()
{
	m_dragBar.update();
}

void DialogueBox::init()
{
}

void DialogueBox::setPosition(sf::Vector2f t_pos)
{
	m_mainBox.setPosition(t_pos); //relative to main window
	m_dragBar.setPosition(t_pos);

}