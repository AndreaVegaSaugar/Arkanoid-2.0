#pragma once
#include "GameState.h"

class MenuGameState: public GameState {
protected:
	Texture* textureB = nullptr;
	SDL_Rect rectB;

	Vector2D posB;
	int widthB = 0;
	int heightB = 0;
	MenuGameState(Game* game);
};

