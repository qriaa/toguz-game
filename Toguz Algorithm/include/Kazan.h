#pragma once

#ifndef KAZAN_H
#define KAZAN_H
#include <SFML/Graphics.hpp>

#include "GameObject.h"
#include "Identifiers.h"

class Kazan : public GameObject
{
private:
	GameState& m_parentGame;

	sf::RectangleShape m_body;

	sf::Text m_text;

	Player_Num m_whoseKazan;
public:
	Kazan(GameState* t_parentGame, sf::Vector2f t_position, sf::Vector2f t_size, Player_Num t_whoseKazan);
	~Kazan();

	void update();

	void handleEvents(sf::Event&);

	void draw(sf::RenderWindow&);

	void changePlayer();
};




#endif