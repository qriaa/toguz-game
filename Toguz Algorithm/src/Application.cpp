#include "Application.h"

Application::Application():
	m_updateRate(1000.0f / 20.0f)
{
}

Application::~Application()
{
	delete state;
}

void Application::run()
{
	window.create(sf::VideoMode(1024, 512), "Toguz Korgool");
	m_isRunning = true;

	state->entry();
	appLoop();

	m_isRunning = false;
	window.close();
}

void Application::appLoop()
{
	sf::Clock updateClock;

	updateClock.restart();
	sf::Int32 updateNext = updateClock.getElapsedTime().asMilliseconds();

	while (m_isRunning && window.isOpen())
	{
		processInput(state);
		sf::Int32 updateTime = updateClock.getElapsedTime().asMilliseconds();

		while ((updateTime - updateNext) >= m_updateRate)
		{
			state->update();

			updateNext += m_updateRate;
		}

		window.clear(sf::Color::Color(125, 125, 125));
		state->draw();

		window.display();
	}

}

void Application::processInput(State* t_state)
{
	sf::Event anEvent;

	window.pollEvent(anEvent);

	switch (anEvent.type)
	{
	case sf::Event::Closed:
		quit();
		break;
	case sf::Event::Resized:
		break;
	default:
		State* newState = t_state->handleEvents(anEvent);
		if (newState != NULL)
		{
			delete t_state;
			state = newState;
			state->entry();
		};
		break;
	}
}

void Application::quit()
{
	m_isRunning = false;
}

void Application::setUpdateRate(double t_updateRate)
{
	if (t_updateRate == 0) return;

	m_updateRate = t_updateRate;
}

double Application::getUpdateRate()
{
	return m_updateRate;
}
