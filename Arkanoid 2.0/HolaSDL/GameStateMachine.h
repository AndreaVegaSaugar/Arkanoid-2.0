#pragma once
#include <stack>
#include <list>

using namespace std;

class GameState;
class GameStateMachine
{
private:
	stack<GameState*> gameStateStack;
	list<GameState*> statesToDelete;
public: 
	GameState* currentState() {
		if (!gameStateStack.empty()) return gameStateStack.top();
		else return nullptr;
	}
	void pushState(GameState* pState);
	void changeState(GameState* pState);
	void popState();

	//void deleteStates();

};

