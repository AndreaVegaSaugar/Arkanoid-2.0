#pragma once
#include "checkML.h"
#include "Vector2D.h"
#include "Texture.h"
#include "MovingObject.h"
using namespace std;

class Game;
class Ball : public MovingObject
{
private:
	Game* game;

public:
	Ball(Vector2D p, int size, Vector2D d, Texture* t, Game* g) : MovingObject(p, size, size, t, d), game(g) {};
	Vector2D getPos() { return pos; };
	Vector2D getDir() { return dir; }
	virtual void update();
	virtual void loadFromFile();
	virtual void saveToFile();
	// Hay que cambiar esto por constantes o algo
	void RestartBall() { pos = (Vector2D((double)800 / 2, (double)600 / 2)); dir = (Vector2D(1, -1)); }
};
