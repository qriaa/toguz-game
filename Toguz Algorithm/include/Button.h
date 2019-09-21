#pragma once
#ifndef BUTTON_H
#define BUTTON_H

#include "ClickRect.h"

class Button : public ClickRect
{
private:



public:
	Button(State*);
	~Button();

	void update();

	State* handleEvents(sf::Event&);

	void draw();


};




#endif