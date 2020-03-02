#include "HasText.h"

HasText::HasText(sf::RectangleShape& t_body, sf::Font& t_font, std::string t_string)
{
	init(t_body, t_font, t_string);
}

void HasText::init(sf::RectangleShape& t_body,sf::Font& t_font, std::string t_string)
{
	m_text.setFont(t_font);
	m_text.setFillColor(sf::Color::Red);
	this->setText(t_body,t_string);
}

void HasText::setText(sf::RectangleShape& t_body, std::string t_string)
{
	m_text.setString(t_string);
	m_text.setPosition(sf::Vector2f(t_body.getPosition().x + (t_body.getSize().x / 2) - m_text.getGlobalBounds().width / 2, t_body.getPosition().y + (t_body.getSize().y / 2) - m_text.getGlobalBounds().height));
}

void HasText::setSize(int t_size)
{
	m_text.setCharacterSize(t_size);
}

void HasText::draw(sf::RenderWindow& t_window)
{
	t_window.draw(m_text);
}
