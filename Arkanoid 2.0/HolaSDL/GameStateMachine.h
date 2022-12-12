#pragma once
#include "GameState.h"
#include <stack>

using namespace std;
class GameStateMachine
{
private:
	stack<GameState*> gameStateStack;

public: 
	void currentState();
	void pushState();
	void changeState();
	void popState();

	/*void update();
	void render();*/
};

