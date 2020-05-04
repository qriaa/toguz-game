#pragma once
#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <SFML/Graphics.hpp>
#include "Identifiers.h"
class State;

class GameObject
{
protected:
	State* m_parentState;
	bool m_removalMarker;

public:
	GameObject(State* t_state);
	virtual ~GameObject();


	virtual void update();

	virtual void handleEvents(sf::Event&);

	virtual void draw(sf::RenderWindow&);

	virtual void init();

	void removeObject();
	
	bool isRemoved();
};

#endif