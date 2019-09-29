#include "Button.h"
#include "Application.h"

Button::Button(State* t_state, sf::Vector2f t_position, sf::Vector2f t_size, std::string t_string):
	ClickRect(t_state, t_position, t_size), m_isActive(false)
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
	m_isActive = false;
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
		m_isActive = true;
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

bool Button::isActive()
{
	return m_isActive;
}


