#pragma once
#ifndef DIALOGUEBOX_H
#define DIALOGUEBOX_H

#include "Identifiers.h"
#include "DragBar.h"

class DialogueBox
{
private:
	State& m_parentState;

	sf::RectangleShape m_mainBox;
	DragBar m_dragBar;

	bool m_isMouseClicked;

public:
	DialogueBox(State* t_parentState, sf::Vector2f t_pos, sf::Vector2f t_size);
	~DialogueBox();

	void draw(sf::RenderWindow& window);

	void handleEvents(sf::Event&);

	void update();

	void init();
};









#endif // !DIALOGUEBOX_H
