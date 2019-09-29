#include "State.h"

State::State(Application& t_app):
	m_app(t_app)
{
	font.loadFromFile("res/comic.ttf");
}

State::~State()
{
}

Application& State::getApp()
{
	return m_app;
}
