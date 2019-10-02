#pragma once
#ifndef STATE_H
#define STATE_H
#include <SFML/Graphics.hpp>

class Application;

class State
{
protected:
	Application& m_app;

	sf::Texture m_backgroundTexture;
	sf::Sprite m_backgroundSprite;
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

	Application& getApp();
};

#endif