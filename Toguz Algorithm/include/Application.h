#pragma once

#ifndef APPLICATION_H
#define APPLICATION_H

#include <SFML/Graphics.hpp>
#include "StateManager.h"
#include "MenuState.h"
#include "GameState.h"

class MenuState;

class Application
{
private:
	bool m_isRunning;
	sf::Uint32 m_updateRate;


public:
	static Application* g_app;

	StateManager stateManager;

	const sf::Vector2i WINDOW_SIZE;
	sf::RenderWindow window;
	
	sf::View view;




	Application();
	~Application();

	void run();

	void appLoop();

	void processInput(State*);

	void quit();

	void setUpdateRate(double updateRate);

	double getUpdateRate();

	void updateAspectRatio();

private:
	Application(const Application&);
	Application& operator=(const Application&);
};

#endif // !APPLICATION_H
