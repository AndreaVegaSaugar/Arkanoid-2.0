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
	Game* game = nullptr;

public:
	Ball(Vector2D p, int size, Vector2D d, Texture* t, Game* g) : MovingObject(p, size, size, t, d), game(g) {};
    virtual void update();
	virtual void loadFromFile(ifstream& loadFile);
	virtual void saveToFile(ofstream& saveFile);
	Vector2D getDir() { return dir; }
	Vector2D getPos() { return pos; }
	void restartBall() { pos = (Vector2D(WIN_WIDTH / 2, WIN_HEIGHT / 2)); dir = (Vector2D(1, -1)); }
};
