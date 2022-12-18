#include "GameStateMachine.h"
#include "GameState.h"

GameStateMachine:: ~GameStateMachine() {

}

void GameStateMachine::pushState(GameState* pState) {
	gameStateStack.push(pState);
}

void GameStateMachine::popState() {
	if (!gameStateStack.empty()) {
		delete gameStateStack.top();
		//statesToDelete.push_back(gameStateStack.top());
		gameStateStack.pop();
	}
}

void GameStateMachine::changeState(GameState* pState) {

	if (!gameStateStack.empty()) {
		if (gameStateStack.top()->getStateID() == pState->getStateID()) return;
		delete gameStateStack.top();
		//statesToDelete.push_back(gameStateStack.top());
		// en vez de delete hacer lo de la lista de estados por borrar
		gameStateStack.pop();
	}
	gameStateStack.push(pState);
}
