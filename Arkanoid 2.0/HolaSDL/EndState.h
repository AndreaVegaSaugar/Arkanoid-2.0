#pragma once
#include "MenuGameState.h"
#include "PauseState.h"
#include "PlayState.h"
#include "MainMenuState.h"
#include "Game.h"
class EndState : public MenuGameState
{
public:
	EndState(Game* game) : MenuGameState(game) {};
	void goToMainMenu(Game* game);
	void exitGame(Game* game);
};

