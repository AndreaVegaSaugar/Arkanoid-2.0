#pragma once
#include "MenuGameState.h"
#include "PauseState.h"
#include "PlayState.h"
#include "MainMenuState.h"
#include "Game.h"
#include "checkML.h"

// Clase ENDSTATE que hereda de MENUGAMESTATE
class EndState : public MenuGameState
{
private:
	static const string endID;
public:

	// Constructora de la clase
	EndState(Game* game, char c);

	// Metodos publicos de la clase
	static void goToMainMenu(Game* game);
	static void exitGame(Game* game);
	virtual string getStateID() const { return endID; }
};

