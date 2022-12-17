#pragma once
#include "MenuGameState.h"
#include "PauseState.h"
#include "PlayState.h"
#include "MainMenuState.h"
#include "Game.h"
class EndState : public MenuGameState
{
private:

public:
	EndState(Game* game, char c);
	static void goToMainMenu(Game* game);
	static void exitGame(Game* game);
};

