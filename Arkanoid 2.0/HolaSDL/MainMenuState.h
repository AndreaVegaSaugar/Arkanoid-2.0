#pragma once
#include "MenuGameState.h"
class MainMenuState: public MenuGameState
{
private:
	MenuButton* start = nullptr;
	MenuButton* load = nullptr;
	MenuButton* exit = nullptr;

public:
	MainMenuState(Game* game, string _menuID, Texture* t, Vector2D p, int w, int h, MenuButton* sB, MenuButton* lB, MenuButton* eB) : MenuGameState(game, _menuID, t, p, w, h), start(sB), load(lB), exit(eB) {};
	void update();
	void render();
	void handleEvents();

	static void startGame(Game* game);
	static void loadGame(Game* game);
	static void exitGame(Game* game);
};

