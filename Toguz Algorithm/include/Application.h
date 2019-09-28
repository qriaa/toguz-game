#pragma once

#ifndef APPLICATION_H
#define APPLICATION_H

#include <SFML/Graphics.hpp>
#include "MenuState.h"
#include "State.h"

class Application
{
private:
	bool m_isRunning;
	sf::Uint32 m_updateRate;


public:
	const sf::Vector2i WINDOW_SIZE;
	sf::RenderWindow window;
	
	sf::View view;




	State* state;

	Application();
	~Application();

	void run();

	void appLoop();

	void processInput(State*);

	void quit();

	void setUpdateRate(double updateRate);

	double getUpdateRate();

	void updateAspectRatio();

};

#endif // !APPLICATION_H
