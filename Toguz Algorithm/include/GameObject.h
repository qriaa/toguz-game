#pragma once
#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <SFML/Graphics.hpp>
#include "Identifiers.h"
#include "State.h"

class GameObject
{
protected:
	State* m_parentState;

public:
	GameObject(State* t_state);
	~GameObject();


	virtual void update();

	virtual void handleEvents(sf::Event&);

	virtual void draw(sf::RenderWindow&);

	virtual void init();

	void kill();
};

#endif