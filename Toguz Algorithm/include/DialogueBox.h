#pragma once
#ifndef DIALOGUEBOX_H
#define DIALOGUEBOX_H

#include "Identifiers.h"
#include "Button.h"

class DialogueBox
{
private:
	State& m_parentState;

	sf::RectangleShape m_mainBox;
	ClickRect m_dragBar;



public:
	DialogueBox(State* t_parentState, sf::Vector2f t_pos, sf::Vector2f t_size);
	~DialogueBox();

	void draw(sf::RenderWindow& window);

	void handleEvents(sf::Event&);

	void update();

	void init();

private:
	bool isMouseOver();
};









#endif // !DIALOGUEBOX_H
