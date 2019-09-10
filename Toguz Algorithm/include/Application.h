#ifndef APPLICATION_H
#define APPLICATION_H

#include <SFML/Graphics.hpp>
#include "State.h"
#include "MenuState.h"

class Application
{
private:
	bool m_isRunning;
	sf::Uint32 m_updateRate;


public:
	sf::RenderWindow window;

	State* state;

	Application();
	~Application();

	void run();

	void appLoop();

	void processInput(State*);

	void quit();

	void setUpdateRate(double updateRate);

	double getUpdateRate();

};









#endif // !APPLICATION_H
