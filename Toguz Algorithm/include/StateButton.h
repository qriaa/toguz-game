#pragma once
#ifndef STATEBUTTON_H
#define STATEBUTTON_H

#include "Button.h"

//TODO: state switches and stuff

enum ButtonChoice {goMenu = 0, goGame};

class StateButton : public Button
{
private:

public:
	ButtonChoice m_choiceMade;

public:
	StateButton(State* t_parentState, sf::Vector2f t_position, sf::Vector2f t_size, std::string t_string, ButtonChoice t_choice);
	~StateButton();

private:
	


};


#endif // !STATEBUTTON_H
