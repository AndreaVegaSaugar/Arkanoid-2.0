#pragma once
#include <list>
#include "ArkanoidObject.h"
#include "Game.h"
using namespace std;
//class Game;
class GameState
{
protected:
	list<ArkanoidObject*> arkanoidObjectList;
	Game* game;
public:
	GameState();
	void update();
	void render() const;
	void handleEvents() const;
};

