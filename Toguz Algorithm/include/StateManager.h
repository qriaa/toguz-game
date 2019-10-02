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

public:
	StateManager(Application* t_app);
	~StateManager();

	void addState(State* t_newState, bool t_isReplaced);
	void removeState();

	State* getActiveState();



private:
	StateManager(const StateManager&);
	StateManager& operator=(const StateManager&);
};






#endif // !STATEMANAGER_H
