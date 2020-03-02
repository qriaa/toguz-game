#include "..\include\DialogueCloseButton.h"
#include "DialogueBox.h"

DialogueCloseButton::DialogueCloseButton(State* t_state,DialogueBox* t_parentBox):
	Button(t_state,
		sf::Vector2f(t_parentBox->getPosition().x + t_parentBox->getSize().x - 20, t_parentBox->getPosition().y),
		sf::Vector2f(20,20)),
	m_parentBox(t_parentBox)
{
}

DialogueCloseButton::~DialogueCloseButton()
{
}

void DialogueCloseButton::update()
{
	Button::update();
}

void DialogueCloseButton::handleEvents(sf::Event& t_event)
{
	Button::handleEvents(t_event);
}

void DialogueCloseButton::draw(sf::RenderWindow& t_window)
{
	Button::draw(t_window);
}

void DialogueCloseButton::setPosition(sf::Vector2f t_pos)
{
	m_body.setPosition(t_pos);
}

void DialogueCloseButton::m_initActive()
{
	m_parentBox->kill();
}
