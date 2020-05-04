#include "State.h"
#include "GameObject.h"

State::State(Application& t_app, std::string t_backgroundTexturePath):
	m_app(t_app)
{
	m_backgroundTexture.loadFromFile(t_backgroundTexturePath);
	m_backgroundTexture.setRepeated(true);
	m_backgroundSprite.setTexture(m_backgroundTexture);
	m_backgroundSprite.setTextureRect(sf::IntRect(sf::Vector2i(0, 0), sf::Vector2i(1920, 1080)));

	font.loadFromFile("Toguz Algorithm/res/comic.ttf");
}

State::~State()
{
	while (!(m_gameObjects.empty()))
	{
		delete m_gameObjects.back();
		m_gameObjects.pop_back();
	}
}

void State::pause()
{
}

void State::resume()
{
}

void State::destroyGameObject(GameObject* t_destroyed) 
{

}

void State::createGameObject(GameObject* t_created)
{
	m_gameObjects.emplace_back(t_created);
}

Application& State::getApp()
{
	return m_app;
}
