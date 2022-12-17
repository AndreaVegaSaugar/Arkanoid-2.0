#pragma once
#include "GameObject.h"
#include "ArkanoidObject.h"
class Game;
class MenuButton : public GameObject
{
	enum States {
		notPointed = 0,
		pointed = 1,
	};
private:
	void (*callback) (Game* game);
	int pointer = 0;
	Game* g;
	int current = notPointed;
	

public:
	MenuButton(Game* _game, Vector2D position, int height, int width, Texture* _texture, void(*_callback) (Game* game));
	virtual void render() const;
	virtual void handleEvent(SDL_Event event);
	
};

