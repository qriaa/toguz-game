#pragma once
#ifndef HOLEBUTTON_H
#define HOLEBUTTON_H

#include "Button.h"

class HoleButton : public Button
{
private:

public:

public:
	HoleButton(State* t_parentState, sf::Vector2f t_position, sf::Vector2f t_size, std::string t_string);
private:
	void m_doOnActive();
};


#endif // !HOLEBUTTON_H
