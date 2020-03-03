#pragma once
#ifndef HASTEXT_H
#define HASTEXT_H
#include "TextBehavior.h"

class HasText : public TextBehavior
{
private:
	sf::Text m_text;

public:
	HasText(sf::RectangleShape& t_body, sf::Font& t_font, std::string t_string);

	void init(sf::RectangleShape& t_body,sf::Font& t_font, std::string t_string);
	void setText(sf::RectangleShape& t_body, std::string t_string);
	void setSize(int t_size);
	void setPosition(sf::RectangleShape& t_body, sf::Vector2f t_pos);
	void draw(sf::RenderWindow& t_window);

};


#endif // !HASTEXT_H
