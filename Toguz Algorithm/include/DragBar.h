#pragma once
#ifndef DRAGBAR_H
#define DRAGBAR_H

#include "Button.h"
#include "State.h"
class DialogueBox;

//TODO: FINISH
class DragBar : public Button
{
private:
	DialogueBox& m_parentBox;
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

protected:
	void m_initActive();
	void m_doOnActive();

};












#endif