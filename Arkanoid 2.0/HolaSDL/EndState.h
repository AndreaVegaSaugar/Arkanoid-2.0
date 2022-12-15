#pragma once
#include "MenuGameState.h"
#include "PauseState.h"
#include "PlayState.h"
#include "MainMenuState.h"
#include "Game.h"
class EndState : public MenuGameState
{
public:
	EndState(Game* game);
	static void goToMainMenu(Game* game);
	static void exitGame(Game* game);
};

