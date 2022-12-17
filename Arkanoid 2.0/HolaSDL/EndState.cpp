#include "EndState.h"
EndState::EndState(Game* game, char c) : MenuGameState(game) {
	gameObjects.push_back(new MenuButton(game, Vector2D(WIN_WIDTH / 2 - 200, WIN_HEIGHT / 2 +150), 100, 150, game->getTexture(Main), goToMainMenu));
	gameObjects.push_back(new MenuButton(game, Vector2D(WIN_WIDTH / 2 + 50, WIN_HEIGHT / 2 +150), 100, 150, game->getTexture(Exit), exitGame));
	if(c == 'w') background = game->getTexture(YouWinTx);
	else background = game->getTexture(GameOverTx);
}


void EndState::goToMainMenu(Game* g) {
	g->gameStateMachine->changeState(new MainMenuState(g));
}

void EndState::exitGame(Game* g) {
	g->exitGame();
}

