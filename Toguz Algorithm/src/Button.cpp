#include "Button.h"
#include "Application.h"

Button::Button(State* t_state, sf::Vector2f t_position, sf::Vector2f t_size):
	ClickRect(t_state, t_position, t_size)
{
	m_btnState = BTN_IDLE;
	m_body.setFillColor(sf::Color::White);
	m_body.setOutlineThickness(-2);
	m_body.setOutlineColor(sf::Color::Black);
	m_soundBuffer.loadFromFile("res/dobrze.ogg");
	m_sound.setBuffer(m_soundBuffer);
}

Button::~Button()
{
}

void Button::update()
{
	m_previousState = m_btnState;

	switch (m_btnState)
	{
	case BTN_IDLE:
		m_body.setFillColor(sf::Color::White);
		break;

	case BTN_HOVER:
		m_body.setFillColor(sf::Color::Red);
		break;

	case BTN_ACTIVE:
		m_body.setFillColor(sf::Color::Yellow);
		m_sound.play();
		m_btnState = BTN_HOVER;
		break;

	}

}

State* Button::handleEvents(sf::Event& t_event)
{
	m_btnState = BTN_IDLE;

	if (isMouseOver())
	{
		m_btnState = BTN_HOVER;

		if (t_event.type == sf::Event::MouseButtonPressed)
		{
			if (t_event.mouseButton.button == sf::Mouse::Left)
			{
				m_btnState = BTN_ACTIVE;
			}
		}
	}


	return nullptr;
}

void Button::draw(sf::RenderWindow& t_window)
{
	t_window.draw(m_body);
}
