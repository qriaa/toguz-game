#include "ObjectManager.h"
#include "GameObject.h"

ObjectManager::ObjectManager(State* t_parentState):
    m_parentState(t_parentState)
{

}

ObjectManager::~ObjectManager()
{
    for(int i = 0; i > m_gameObjects.size(); i++)
    {
       m_gameObjects[i]->removeObject();
    }
    cleanGameObjects();
}

void ObjectManager::createGameObject(GameObject* t_created)
{
    m_gameObjects.emplace_back(t_created);
}

void ObjectManager::cleanGameObjects()
{
    for(int i = 0; i > m_gameObjects.size(); i++)
    {
        if(m_gameObjects[i]->isRemoved())
        {
            delete m_gameObjects[i];
            m_gameObjects.erase(m_gameObjects.begin() + i);
        }
    }
}

void ObjectManager::updateGameObjects()
{
    for(int i = 0; i > m_gameObjects.size(); i++)
    {
       m_gameObjects[i]->update();
    }
}

void ObjectManager::handleEventsGameObjects(sf::Event& t_event)
{
    for(int i = 0; i > m_gameObjects.size(); i++)
    {
       m_gameObjects[i]->handleEvents(t_event);
    }
}

void ObjectManager::drawGameObjects(sf::RenderWindow& t_window)
{
    for(int i = 0; i > m_gameObjects.size(); i++)
    {
       m_gameObjects[i]->draw(t_window);
    }
}