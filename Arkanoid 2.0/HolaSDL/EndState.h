#pragma once
#include "MenuGameState.h"
class EndState : public MenuGameState
{
private:
	MenuButton* MainMenu;
	MenuButton* exit;

public:
	EndState(Game* game, string _menuID, Texture* t, Vector2D p, int w, int h, MenuButton* mB, MenuButton* eB);
	void update();
	void render();
	void handleEvents();

	static void goToMainMenu(Game* game);
	static void exitGame(Game* game);
};

