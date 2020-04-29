#include "Application.h"

Application* Application::m_app = nullptr;

Application::Application():
	stateManager(this),
	m_updateRate(1000.0f / 60.0f),
	m_isRunning(true),
	WINDOW_SIZE(sf::Vector2i(1920,1080))
{
	m_app = this;
}

Application::~Application()
{
}

Application* Application::getApp()
{
	if(m_app == nullptr)
	{
		m_app = new Application();
	}
	return m_app;
}

void Application::run()
{
	window.create(sf::VideoMode(WINDOW_SIZE.x, WINDOW_SIZE.y), "Toguz Korgool");
	view.reset(sf::FloatRect(sf::Vector2f(0,0), static_cast<sf::Vector2f>(window.getSize())));
	window.setView(view);
	m_isRunning = true;

	stateManager.addState(new MenuState(this), false);
	stateManager.updateStates();

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
		processInput(stateManager.getActiveState());
		sf::Int32 updateTime = updateClock.getElapsedTime().asMilliseconds();

		while ((updateTime - updateNext) >= m_updateRate)
		{
			stateManager.getActiveState()->update();

			updateNext += m_updateRate;
		}
		stateManager.updateStates();
		window.clear(sf::Color::Black);
		window.setView(view);
		stateManager.getActiveState()->draw(window);

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
			t_state->handleEvents(anEvent);
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
		float barFactor = (1 - viewFactor) / 2;

		view.setViewport(sf::FloatRect(barFactor, 0.f, viewFactor, 1.f));
	}
	else if (newSize.x / 16 < newSize.y / 9)			//height of the window is too long
	{
		//we leave newSize.x as it is
		float unit = newSize.x / 16;

		float viewFactor = (unit * 9) / newSize.y;
		float barFactor = (1 - viewFactor) / 2;

		view.setViewport(sf::FloatRect(0.f,barFactor,1.f,viewFactor));
	}
}
