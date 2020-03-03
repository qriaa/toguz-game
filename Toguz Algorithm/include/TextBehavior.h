#pragma once
#ifndef TEXTBEHAVIOR_H
#define TEXTBEHAVIOR_H
#include <iostream>
#include "SFML/Graphics.hpp"

class TextBehavior
{
public:
	virtual void init(sf::RectangleShape& t_body, sf::Font& t_font, std::string t_string) = 0;
	virtual void setText(sf::RectangleShape& t_body, std::string t_string) = 0;
	virtual void setSize(int t_size) = 0;
	virtual void setPosition(sf::RectangleShape& t_body, sf::Vector2f t_pos) = 0;
	virtual void draw(sf::RenderWindow& t_window) = 0;
};

#endif