#include "StateButton.h"
#include "Application.h"


StateButton::StateButton(State* t_parentState, sf::Vector2f t_position, sf::Vector2f t_size, std::string t_string, ButtonChoice t_choice):
	Button(t_parentState,t_position,t_size,t_string), choiceMade(t_choice)
{

}

StateButton::~StateButton()
{
}

void StateButton::m_doOnActive()
{
	switch (choiceMade)
	{
	case CHC_none:
		break;
	case CHC_quit:
		Application::g_app->quit();
		break;
	case CHC_goMenu:
		Application::g_app->stateManager.addState(new MenuState(Application::g_app), true);
		break;
	case CHC_goGame:
		Application::g_app->stateManager.addState(new GameState(Application::g_app), true);
		break;
	}
}

