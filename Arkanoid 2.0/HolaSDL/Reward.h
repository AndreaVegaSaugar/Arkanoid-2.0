#pragma once
#include "checkML.h"
#include "Vector2D.h"
#include "Texture.h"
#include "MovingObject.h"
using namespace std;

class Reward : public MovingObject
{
private:
	char tipeReward;
	int row;
	int col;

public:
	Reward(Vector2D p, int h, int w, Vector2D d, Texture* t, char tipo);
	virtual void update();
	virtual void render() const;
	virtual void loadFromFile() {};
	virtual void saveToFile() {};
	Vector2D getDir() { return dir; }
	char getTipe() { return tipeReward; }
	bool collides(SDL_Rect ballRect, Vector2D& collisionVector);
	void movingAnimation();
};