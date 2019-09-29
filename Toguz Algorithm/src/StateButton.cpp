#include "StateButton.h"

StateButton::StateButton(State* t_parentState, sf::Vector2f t_position, sf::Vector2f t_size, std::string t_string, ButtonChoice t_choice):
	Button(t_parentState,t_position,t_size,t_string), m_choiceMade(t_choice)
{

}

StateButton::~StateButton()
{
}
