#pragma once
#ifndef BUTTON_H
#define BUTTON_H

#include "ClickRect.h"
#include <SFML/Audio.hpp>

enum Button_State {BTN_IDLE = 0, BTN_HOVER, BTN_ACTIVE};

class Button : public ClickRect
{
private:
	sf::SoundBuffer soundBuffer;
	sf::Sound sound;

	Button_State previousState;
	Button_State btnState;

public:
	Button(State*, sf::Vector2f, sf::Vector2f);
	~Button();

	void update();

	State* handleEvents(sf::Event&);

	void draw(sf::RenderWindow&);


};




#endif