#include "State.h"

State::State(Application& t_app):
	m_app(t_app)
{
}

State::~State()
{
}

Application& State::getApp()
{
	return m_app;
}
