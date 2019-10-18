#pragma once
#ifndef STATEMANAGER_H
#define STATEMANAGER_H

#include "State.h"

class Application;

class StateManager
{
private:
	Application& m_app;

	std::vector<State*> m_stateStack;
	State* m_newState;
	bool m_stateAdded;
	bool m_stateRemoved;
	bool m_isReplaced;

public:
	StateManager(Application* t_app);
	~StateManager();

	void addState(State* t_newState, bool t_isReplaced);
	void removeState();
	void updateStates();

	State* getActiveState();



private:
	StateManager(const StateManager&);
	StateManager& operator=(const StateManager&);
};






#endif // !STATEMANAGER_H
