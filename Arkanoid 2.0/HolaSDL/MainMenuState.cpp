#include "MainMenuState.h"
#include "Game.h"
MainMenuState::MainMenuState(Game* game) :MenuGameState(game) {
	gameObjects.push_back(new MenuButton(game, Vector2D( WIN_WIDTH/2 - 90, WIN_HEIGHT / 2 - 110), 100, 150, game->getTexture(Play), startGame));
	gameObjects.push_back(new MenuButton(game, Vector2D(WIN_WIDTH / 2 - 90, WIN_HEIGHT / 2), 100, 150, game->getTexture(Load), loadGame));
	gameObjects.push_back(new MenuButton(game, Vector2D(WIN_WIDTH / 2 - 90, WIN_HEIGHT / 2 + 110), 100, 150, game->getTexture(Exit), exitGame));
	background = game->getTexture(Title);
}

 void MainMenuState::startGame(Game* g) {
     g->gameStateMachine->changeState(new PlayState(g, " "));
};

 void MainMenuState::loadGame(Game* g) {
	 string file;
	 cout << "Introduce code of your last game: ";
	 cin >> file;
	 try {
		 g->gameStateMachine->changeState(new PlayState(g, file));
	 }
	 catch (FileFormatError e) {
		 cout << e.what() << endl;
	 }
	 catch (FileNotFoundError e) {
		 cout << e.what() << endl;
		 cout << "We couldn't find a save file with that name so we will start a new game for you";
	     g->gameStateMachine->changeState(new PlayState(g, " "));
	 }
	
 }

 void MainMenuState::exitGame(Game* g) {
	 g->exitGame();
 }