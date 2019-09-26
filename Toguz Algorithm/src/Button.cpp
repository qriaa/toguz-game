#include "Button.h"
#include "Application.h"

Button::Button(State* t_state, sf::Vector2f t_position, sf::Vector2f t_size):
	ClickRect(t_state, t_position, t_size)
{
	btnState = BTN_IDLE;
	m_body.setFillColor(sf::Color::White);
	m_body.setOutlineThickness(-2);
	m_body.setOutlineColor(sf::Color::Black);
	soundBuffer.loadFromFile("res/dobrze.ogg");
	sound.setBuffer(soundBuffer);
}

Button::~Button()
{
}

void Button::update()
{
	previousState = btnState;

	switch (btnState)
	{
	case BTN_IDLE:
		m_body.setFillColor(sf::Color::White);
		break;

	case BTN_HOVER:
		m_body.setFillColor(sf::Color::Red);
		break;

	case BTN_ACTIVE:
		m_body.setFillColor(sf::Color::Yellow);
		sound.play();
		btnState = BTN_HOVER;
		break;

	}

}

State* Button::handleEvents(sf::Event& t_event)
{
	btnState = BTN_IDLE;

	if (isMouseOver())
	{
		btnState = BTN_HOVER;

		if (t_event.type == sf::Event::MouseButtonPressed)
		{
			if (t_event.mouseButton.button == sf::Mouse::Left)
			{
				btnState = BTN_ACTIVE;
			}
		}
	}


	return nullptr;
}

void Button::draw(sf::RenderWindow& t_window)
{
	t_window.draw(m_body);
}
