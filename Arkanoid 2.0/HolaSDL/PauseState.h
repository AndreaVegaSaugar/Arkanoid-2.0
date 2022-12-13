#pragma once
#include "MenuGameState.h"
class PauseState : public MenuGameState
{
private:
	MenuButton* resume = nullptr;
	MenuButton* save = nullptr;
	MenuButton* MainMenu = nullptr;
	static const string s_pauseID;

public:
	PauseState(Game* game, string _menuID, Texture* t, Vector2D p, int w, int h, MenuButton* rB, MenuButton* sB, MenuButton* mB) : MenuGameState(game, _menuID, t, p, w, h), resume(rB), save(sB), MainMenu(mB) {};
	void update();
	void render() const;
	void handleEvents();
	virtual string getStateID() const { return s_pauseID; }

	static void resumeGame(Game* game);
	static void saveGame(Game* game);
	static void goToMainMenu(Game* game);
};

