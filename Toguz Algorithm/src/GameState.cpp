#include "GameState.h"

GameState::GameState(Application* t_app):
	State(*t_app, "res/wood.jpg")
{

}

GameState::~GameState()
{
}

void GameState::draw(sf::RenderWindow& t_window)
{
	t_window.draw(m_backgroundSprite);
}

State* GameState::handleEvents(sf::Event&)
{
	return nullptr;
}

void GameState::update()
{
}

void GameState::entry()
{
}
