#include "State.h"
#include "GameObject.h"
#include "ObjectManager.h"
#include "Application.h"

State::State(Application& t_app, std::string t_backgroundTexturePath):
	m_app(t_app)
{
	m_objectManager = new ObjectManager(this);
	m_backgroundTexture.loadFromFile(Application::getApp()->getResPath() + t_backgroundTexturePath);
	m_backgroundTexture.setRepeated(true);
	m_backgroundSprite.setTexture(m_backgroundTexture);
	m_backgroundSprite.setTextureRect(sf::IntRect(sf::Vector2i(0, 0), sf::Vector2i(1920, 1080)));

	font.loadFromFile(Application::getApp()->getResPath() + "comic.ttf");
}

State::~State()
{
	delete m_objectManager;
	m_objectManager = nullptr;
}

void State::pause()
{
}

void State::resume()
{
}

void State::destroyGameObject(GameObject* t_destroyed) 
{
	t_destroyed->removeObject();
}

void State::createGameObject(GameObject* t_created)
{
	m_objectManager->createGameObject(t_created);
}

void State::cleanupObjects()
{
	m_objectManager->cleanGameObjects();
}

Application& State::getApp()
{
	return m_app;
}
