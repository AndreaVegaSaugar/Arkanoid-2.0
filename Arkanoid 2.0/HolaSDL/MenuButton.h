#pragma once
#include "GameObject.h"
#include "Game.h"
#include "ArkanoidObject.h"

using CallBack = void(Game* game);

class MenuButton : public GameObject
{
private:
	CallBack* function;
	SDL_Rect buttonRect;
	int row = 0;
	int col = 0;

public:
	MenuButton(Vector2D position, int height, int width, Texture* _texture, SDL_Rect bR, CallBack* funct, int r, int c) : GameObject(position, height, width, _texture), buttonRect(bR), function(funct), row(r), col(c) {};
	void render() const;
	void handleEvents() const;
};

// static fuctions 