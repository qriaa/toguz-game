#pragma once
#ifndef DIALOGUEBOX_H
#define DIALOGUEBOX_H

#include "GameObject.h"
#include "Identifiers.h"
#include "DragBar.h"
#include "DialogueCloseButton.h"

class DialogueBox : public GameObject
{
protected:
	sf::RectangleShape m_mainBox;
	std::vector<GameObject*> m_gameObjects;
	DragBar* m_dragBarPtr = nullptr;
	DialogueCloseButton* m_dialogueClosePtr = nullptr;
public:
	DialogueBox(State* t_parentState, sf::Vector2f t_pos, sf::Vector2f t_size);
	DialogueBox(State* t_parentState, sf::Vector2f t_size);
	virtual ~DialogueBox();

	void createGameObject(GameObject*);

	void destroyGameObject(GameObject*);

	virtual void draw(sf::RenderWindow& window);

	virtual void handleEvents(sf::Event&);

	virtual void update();

	virtual void init();

	virtual void setPosition(sf::Vector2f);

	sf::Vector2f getPosition();

	sf::Vector2f getSize();
};









#endif // !DIALOGUEBOX_H
