#pragma once
#include <stack>

using namespace std;
class GameState;
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
};

