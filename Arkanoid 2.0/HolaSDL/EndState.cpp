#include "EndState.h"
EndState::EndState(Game* game) : MenuGameState(game) {
	gameObjects.push_back(new MenuButton(game, Vector2D(100, 170), 50, 50, game->getTexture(Main), goToMainMenu));
	gameObjects.push_back(new MenuButton(game, Vector2D(100, 240), 50, 50, game->getTexture(Exit), exitGame));
	//background = game->getTexture();
}


void EndState::goToMainMenu(Game* game) {
	cout << "MainMenu";
}

void EndState::exitGame(Game* game) {
	cout << "Exit";
}

