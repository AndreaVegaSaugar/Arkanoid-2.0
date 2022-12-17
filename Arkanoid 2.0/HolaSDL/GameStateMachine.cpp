#include "GameStateMachine.h"
#include "GameState.h"
void GameStateMachine::pushState(GameState* pState) {
	gameStateStack.push(pState);
	current = gameStateStack.top();
}

void GameStateMachine::popState() {
	if (!gameStateStack.empty()) {
		delete gameStateStack.top();
		gameStateStack.pop();
	}
}

void GameStateMachine::changeState(GameState* pState) {
	if (!gameStateStack.empty()) {
		//if (gameStateStack.top()->getStateID() == pState->getStateID()) return;
		//delete gameStateStack.top();
		// en vez de delete hacer lo de la lista de etados por borrar
		gameStateStack.pop();
	}
	pushState(pState);
}