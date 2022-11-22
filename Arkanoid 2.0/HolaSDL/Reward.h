#pragma once
#include "checkML.h"
#include "Vector2D.h"
#include "Texture.h"
#include "MovingObject.h"
using namespace std;

class Reward : public MovingObject
{
private:
	int tipoReward;
	int row;
	int col;

public:
	Reward(Vector2D p, int h, int w, Vector2D d, Texture* t, int tipo) : MovingObject(p, h, w, t, d);
	virtual void update();
	virtual void loadFromFile() {};
	virtual void saveToFile() {};
	Vector2D getDir() { return dir; }
	void movingAnimation();
};