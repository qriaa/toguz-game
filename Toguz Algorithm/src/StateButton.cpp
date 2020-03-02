#include "StateButton.h"
#include "Application.h"


StateButton::StateButton(State* t_parentState, sf::Vector2f t_position, sf::Vector2f t_size, std::string t_string, ButtonChoice t_choice):
	Button(t_parentState,t_position,t_size,t_string),
	choiceMade(t_choice),
	stateChanged(false)
{

}

StateButton::~StateButton()
{
}

void StateButton::m_initActive()
{
	switch (choiceMade)
	{
	case CHC_none:
		break;
	case CHC_quit:
		Application::getApp()->quit();
		break;
	case CHC_goMenu:
		Application::getApp()->stateManager.addState(new MenuState(Application::getApp()), true);
		stateChanged = true;
		break;
	case CHC_goGame:
		Application::getApp()->stateManager.addState(new GameState(Application::getApp()), true);
		stateChanged = true;
		break;
	}
}

