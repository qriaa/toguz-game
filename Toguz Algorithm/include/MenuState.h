#ifndef MENUSTATE_H
#define MENUSTATE_H

#include <vector>
#include "State.h"
#include "GameState.h"
#include "Application.h"
#include "StateButton.h"

class MenuState : public State
{
private:
	sf::Texture m_texture;
	sf::Sprite m_backgroundSprite;

	sf::Text m_titleText;

	StateButton m_button;


public:

	MenuState(Application* t_app);
	~MenuState();


	void draw();
	
	State* handleEvents(sf::Event&);

	void update();

	void entry();
};









#endif