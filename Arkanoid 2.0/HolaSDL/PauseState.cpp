#include "PauseState.h"

PauseState::PauseState(Game* game) : MenuGameState(game) {
	gameObjects.push_back(new MenuButton(game, Vector2D(WIN_WIDTH / 2 - 90, WIN_HEIGHT / 2 - 110), 100, 150, game->getTexture(Resume), resumeGame));
	gameObjects.push_back(new MenuButton(game, Vector2D(WIN_WIDTH / 2 - 90, WIN_HEIGHT / 2), 100, 150, game->getTexture(Save), saveGame));
	gameObjects.push_back(new MenuButton(game, Vector2D(WIN_WIDTH / 2 - 90, WIN_HEIGHT / 2 + 110), 100, 150, game->getTexture(Main), goToMainMenu));
}

void PauseState::resumeGame(Game* game) {
	game->gameStateMachine->popState();
}

void PauseState::saveGame(Game* game) {
	cout << "Save";
}

void PauseState::goToMainMenu(Game* game) {
	game->gameStateMachine->changeState(new MainMenuState(game));
}