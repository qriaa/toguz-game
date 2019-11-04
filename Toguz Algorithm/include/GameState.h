#pragma once

#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "Identifiers.h"
#include "State.h"
#include "StateButton.h"
#include "Board.h"
#include "HoleButton.h"
#include "Kazan.h"
#include "TuzSlot.h"

class GameState : public State
{
private:
	StateButton* m_menuButton;

	Player_Num m_activePlayer;

	std::vector<HoleButton*> m_holes;
	Kazan* kazanOne;
	Kazan* kazanTwo;
	TuzSlot* tuzOne;
	TuzSlot* tuzTwo;

public:
	Board m_board;
public:
	GameState(Application* t_app);
	~GameState();

	void draw(sf::RenderWindow& t_window);

	void handleEvents(sf::Event&);

	void update();

	void init();

	bool makeMove(int t_hole);

private:
	void m_checkHole(int t_hole);
	void m_changeActivePlayer();
};


#endif