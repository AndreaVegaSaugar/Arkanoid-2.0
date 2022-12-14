#pragma once
#include "MenuGameState.h"
class PauseState : public MenuGameState
{
private:
	MenuButton* resume = nullptr;
	MenuButton* save = nullptr;
	MenuButton* MainMenu = nullptr; // lista de objetos

public:
	PauseState(Game* game, string _menuID, Texture* t, Vector2D p, int w, int h, MenuButton* rB, MenuButton* sB, MenuButton* mB) : MenuGameState(game, _menuID, t, p, w, h), resume(rB), save(sB), MainMenu(mB) {};
	void update();
	void render();
	void handleEvents(); // como que no harian falta porque es comportamiento heredado de recorrer una lista con iteradoes

	
	static void resumeGame(Game* game);
	static void saveGame(Game* game);
	static void goToMainMenu(Game* game);
};

