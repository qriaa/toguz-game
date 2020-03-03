#pragma once
#ifndef STATE_H
#define STATE_H
#include <SFML/Graphics.hpp>

class GameObject;
class Application;

class State
{
protected:
	Application& m_app;

	sf::Texture m_backgroundTexture;
	sf::Sprite m_backgroundSprite;

	std::vector<GameObject*> m_gameObjects;
public:
	sf::Font font;

	State(Application& t_app, std::string t_backgroundTexturePath);
	virtual ~State();

	virtual void pause();

	virtual void resume();

	virtual void draw(sf::RenderWindow&) = 0;

	virtual void handleEvents(sf::Event&) = 0;

	virtual void update() = 0;

	virtual void init() = 0;

	/* do NOT use in loops deleting all objects (idk why doesnt that work)
	weird vector and pointer stuff (possibly reallocation) */
	void destroyGameObject(GameObject* t_destroyed);

	void createGameObject(GameObject* t_created);

	Application& getApp();
};

#endif