#pragma once
#ifndef NOTEXT_H
#define NOTEXT_H
#include "TextBehavior.h"

class NoText : public TextBehavior
{
public:
	void init(sf::RectangleShape& t_body, sf::Font& t_font, std::string t_string);
	void setText(sf::RectangleShape& t_body, std::string t_string);
	void setSize(int t_size);
	void setPosition(sf::RectangleShape& t_body, sf::Vector2f t_pos);
	void draw(sf::RenderWindow& t_window);
};


#endif