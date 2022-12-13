#pragma once
#include "GameState.h"
#include "MainMenuState.h"
#include <stack>

using namespace std;
class GameStateMachine
{
private:
	stack<GameState*> gameStateStack;

public: 
	GameState* currentState() {
		if (!gameStateStack.empty()) return gameStateStack.top();
		else return nullptr;
	}
	void pushState(GameState* pState);
	void changeState(GameState* pState);
	void popState();

	GameStateMachine();
};

