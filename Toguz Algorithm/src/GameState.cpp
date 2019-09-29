#include "GameState.h"




GameState::GameState(Application* t_app):
	State(*t_app)
{

}

GameState::~GameState()
{
}

void GameState::draw()
{
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
