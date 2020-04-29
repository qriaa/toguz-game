#include "GameObject.h"

GameObject::GameObject(State* t_state):
	m_parentState(t_state)
{
}

GameObject::~GameObject()
{
}

void GameObject::update()
{
}

void GameObject::handleEvents(sf::Event&)
{
}

void GameObject::draw(sf::RenderWindow&)
{
}

void GameObject::init()
{
}

void GameObject::kill()
{
	m_parentState->destroyGameObject(this);
}
