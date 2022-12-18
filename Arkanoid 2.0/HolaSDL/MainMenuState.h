#pragma once
#include "MenuGameState.h"
#include "PauseState.h"
#include "PlayState.h"
#include "EndState.h"
#include "Game.h"
class MainMenuState: public MenuGameState
{
private:
	static const string menuID;
public:
	MainMenuState(Game* game);

	static void startGame(Game* g);
	static void loadGame(Game* g);
	static void exitGame(Game* g);
	virtual string getStateID() const { return menuID; }
};

