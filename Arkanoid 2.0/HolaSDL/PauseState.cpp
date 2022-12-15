#include "PauseState.h"

PauseState::PauseState(Game* game) : MenuGameState(game) {
	gameObjects.push_back(new MenuButton(game, Vector2D(100, 170), 50, 50, game->getTexture(Resume), resumeGame));
	gameObjects.push_back(new MenuButton(game, Vector2D(100, 100), 50, 50, game->getTexture(Heart), saveGame));
	gameObjects.push_back(new MenuButton(game, Vector2D(100, 240), 50, 50, game->getTexture(Exit), goToMainMenu));
}

void PauseState::resumeGame(Game* game) {
	cout << "Resume";
}

void PauseState::saveGame(Game* game) {
	cout << "Save";
}

void PauseState::goToMainMenu(Game* game) {
	cout << "MainMenu";
}