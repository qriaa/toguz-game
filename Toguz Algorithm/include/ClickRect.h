#pragma once

#ifndef CLICKRECT_H
#define CLICKRECT_H
#include <SFML/Graphics.hpp>
#include "State.h"

class Application;

class ClickRect
{
protected:
	sf::RectangleShape m_body;
	State& m_parentState;

public:
	ClickRect(State*, sf::Vector2f, sf::Vector2f);
	~ClickRect();


	virtual void update() = 0;

	virtual void handleEvents(sf::Event&) = 0;

	virtual void draw(sf::RenderWindow&) = 0;

	bool isMouseOver();
};

#endif // !BUTTON_H
