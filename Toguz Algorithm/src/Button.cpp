#include "Button.h"
#include "Application.h"




Button::Button(State* t_state, sf::Vector2f t_position, sf::Vector2f t_size, std::string t_string):
	ClickRect(t_state, t_position, t_size)
{
	m_btnState = BTN_IDLE;

	m_body.setFillColor(sf::Color::White);
	m_body.setOutlineThickness(-2);
	m_body.setOutlineColor(sf::Color::Black);

	m_soundBuffer.loadFromFile("res/dobrze.ogg");
	m_sound.setBuffer(m_soundBuffer);

	m_text.setFont(m_parentState.font);
	m_text.setFillColor(sf::Color::Red);
	m_text.setString(t_string);
	m_text.setPosition(sf::Vector2f(t_position.x + (t_size.x/2) - m_text.getGlobalBounds().width / 2 , t_position.y + (t_size.y/2) - m_text.getGlobalBounds().height));
}

Button::~Button()
{
}

void Button::update()
{
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
		m_btnState = BTN_HOVER;
		break;
	}
}

void Button::handleEvents(sf::Event& t_event)
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
}

void Button::draw(sf::RenderWindow& t_window)
{
	t_window.draw(m_body);
	t_window.draw(m_text);
}

void Button::m_doOnIdle()
{
	m_body.setFillColor(sf::Color::White);
}

void Button::m_doOnHover()
{
	m_body.setFillColor(sf::Color::Red);
}

void Button::m_doOnActive()
{
	m_body.setFillColor(sf::Color::Yellow);
	m_sound.play();
}