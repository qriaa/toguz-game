#include "Kazan.h"
#include "Application.h"

Kazan::Kazan(GameState* t_parentGame, sf::Vector2f t_position, sf::Vector2f t_size, Player_Num t_whoseKazan) :
	m_parentGame(*t_parentGame),
	m_whoseKazan(t_whoseKazan)
{
	m_body.setPosition(t_position);
	m_body.setSize(t_size);

	m_body.setFillColor(sf::Color::White);
	m_body.setOutlineThickness(-2);
	m_body.setOutlineColor(sf::Color::Black);

	m_text.setFont(m_parentGame.font);
	m_text.setFillColor(sf::Color::Red);

	switch (t_whoseKazan)
	{
	case PLR_ONE:
		m_text.setString(std::to_string(m_parentGame.m_board.kazanOne));
		break;
	case PLR_TWO:
		m_text.setString(std::to_string(m_parentGame.m_board.kazanTwo));
		break;
	}
	m_text.setPosition(sf::Vector2f(t_position.x + (t_size.x / 2) - m_text.getGlobalBounds().width / 2, t_position.y + (t_size.y / 2) - m_text.getGlobalBounds().height));
}

Kazan::~Kazan()
{
}

void Kazan::update()
{
	switch (m_whoseKazan)
	{
	case PLR_ONE:
		m_text.setString(std::to_string(m_parentGame.m_board.kazanOne));
		break;
	case PLR_TWO:
		m_text.setString(std::to_string(m_parentGame.m_board.kazanTwo));
		break;
	}
	m_text.setPosition(sf::Vector2f(m_body.getPosition().x + (m_body.getSize().x / 2) - m_text.getGlobalBounds().width / 2, m_body.getPosition().y + (m_body.getSize().y / 2) - m_text.getGlobalBounds().height));
}

void Kazan::handleEvents(sf::Event& t_event)
{

}

void Kazan::draw(sf::RenderWindow& t_window)
{
	t_window.draw(m_body);
	t_window.draw(m_text);
}
