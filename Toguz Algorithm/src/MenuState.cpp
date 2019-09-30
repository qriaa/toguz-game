#include "MenuState.h"

MenuState::MenuState(Application* t_app):
	State(*t_app, "res/wood.jpg"), m_button(this, sf::Vector2f(100,1080/3), sf::Vector2f(300, 100), "obal mi monument", CHC_goGame)
{
	m_titleText.setFont(font);
	m_titleText.setFillColor(sf::Color::White);
	m_titleText.setCharacterSize(50);
	m_titleText.setString("Kogut Zorgool");
	m_titleText.setPosition(sf::Vector2f(100, 100));
}

MenuState::~MenuState()
{
}

void MenuState::draw(sf::RenderWindow& t_window)
{
	t_window.draw(m_backgroundSprite);
	t_window.draw(m_titleText);
	m_button.draw(t_window);
}

State* MenuState::handleEvents(sf::Event& t_event)
{
	if (m_button.handleEvents(t_event))
	{
		switch (m_button.choiceMade)
		{
		case(CHC_none):
			break;
		case(CHC_quit):
			m_app.quit();
			break;
		case(CHC_goMenu):
			return new MenuState(&m_app);
			break;
		case(CHC_goGame):
			return new GameState(&m_app);
			break;
		}
	}
	return nullptr;
}

void MenuState::update()
{
	m_button.update();
}

void MenuState::entry()
{
}
