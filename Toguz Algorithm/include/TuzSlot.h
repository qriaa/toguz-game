#pragma once

#ifndef TUZSLOT_H
#define TUZSLOT_H

#include <SFML/Graphics.hpp>
#include "GameObject.h"
#include "Identifiers.h"


class TuzSlot : public GameObject
{
private:
	GameState& m_parentGame;
	sf::RectangleShape m_body;
	Player_Num m_whoseTuzSlot;
	
	bool hasTuz;
public:
	TuzSlot(GameState* t_parentGame, sf::Vector2f t_position, sf::Vector2f t_size, Player_Num t_whoseTuzSlot);
	~TuzSlot();

	void update();

	void handleEvents(sf::Event&);

	void draw(sf::RenderWindow&);

	void changePlayer();
};







#endif // !TUZSLOT_H
