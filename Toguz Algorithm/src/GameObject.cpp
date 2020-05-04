#include "GameObject.h"
#include "State.h"

GameObject::GameObject(State* t_state):
	m_parentState(t_state),
	m_removalMarker(false)
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

void GameObject::removeObject()
{
	m_removalMarker = true;
}

bool GameObject::isRemoved()
{
	return m_removalMarker;
}