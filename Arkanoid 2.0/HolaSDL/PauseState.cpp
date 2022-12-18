#include "PauseState.h"
const string PauseState::pauseID = "PAUSE";

PauseState::PauseState(Game* game) : MenuGameState(game) {
	gameObjects.push_back(new MenuButton(game, Vector2D(WIN_WIDTH / 2 - 90, WIN_HEIGHT / 2 - 110), 100, 150, game->getTexture(Resume), resumeGame));
	gameObjects.push_back(new MenuButton(game, Vector2D(WIN_WIDTH / 2 - 90, WIN_HEIGHT / 2), 100, 150, game->getTexture(Save), saveGame));
	gameObjects.push_back(new MenuButton(game, Vector2D(WIN_WIDTH / 2 - 90, WIN_HEIGHT / 2 + 110), 100, 150, game->getTexture(Main), goToMainMenu));
	background = game->getTexture(Pause);
}
void PauseState::resumeGame(Game* game) {
	game->gameStateMachine->currentState()->deleteState();
	game->gameStateMachine->popState();
}

void PauseState::saveGame(Game* game) {
	ShowWindow(GetConsoleWindow(), SW_NORMAL);
	string code;
	cout << "Introduce el codigo de guardado: ";
	cin >> code;
	ShowWindow(GetConsoleWindow(), SW_MINIMIZE);
	game->gameStateMachine->popState();
	PlayState* play = static_cast<PlayState*>(game->gameStateMachine->currentState());
	play->saveToFile(code);
	game->gameStateMachine->pushState(new PauseState(game));
	
}

void PauseState::goToMainMenu(Game* game) {
	game->gameStateMachine->currentState()->deleteState();
	game->gameStateMachine->changeState(new MainMenuState(game));
}