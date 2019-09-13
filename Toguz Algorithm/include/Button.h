#pragma once

#ifndef BUTTON_H
#define BUTTON_H
#include <SFML/Graphics.hpp>
#include "State.h"

class Button
{
protected:
	sf::RectangleShape m_body;
	State& m_parentState;

public:
	Button(State*);
	~Button();


	virtual void update();

	virtual State* handleEvents(sf::Event&);

	virtual void draw();

	bool isMouseOver();
};

#endif // !BUTTON_H
