#pragma once
#include <list>
#include <windows.h>
#include "GameObject.h"
#include "Texture.h"
#include "Vector2D.h"
#include "Const.h"
using namespace std;
class Game;
class GameState
{
protected:
	list<GameObject*> gameObjects; 
	Game* game;
	GameState(Game* g) : game(g) {};
	bool deleted = false;

public:
	void deleteState() { deleted = true; };
	virtual void update();
	virtual void render() const;
	virtual void handleEvent(SDL_Event event);

	virtual string getStateID() const = 0;
};

