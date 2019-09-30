#ifndef MENUSTATE_H
#define MENUSTATE_H

#include <vector>
#include "Application.h"
#include "State.h"
#include "GameState.h"
#include "StateButton.h"

class MenuState : public State
{
private:
	sf::Text m_titleText;

	StateButton m_button;
public:

	MenuState(Application* t_app);
	~MenuState();


	void draw(sf::RenderWindow& t_window);
	
	State* handleEvents(sf::Event&);

	void update();

	void entry();
};









#endif