#pragma once
#include "MenuGameState.h"
#include "PauseState.h"
#include "PlayState.h"
#include "EndState.h"
class Game;
class MainMenuState: public MenuGameState
{
private:
	//MenuButton* start = nullptr;
	//MenuButton* load = nullptr;
	//MenuButton* exit = nullptr;


public:
	MainMenuState(Game* game);

	static void startGame(Game* g);
	static void loadGame(Game* g);
	static void exitGame(Game* g);
};

