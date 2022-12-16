#pragma once
#include "GameObject.h"
#include "ArkanoidObject.h"
class Game;
class MenuButton : public GameObject
{
private:
	void (*callback) (Game* game);
	int row = 0;
	int col = 0;
	Game* g;

public:
	MenuButton(Game* _game, Vector2D position, int height, int width, Texture* _texture, void(*_callback) (Game* game));
	void render() const;
	void handleEvent(SDL_Event event);
	
};

