#pragma once
#ifndef DRAGBAR_H
#define DRAGBAR_H

#include "ClickRect.h"
class DialogueBox;

class DragBar : public ClickRect
{
private:
	DialogueBox& m_parentBox;

public:
	DragBar(State* t_parentState, DialogueBox* t_parentBox, sf::Vector2f t_position, sf::Vector2f t_size);
	~DragBar();

	void update();

	void handleEvents(sf::Event&);

	void draw(sf::RenderWindow&);

	void init();

};












#endif