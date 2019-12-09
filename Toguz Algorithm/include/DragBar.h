#pragma once
#ifndef DRAGBAR_H
#define DRAGBAR_H

#include "ClickRect.h"
#include "State.h"
class DialogueBox;

class DragBar : public ClickRect
{
private:
	DialogueBox& m_parentBox;
	bool m_isMouseClicked;
	sf::Vector2f m_mouseRelativePos;
	bool m_hasRelativePos;

public:
	DragBar(State* t_parentState, DialogueBox* t_parentBox, sf::Vector2f t_position, sf::Vector2f t_size);
	~DragBar();

	void update();

	void handleEvents(sf::Event&);

	void draw(sf::RenderWindow&);

	void init();

	void setPosition(sf::Vector2f);

};












#endif