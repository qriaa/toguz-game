#pragma once
#ifndef BUTTON_H
#define BUTTON_H

#include "ClickRect.h"
#include <SFML/Audio.hpp>

class Button : public ClickRect
{
private:
	sf::SoundBuffer soundBuffer;
	sf::Sound sound;


public:
	Button(State*, sf::Vector2f, sf::Vector2f);
	~Button();

	void update();

	State* handleEvents(sf::Event&);

	void draw(sf::RenderWindow&);


};




#endif