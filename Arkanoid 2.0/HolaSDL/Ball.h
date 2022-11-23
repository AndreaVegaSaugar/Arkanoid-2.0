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
    virtual void update();
	virtual void loadFromFile();
	virtual void saveToFile();
	Vector2D getDir() { return dir; }
	Vector2D getPos() { return pos; }
	// Cambiar por constantes o algo
	void restartBall() { pos = (Vector2D(800 / 2, 600 / 2)); dir = (Vector2D(1, -1)); }
};
