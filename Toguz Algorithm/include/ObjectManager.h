#ifndef OBJECTMANAGER_H
#define OBJECTMANAGER_H

#include <vector>
#include <SFML/Graphics.hpp>

class GameObject;
class State;

class ObjectManager
{
private:
    State* m_parentState;
    std::vector<GameObject*> m_gameObjects;

public:
    ObjectManager(State* t_parentState);
    ~ObjectManager();

    void createGameObject(GameObject* t_created);
    void cleanGameObjects();

    void updateGameObjects();
    void handleEventsGameObjects(sf::Event& t_event);
    void drawGameObjects(sf::RenderWindow& t_window);
};

#endif