#include "MainMenuState.h"

MainMenuState::MainMenuState(Game* game) :MenuGameState(game) {
	gameObjects.push_back(new MenuButton(game, Vector2D(100, 170), 50, 50, game->getTexture(Load), loadGame));
	gameObjects.push_back(new MenuButton(game, Vector2D(100, 100), 50, 50, game->getTexture(Play), startGame));
	gameObjects.push_back(new MenuButton(game, Vector2D(100, 240), 50, 50, game->getTexture(Exit), exitGame));
	background = game->getTexture(Title);
}

 void MainMenuState::startGame(Game* g) {
	 cout << "StartGame" << endl;
	//g->gameStateMachine->changeState(new PlayState(g));
};

 void MainMenuState::loadGame(Game* g) {
	 cout << "LoadGame" << endl;
 }

 void MainMenuState::exitGame(Game* g) {
	 cout << "ExitGame" << endl;
 }