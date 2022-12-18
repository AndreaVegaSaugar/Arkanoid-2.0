#include "MainMenuState.h"
const string MainMenuState::menuID = "MENU";

MainMenuState::MainMenuState(Game* game) :MenuGameState(game) {
	gameObjects.push_back(new MenuButton(game, Vector2D( WIN_WIDTH/2 - 90, WIN_HEIGHT / 2 - 110), 100, 150, game->getTexture(Start), startGame));
	gameObjects.push_back(new MenuButton(game, Vector2D(WIN_WIDTH / 2 - 90, WIN_HEIGHT / 2), 100, 150, game->getTexture(Load), loadGame));
	gameObjects.push_back(new MenuButton(game, Vector2D(WIN_WIDTH / 2 - 90, WIN_HEIGHT / 2 + 110), 100, 150, game->getTexture(Exit), exitGame));
	background = game->getTexture(Title);
}

 void MainMenuState::startGame(Game* g) {
	 g->gameStateMachine->currentState()->deleteState();
     g->gameStateMachine->changeState(new PlayState(g, " "));
};

 void MainMenuState::loadGame(Game* g) {
	 ShowWindow(GetConsoleWindow(), SW_NORMAL);
	 string file;
	 cout << "Introduce code of your last game: ";
	 cin >> file;
	 ShowWindow(GetConsoleWindow(), SW_MINIMIZE);
	 try {
		 g->gameStateMachine->currentState()->deleteState();
		 g->gameStateMachine->changeState(new PlayState(g, file));
	 }
	 catch (FileFormatError e) {
		 cout << e.what() << endl;
	 }
	 catch (FileNotFoundError e) {
		 cout << e.what() << endl;
		 cout << "We couldn't find a save file with that name so we will start a new game for you";
		 g->gameStateMachine->currentState()->deleteState();
	     g->gameStateMachine->changeState(new PlayState(g, " "));
	 }
	
 }

 void MainMenuState::exitGame(Game* g) {
	 g->exitGame();
 }