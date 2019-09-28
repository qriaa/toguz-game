#include "Application.h"

Application::Application():
	m_updateRate(1000.0f / 20.0f), m_isRunning(true), WINDOW_SIZE(sf::Vector2i(1920,1080))
{
	state = new MenuState(this);
}

Application::~Application()
{
	delete state;
}

void Application::run()
{
	window.create(sf::VideoMode(WINDOW_SIZE.x, WINDOW_SIZE.y), "Toguz Korgool");
	view.reset(sf::FloatRect(sf::Vector2f(0,0), static_cast<sf::Vector2f>(window.getSize())));
	window.setView(view);
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

		window.clear(sf::Color::Black);
		window.setView(view);
		state->draw();

		window.display();
	}

}

void Application::processInput(State* t_state)
{
	sf::Event anEvent;

	while (window.pollEvent(anEvent))
	{
		switch (anEvent.type)
		{
		case sf::Event::Closed:
			quit();
			break;
		case sf::Event::Resized:
			updateAspectRatio();
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

void Application::updateAspectRatio()
{
	sf::Vector2u newSize = window.getSize();
	if (newSize.x / 16 > newSize.y / 9)					//width of the window is too wide
	{
		//we leave newSize.y as it is
		float unit = newSize.y / 9;

		float viewFactor = (unit * 16) / newSize.x;
		float barFactor = (abs(1 - viewFactor)) / 2;

		view.setViewport(sf::FloatRect(barFactor, 0.f, viewFactor, 1.f));
	}
	else if (newSize.x / 16 < newSize.y / 9)			//height of the window is too long
	{
		//we leave newSize.x as it is
		float unit = newSize.x / 16;

		float viewFactor = (unit * 9) / newSize.y;
		float barFactor = (abs(1 - viewFactor)) / 2;

		view.setViewport(sf::FloatRect(0.f,barFactor,1.f,viewFactor));
	}
}
