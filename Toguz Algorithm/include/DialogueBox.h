#pragma once
#ifndef DIALOGUEBOX_H
#define DIALOGUEBOX_H

#include "GameObject.h"
#include "Identifiers.h"
#include "DragBar.h"

class DialogueBox : public GameObject
{
private:
	State& m_parentState;

	sf::RectangleShape m_mainBox;
	DragBar m_dragBar;

public:
	DialogueBox(State* t_parentState, sf::Vector2f t_pos, sf::Vector2f t_size);
	DialogueBox(State* t_parentState, sf::Vector2f t_size);
	~DialogueBox();

	void draw(sf::RenderWindow& window);

	void handleEvents(sf::Event&);

	void update();

	void init();

	void setPosition(sf::Vector2f);

	friend class DragBar;
};









#endif // !DIALOGUEBOX_H
