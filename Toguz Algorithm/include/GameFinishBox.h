#pragma once
#ifndef GAMEFINISHBOX_H
#define GAMEFINISHBOX_H
#include "DialogueBox.h"
#include "Board.h"
#include "Identifiers.h"
#include "StateButton.h"

class GameFinishBox : public DialogueBox
{
private:
	sf::Text m_text;
	Board* m_boardPtr;
	StateButton* m_stateButtonPtr;
	Player_Num m_victoriousPlayer;
public:
	GameFinishBox(State* t_parentState, Board* t_board, Player_Num t_victoriousPlayer);
	~GameFinishBox();

	void draw(sf::RenderWindow& window);

	void handleEvents(sf::Event&);

	void update();

	void init();

	void setPosition(sf::Vector2f);
};








#endif // !GAMEFINISHBOX_H
