#ifndef MENUSTATE_H
#define MENUSTATE_H

#include <vector>
#include "State.h"
#include "StateButton.h"

class Application;

class MenuState : public State
{
private:
	sf::Text m_titleText;

	StateButton* m_gameButton;
	StateButton* m_quitButton;
public:

	MenuState(Application* t_app);
	~MenuState();


	void draw(sf::RenderWindow& t_window);
	
	void handleEvents(sf::Event&);

	void update();

	void init();
};









#endif