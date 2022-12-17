#include "MainMenuState.h"
#include "Game.h"
MainMenuState::MainMenuState(Game* game) :MenuGameState(game) {
	gameObjects.push_back(new MenuButton(game, Vector2D( WIN_WIDTH/2 - 90, WIN_HEIGHT / 2 - 110), 100, 150, game->getTexture(Play), startGame));
	gameObjects.push_back(new MenuButton(game, Vector2D(WIN_WIDTH / 2 - 90, WIN_HEIGHT / 2), 100, 150, game->getTexture(Load), loadGame));
	gameObjects.push_back(new MenuButton(game, Vector2D(WIN_WIDTH / 2 - 90, WIN_HEIGHT / 2 + 110), 100, 150, game->getTexture(Exit), exitGame));
	background = game->getTexture(Title);
}

 void MainMenuState::startGame(Game* g) {
	 cout << "StartGame" << endl;
     g->gameStateMachine->changeState(new PlayState(g));
};

 void MainMenuState::loadGame(Game* g) {
	 cout << "LoadGame" << endl;
 }

 void MainMenuState::exitGame(Game* g) {
	 cout << "ExitGame" << endl;
 }