#pragma once

#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "State.h"
#include "StateButton.h"
#include "HoleButton.h"
#include "Board.h"

enum Player_Num { PLR_ONE, PLR_TWO };

class GameState : public State
{
private:
	StateButton* m_menuButton;

	Player_Num m_activePlayer;

	std::vector<HoleButton*> m_holes;

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
};


#endif