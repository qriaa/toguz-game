#include "Button.h"
#include "Application.h"

Button::Button(State* t_state, sf::Vector2f t_position, sf::Vector2f t_size):
	ClickRect(t_state, t_position, t_size)
{
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
	if (isMouseOver())
		m_body.setFillColor(sf::Color::Red);
	else
		m_body.setFillColor(sf::Color::White);

	if (isClicked)
	{
		sound.play();
		isClicked = false;
	}

}

State* Button::handleEvents(sf::Event& t_event)
{
	if (t_event.MouseButtonPressed && t_event.mouseButton.button == sf::Mouse::Left)      //TO BE FIXED
	{
		if (isMouseOver() && !wasClicked)
		{
			isClicked = true;
			wasClicked = true;
		}
	}

	return nullptr;
}

void Button::draw(sf::RenderWindow& t_window)
{
	t_window.draw(m_body);
}
