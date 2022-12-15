#pragma once
#include <list>
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
	GameState(Game* g): game(g) {}
public:
	virtual void update();
	virtual void render() const;
	virtual void handleEvents();
};

