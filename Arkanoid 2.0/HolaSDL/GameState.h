#pragma once
#include <list>
#include "ArkanoidObject.h"
#include "Game.h"
using namespace std;

class GameState
{
protected:
	list<GameObject*> gameObjects;
	Game* game;

public:
	GameState(Game* g) : game(g) {}
	virtual void update() = 0;
	virtual void render() const = 0;
	virtual void handleEvents() const = 0;
	virtual string getStateID() const = 0;
};

