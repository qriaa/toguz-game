#pragma once
#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <SFML/Graphics.hpp>

class GameObject
{
private:

public:
	GameObject();
	~GameObject();


	virtual void update();

	virtual void handleEvents(sf::Event&);

	virtual void draw(sf::RenderWindow&);

	virtual void init();
};

#endif