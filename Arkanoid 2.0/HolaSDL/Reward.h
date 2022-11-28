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
	int row = 0;
	int col = 0;
	int totalCol = 0;

public:
	Reward(Vector2D p, int h, int w, Vector2D d, Texture* t, char tipo, int tC);
	virtual void update();
	virtual void render() const;
	virtual void loadFromFile(string file) {};
	virtual void saveToFile(ofstream& saveFile);
	Vector2D getDir() { return dir; }
	void getTipe(char& c) { c = tipeReward; }
	bool collides(SDL_Rect ballRect, Vector2D& collisionVector);
};