#include "DialogueBox.h"
#include "Application.h"

DialogueBox::DialogueBox(State* t_parentState,sf::Vector2f t_pos, sf::Vector2f t_size):
	GameObject(t_parentState)
{
	m_mainBox.setPosition(t_pos);
	m_mainBox.setSize(t_size);
	m_mainBox.setOutlineColor(sf::Color::Black);
	m_mainBox.setOutlineThickness(-2);
	m_dragBarPtr = new DragBar(t_parentState, this, sf::Vector2f(960 - (t_size.x / 2), 540 - (t_size.y / 2)), sf::Vector2f(t_size.x - 20, 20));
	createGameObject(m_dragBarPtr);
	m_dialogueClosePtr = new DialogueCloseButton(t_parentState, this);
	createGameObject(m_dialogueClosePtr);
}

DialogueBox::DialogueBox(State* t_parentState, sf::Vector2f t_size):
	GameObject(t_parentState)
{
	m_mainBox.setPosition(sf::Vector2f(960 - (t_size.x / 2),540 - (t_size.y / 2)));
	m_mainBox.setSize(t_size);
	m_mainBox.setOutlineColor(sf::Color::Black);
	m_mainBox.setOutlineThickness(-2);
	m_dragBarPtr = new DragBar(t_parentState, this, sf::Vector2f(960 - (t_size.x / 2), 540 - (t_size.y / 2)), sf::Vector2f(t_size.x - 20, 20));
	createGameObject(m_dragBarPtr);
	m_dialogueClosePtr = new DialogueCloseButton(t_parentState, this);
	createGameObject(m_dialogueClosePtr);
}

DialogueBox::~DialogueBox()
{
	while (!(m_gameObjects.empty()))
	{
		delete m_gameObjects.back();
		m_gameObjects.pop_back();
	}
}

void DialogueBox::createGameObject(GameObject* t_created)
{
	m_gameObjects.emplace_back(t_created);
}

void DialogueBox::destroyGameObject(GameObject* t_destroyed)
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		if (m_gameObjects[i] == t_destroyed)
		{
			delete m_gameObjects[i];
			m_gameObjects.erase(m_gameObjects.begin() + i);
			return;
		}
	}
}

void DialogueBox::draw(sf::RenderWindow& window)
{
	window.draw(m_mainBox);
	for (GameObject* object : m_gameObjects)
	{
		object->draw(window);
	}
}

void DialogueBox::handleEvents(sf::Event& t_event)
{
	for (GameObject* object : m_gameObjects)
	{
		object->handleEvents(t_event);
	}
}

void DialogueBox::update()
{
	for (GameObject* object : m_gameObjects)
	{
		object->update();
	}
}

void DialogueBox::init()
{
}

void DialogueBox::setPosition(sf::Vector2f t_pos)
{
	//can be fixed with observer
	//relative to main window
	m_mainBox.setPosition(t_pos);
	m_dragBarPtr->setPosition(t_pos);
	m_dialogueClosePtr->setPosition(sf::Vector2f(t_pos.x + m_mainBox.getSize().x-20, t_pos.y));
}

sf::Vector2f DialogueBox::getPosition()
{
	return m_mainBox.getPosition();
}

sf::Vector2f DialogueBox::getSize()
{
	return m_mainBox.getSize();
}
