#pragma once
#include "GameState.h"
#include "MenuButton.h"

class MenuGameState: public GameState {
protected:
	Texture* background = nullptr;
	SDL_Rect rectBack;

	Vector2D posB;
	int widthB = 0;
	int heightB = 0;
	MenuGameState(Game* game);
	void render() const;
};

