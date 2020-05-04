#pragma once
#ifndef DIALOGUECLOSEBUTTON_H
#define DIALOGUECLOSEBUTTON_H
#include "Button.h"

class DialogueBox;


class DialogueCloseButton : public Button
{
private:
	DialogueBox* m_parentBox;

public:
	DialogueCloseButton(State* t_state, DialogueBox* t_parentBox);
	~DialogueCloseButton();

	void update();

	void handleEvents(sf::Event&);

	void draw(sf::RenderWindow&);

	void setPosition(sf::Vector2f);

protected:
	void m_initActive();

};



#endif