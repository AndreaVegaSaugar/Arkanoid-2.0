#include "GameStateMachine.h"
#include "GameState.h"
void GameStateMachine::pushState(GameState* pState) {
	gameStateStack.push(pState);
	current = gameStateStack.top();
}

void GameStateMachine::popState() {
	if (!gameStateStack.empty()) {
		//delete gameStateStack.top();
		statesToDelete.push_back(gameStateStack.top());
		gameStateStack.pop();
	}
}

void GameStateMachine::changeState(GameState* pState) {
	current = pState;
	if (!gameStateStack.empty()) {
		//if (gameStateStack.top()->getStateID() == pState->getStateID()) return;
		//delete gameStateStack.top();
		statesToDelete.push_back(gameStateStack.top());
		// en vez de delete hacer lo de la lista de estados por borrar
		gameStateStack.pop();
	}
	pushState(pState);
}

void GameStateMachine::deleteStates() {
	//delete statesToDelete;
	for (auto it = statesToDelete.begin(); it != statesToDelete.end(); ++it) {
		delete (*it);
	}
}
void GameStateMachine::save() {

}