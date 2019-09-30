#include "State.h"

State::State(Application& t_app, std::string t_backgroundTexturePath):
	m_app(t_app)
{
	m_backgroundTexture.loadFromFile(t_backgroundTexturePath);
	m_backgroundTexture.setRepeated(true);
	m_backgroundSprite.setTexture(m_backgroundTexture);
	m_backgroundSprite.setTextureRect(sf::IntRect(sf::Vector2i(0, 0), sf::Vector2i(1920, 1080)));

	font.loadFromFile("res/comic.ttf");
}

State::~State()
{
}

Application& State::getApp()
{
	return m_app;
}
