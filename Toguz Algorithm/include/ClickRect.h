#pragma once

#ifndef CLICKRECT_H
#define CLICKRECT_H
#include <SFML/Graphics.hpp>
#include "State.h"

class ClickRect
{
protected:
	sf::RectangleShape m_body;
	State& m_parentState;


public:
	ClickRect(State*);
	~ClickRect();


	virtual void update() = 0;

	virtual State* handleEvents(sf::Event&) = 0;

	virtual void draw() = 0;

	bool isMouseOver();
};

#endif // !BUTTON_H
