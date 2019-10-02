#include "StateManager.h"

StateManager::StateManager(Application* t_app):
	m_app(*t_app)
{
}

StateManager::~StateManager()
{
}

void StateManager::addState(State* t_newState, bool t_isReplaced)
{
	if (!m_stateStack.empty())
	{
		if (t_isReplaced)
		{
			delete m_stateStack.back();
			m_stateStack.pop_back();
		}
		else
		{
			m_stateStack.back()->pause();
		}
	}
	m_stateStack.push_back(t_newState);
	m_stateStack.back()->init();

}

void StateManager::removeState()
{
}

State* StateManager::getActiveState()
{
	return m_stateStack.back();
}
