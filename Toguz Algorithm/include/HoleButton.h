#pragma once
#ifndef HOLEBUTTON_H
#define HOLEBUTTON_H

#include "Button.h"
class GameState;

class HoleButton : public Button
{
private:
	GameState& m_parentGame;
	int m_holeNumber;

public:
	HoleButton(GameState* t_parentGame, sf::Vector2f t_position, sf::Vector2f t_size, int t_holeNumber);

	void update();

	void draw(sf::RenderWindow&);

	void setHoleNumber(int t_number);
private:
	void m_doOnActive();
};


#endif // !HOLEBUTTON_H
