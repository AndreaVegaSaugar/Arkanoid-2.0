#include "EndState.h"

// Identificador de clase de estado
const string EndState::endID = "END";

// Constructora de la clase, que difine sus botones y fondo
EndState::EndState(Game* game, char c) : MenuGameState(game) {
	gameObjects.push_back(new MenuButton(game, Vector2D(WIN_WIDTH / 2 - 200, WIN_HEIGHT / 2 +150), 100, 150, game->getTexture(Main), goToMainMenu));
	gameObjects.push_back(new MenuButton(game, Vector2D(WIN_WIDTH / 2 + 50, WIN_HEIGHT / 2 +150), 100, 150, game->getTexture(Exit), exitGame));
	if(c == 'w') background = game->getTexture(YouWinTx); // Distintos fondos dependiendo de si se ha ganado o perdido
	else background = game->getTexture(GameOverTx);
}

// Metodo (callback) para volver al MainMenu
void EndState::goToMainMenu(Game* g) {
	g->gameStateMachine->currentState()->deleteState();
	g->gameStateMachine->changeState(new MainMenuState(g));
}

// Metodo (callback) para salir de la aplicacion
void EndState::exitGame(Game* g) {
	g->exitGame();
}

