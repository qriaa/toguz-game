#pragma once
#ifndef DIALOGUEBOX_H
#define DIALOGUEBOX_H

#include "GameObject.h"
#include "Identifiers.h"
#include "DragBar.h"
#include "DialogueCloseButton.h"

class DialogueBox : public GameObject
{
private:
	sf::RectangleShape m_mainBox;
	std::vector<GameObject*> m_gameObjects;
	DragBar* m_dragBarPtr = nullptr;
	DialogueCloseButton* m_dialogueClosePtr = nullptr;
public:
	DialogueBox(State* t_parentState, sf::Vector2f t_pos, sf::Vector2f t_size);
	DialogueBox(State* t_parentState, sf::Vector2f t_size);
	~DialogueBox();

	void createGameObject(GameObject*);

	void destroyGameObject(GameObject*);

	void draw(sf::RenderWindow& window);

	void handleEvents(sf::Event&);

	void update();

	void init();

	void setPosition(sf::Vector2f);

	sf::Vector2f getPosition();

	sf::Vector2f getSize();

	friend class DragBar;
};









#endif // !DIALOGUEBOX_H
