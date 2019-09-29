#pragma once
#ifndef STATE_H
#define STATE_H
#include <SFML/Graphics.hpp>

class Application;

class State
{
protected:
	Application& m_app;

public:
	sf::Font font;

	State(Application& t_app);
	virtual ~State();


	virtual void draw() = 0;

	virtual State* handleEvents(sf::Event&) = 0;

	virtual void update() = 0;

	virtual void entry() = 0;

	Application& getApp();
};

#endif