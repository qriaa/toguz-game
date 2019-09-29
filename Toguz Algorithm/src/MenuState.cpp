#include "MenuState.h"

MenuState::MenuState(Application* t_app):
	State(*t_app), m_button(this, sf::Vector2f(100,1080/3), sf::Vector2f(300, 100), "obal mi monument", goGame)
{
	m_texture.loadFromFile("res/wood.jpg");
	m_texture.setRepeated(true);
	m_backgroundSprite.setTexture(m_texture);
	m_backgroundSprite.setTextureRect(sf::IntRect(sf::Vector2i(0,0), sf::Vector2i(1920, 1080)));
	m_titleText.setFont(font);
	m_titleText.setFillColor(sf::Color::White);
	m_titleText.setCharacterSize(50);
	m_titleText.setString("Kogut Zorgool");
	m_titleText.setPosition(sf::Vector2f(100, 100));
}

MenuState::~MenuState()
{
}

void MenuState::draw()
{
	m_app.window.draw(m_backgroundSprite);
	m_app.window.draw(m_titleText);
	m_button.draw(m_app.window);
}

State* MenuState::handleEvents(sf::Event& t_event)
{
	m_button.handleEvents(t_event);
	
	return nullptr;
}

void MenuState::update()
{
	m_button.update();
}

void MenuState::entry()
{
}
