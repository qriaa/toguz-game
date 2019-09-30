#pragma once
#ifndef STATEBUTTON_H
#define STATEBUTTON_H

#include "Button.h"

//TODO: state switches and stuff

enum ButtonChoice {CHC_none,CHC_quit,CHC_goMenu, CHC_goGame};

class StateButton : public Button
{
private:

public:
	ButtonChoice choiceMade;
public:
	StateButton(State* t_parentState, sf::Vector2f t_position, sf::Vector2f t_size, std::string t_string, ButtonChoice t_choice);
	~StateButton();

private:

};


#endif // !STATEBUTTON_H
