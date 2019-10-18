#pragma once

#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "State.h"
#include "StateButton.h"
#include "HoleButton.h"
#include "Board.h"

class GameState : public State
{
	friend class HoleButton;
private:
	Board board;





	StateButton* menuButton;
public:
	GameState(Application* t_app);
	~GameState();

	void draw(sf::RenderWindow& t_window);

	void handleEvents(sf::Event&);

	void update();

	void init();

};


#endif