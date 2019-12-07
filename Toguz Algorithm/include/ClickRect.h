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
	ClickRect(State*,sf::Vector2f, sf::Vector2f);
	~ClickRect();

	void draw(sf::RenderWindow& window);

	void handleEvents(sf::Event&);

	void update();

	void init();

	bool isMouseOver();
};

#endif
