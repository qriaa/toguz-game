#pragma once
#ifndef BUTTON_H
#define BUTTON_H

#include "GameObject.h"
#include "State.h"
#include "HasText.h"
#include "NoText.h"
#include <SFML/Audio.hpp>

enum Button_State {BTN_IDLE = 0, BTN_HOVER, BTN_ACTIVE};

class Button : public GameObject
{
protected:
	sf::RectangleShape m_body;

	TextBehavior* m_textBehavior;

	Button_State m_btnState;
	Button_State m_previousState;
	bool m_isMouseClicked;
public:

	Button(State* t_state, sf::Vector2f t_position, sf::Vector2f t_size, std::string t_string);
	Button(State* t_state, sf::Vector2f t_position, sf::Vector2f t_size);

	~Button();

	virtual void update();

	virtual void handleEvents(sf::Event&);

	virtual void draw(sf::RenderWindow&);

	void setText(std::string t_string);

	bool isMouseOver();
protected:
	virtual void m_initIdle();
	virtual void m_initHover();
	virtual void m_initActive();

	virtual void m_doOnIdle();
	virtual void m_doOnHover();
	virtual void m_doOnActive();

};




#endif