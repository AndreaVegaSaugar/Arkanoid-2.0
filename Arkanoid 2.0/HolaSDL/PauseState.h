#pragma once
#include "MenuGameState.h"
#include "PlayState.h"
#include "EndState.h"
#include "MainMenuState.h"
#include "Game.h"
class PauseState : public MenuGameState {
private:

	//MenuButton* resume = nullptr;
	//MenuButton* save = nullptr;
	//MenuButton* MainMenu = nullptr;
	static const string s_pauseID;

public:
	PauseState(Game* game);

	static void resumeGame(Game* game);
	static void saveGame(Game* game);
	static void goToMainMenu(Game* game);
};

