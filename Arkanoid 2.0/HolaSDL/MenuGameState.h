#pragma once
#include "GameState.h"
#include "PauseState.h"
#include "PlayState.h"
#include "EndState.h"
#include "MainMenuState.h"
class MenuGameState: public GameState
{
protected:
	string s_menuID;

	Texture* textureB = nullptr;
	SDL_Rect rectB;

	Vector2D posB;
	int widthB = 0;
	int heightB = 0;

public:
	MenuGameState(Game* game, string _menuID, Texture* t, Vector2D p, int w, int h);
	virtual void update() = 0;
	virtual void handleEvents() = 0;
	virtual void render() = 0;
	virtual string getStateID() const { return s_menuID; }
};

