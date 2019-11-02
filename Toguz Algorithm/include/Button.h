#pragma once
#ifndef BUTTON_H
#define BUTTON_H

#include "ClickRect.h"
#include <SFML/Audio.hpp>

enum Button_State {BTN_IDLE = 0, BTN_HOVER, BTN_ACTIVE};

class Button : public ClickRect
{
protected:
	sf::Text m_text;

	Button_State m_btnState;
	bool m_isMouseClicked;
public:

	Button(State* t_state, sf::Vector2f t_position, sf::Vector2f t_size, std::string t_string);
	~Button();

	virtual void update();

	virtual void handleEvents(sf::Event&);

	virtual void draw(sf::RenderWindow&);

	void setText(std::string t_string);

protected:

	virtual void m_doOnIdle();
	virtual void m_doOnHover();
	virtual void m_doOnActive();

};




#endif