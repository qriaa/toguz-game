#pragma once
#ifndef BUTTON_H
#define BUTTON_H

#include "ClickRect.h"
#include <SFML/Audio.hpp>

enum Button_State {BTN_IDLE = 0, BTN_HOVER, BTN_ACTIVE};

class Button : public ClickRect
{
private:
	sf::SoundBuffer m_soundBuffer;
	sf::Sound m_sound;

	sf::Text m_text;

	Button_State m_btnState;
	bool m_isActive;
public:

	Button(State*, sf::Vector2f, sf::Vector2f, std::string);
	~Button();

	void update();

	void handleEvents(sf::Event&);

	void draw(sf::RenderWindow&);

	bool isActive();
};




#endif