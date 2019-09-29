#pragma once

#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "State.h"


class GameState : public State
{
private:


public:
	GameState(Application* t_app);
	~GameState();

	void draw();

	State* handleEvents(sf::Event&);

	void update();

	void entry();

};


#endif