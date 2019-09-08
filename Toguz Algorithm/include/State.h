#pragma once
#ifndef STATE_H
#define STATE_H
#include <SFML/Graphics.hpp>


class Application;

class State
{
protected:
	Application& mApp;

public:

	State(Application& mApp);
	virtual ~State();

	virtual void draw() = 0;

	virtual State* handleEvents(sf::Event&) = 0;

	virtual void update() = 0;

	virtual void entry() = 0;

};



#endif