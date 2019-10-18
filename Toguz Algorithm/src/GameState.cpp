#include "GameState.h"

GameState::GameState(Application* t_app):
	State(*t_app, "res/wood.jpg"),
	menuButton(new StateButton(this, sf::Vector2f(1920 - 300, 1080 - 200), sf::Vector2f(200,100),"Menu",CHC_goMenu))
{
	
}

GameState::~GameState()
{
}

void GameState::draw(sf::RenderWindow& t_window)
{
	t_window.draw(m_backgroundSprite);
	menuButton->draw(t_window);
}

void GameState::handleEvents(sf::Event& t_event)
{
	menuButton->handleEvents(t_event);
}

void GameState::update()
{
	menuButton->update();
}

void GameState::init()
{
}
