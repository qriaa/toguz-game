#pragma once
#ifndef STATEBUTTON_H
#define STATEBUTTON_H

#include "Identifiers.h"
#include "Button.h"


class StateButton : public Button
{
private:

public:
	ButtonChoice choiceMade;
	bool stateChanged;
public:
	StateButton(State* t_parentState, sf::Vector2f t_position, sf::Vector2f t_size, std::string t_string, ButtonChoice t_choice);
	~StateButton();

private:
	void m_initActive();
};


#endif // !STATEBUTTON_H
