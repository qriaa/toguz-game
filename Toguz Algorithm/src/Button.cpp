#include "Button.h"
#include "Application.h"




Button::Button(State* t_state, sf::Vector2f t_position, sf::Vector2f t_size, std::string t_string):
	GameObject(t_state),
	m_isMouseClicked(false)
{
	m_parentState = t_state;
	m_btnState = BTN_IDLE;
	m_previousState = BTN_IDLE;

	m_body.setPosition(t_position);
	m_body.setSize(t_size);
	m_body.setFillColor(sf::Color::White);
	m_body.setOutlineThickness(-2);
	m_body.setOutlineColor(sf::Color::Black);

	m_textBehavior = new HasText(m_body,m_parentState->font,t_string);
}

Button::Button(State* t_state, sf::Vector2f t_position, sf::Vector2f t_size):
	GameObject(t_state),
	m_isMouseClicked(false)
{
	m_parentState = t_state;
	m_btnState = BTN_IDLE;
	m_previousState = BTN_IDLE;

	m_body.setPosition(t_position);
	m_body.setSize(t_size);
	m_body.setFillColor(sf::Color::White);
	m_body.setOutlineThickness(-2);
	m_body.setOutlineColor(sf::Color::Black);

	m_textBehavior = new NoText();
}

Button::~Button()
{
}

void Button::update()
{
	m_btnState = BTN_IDLE;

	if (isMouseOver())
	{
		m_btnState = BTN_HOVER;

		if (m_isMouseClicked)
		{
			m_btnState = BTN_ACTIVE;
		}
	}

	if (m_previousState != m_btnState)
	{
		switch (m_btnState)
		{
		case BTN_IDLE:
			m_initIdle();
			break;

		case BTN_HOVER:
			m_initHover();
			break;

		case BTN_ACTIVE:
			m_initActive();
			break;
		}
	}

	switch (m_btnState)
	{
	case BTN_IDLE:
		m_doOnIdle();
		break;

	case BTN_HOVER:
		m_doOnHover();
		break;

	case BTN_ACTIVE:
		m_doOnActive();
		break;
	}

	m_previousState = m_btnState;
}

void Button::handleEvents(sf::Event& t_event)
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

void Button::draw(sf::RenderWindow& t_window)
{
	t_window.draw(m_body);
	m_textBehavior->draw(t_window);
}

void Button::setText(std::string t_string)
{
	m_textBehavior->setText(m_body, t_string);
}

bool Button::isMouseOver()
{
	sf::Vector2i initPos = sf::Mouse::getPosition(m_parentState->getApp().window);
	sf::Vector2f mousePos = m_parentState->getApp().window.mapPixelToCoords(initPos);
	sf::Vector2f bodyPos = m_body.getPosition();
	sf::Vector2f bodySize = m_body.getSize();

	if (mousePos.x >= bodyPos.x && mousePos.x <= bodyPos.x + bodySize.x &&		//mouse is inbetween the left and the right edge
		mousePos.y >= bodyPos.y && mousePos.y <= bodyPos.y + bodySize.y)		//mouse is inbetween the top and bottom edge
		return true;
	else return false;
}

void Button::m_initIdle()
{
	m_body.setFillColor(sf::Color::White);
}

void Button::m_initHover()
{
	m_body.setFillColor(sf::Color::Red);
}

void Button::m_initActive()
{
	m_body.setFillColor(sf::Color::Yellow);
}

void Button::m_doOnIdle()
{
}

void Button::m_doOnHover()
{
}

void Button::m_doOnActive()
{
}