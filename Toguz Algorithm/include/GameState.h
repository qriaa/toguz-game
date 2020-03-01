#pragma once

#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "Identifiers.h"
#include "GameObject.h"
#include "State.h"
#include "StateButton.h"
#include "Board.h"
#include "HoleButton.h"
#include "Kazan.h"
#include "TuzSlot.h"
#include "DialogueBox.h"

class GameState : public State
{
private:
	StateButton* m_menuButton;

	Player_Num m_activePlayer;
	bool m_playerChanged;
	bool m_toBeChangedFlag;

	std::vector<HoleButton*> m_holes;
	Kazan* kazanOne;
	Kazan* kazanTwo;
	TuzSlot* tuzOne;
	TuzSlot* tuzTwo;

	bool m_gameFinished;

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

	bool hasPlayerChanged();

	Player_Num getActivePlayer();

private:
	void m_checkHole(int t_hole);
	void m_changeActivePlayer();
	void m_checkForVictory();
	void m_endGame(Player_Num t_victoriousPlayer);
};


#endif