#ifndef MENUSTATE_H
#define MENUSTATE_H

#include <vector>
#include "State.h"
#include "Application.h"
#include "Button.h"

class MenuState : public State
{
private:
	sf::Text m_titleText;
	sf::Font m_font;

	Button button;

public:
	MenuState(Application* t_app);
	~MenuState();


	void draw();
	
	State* handleEvents(sf::Event&);

	void update();

	void entry();
};









#endif