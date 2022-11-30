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
	Ball(Vector2D p, int size, Vector2D d, Texture* t, Game* g, double s) : MovingObject(p, size, size, t, d, s), game(g) {};
    virtual void update();
	virtual void loadFromFile(ifstream& loadFile);
	virtual void saveToFile(ofstream& saveFile);
	Vector2D getDir() { return dir; }
	Vector2D getPos() { return pos; }
	int getSize() { return w; }
	void setSize(int size) { w = size; h = size; };
	void restartBall() { pos = (Vector2D(WIN_WIDTH / 2, WIN_HEIGHT / 2)); dir = (Vector2D(1, -1)); h = BALL_SIZE; w = BALL_SIZE; }
};
