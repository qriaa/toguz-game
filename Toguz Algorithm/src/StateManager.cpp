#include "StateManager.h"

StateManager::StateManager(Application* t_app):
	m_app(*t_app),
	m_stateAdded(false),
	m_stateRemoved(false),
	m_isReplaced(false)
{
}

StateManager::~StateManager()
{
}

void StateManager::addState(State* t_newState, bool t_isReplaced)
{
	m_stateAdded = true;
	m_newState = t_newState;
	m_isReplaced = t_isReplaced;
}

void StateManager::removeState()
{
	m_stateRemoved = true;
}

void StateManager::updateStates()
{
	if (m_stateAdded)
	{
		if (!m_stateStack.empty())
		{
			if (m_isReplaced)
			{
				delete m_stateStack.back();
				m_stateStack.pop_back();
			}
			else
			{
				m_stateStack.back()->pause();
			}
		}
		m_stateStack.push_back(m_newState);
		m_stateStack.back()->init();
		m_stateAdded = false;
		m_isReplaced = false;
	}
	if (m_stateRemoved)
	{
		if (!m_stateStack.empty())
		{
			delete m_stateStack.back();
			m_stateStack.pop_back();
		}
		if (!m_stateStack.empty())
		{
			m_stateStack.back()->resume();
		}
		m_stateRemoved = false;
	}


}

State* StateManager::getActiveState()
{
	return m_stateStack.back();
}
