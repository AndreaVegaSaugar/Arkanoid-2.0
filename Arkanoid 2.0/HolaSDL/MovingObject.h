#pragma once
#include "ArkanoidObject.h"

class MovingObject : public ArkanoidObject
{
protected:
	Vector2D dir;
	int speed;

public:
	MovingObject(Vector2D pos, int h, int w, Texture* texture, Vector2D d, int s): ArkanoidObject(pos,h,w,texture), dir(d), speed(s){};
	virtual void loadFromFile(ifstream& loadFile) {};
	virtual void saveToFile(ofstream& saveFile) {};
	void move();
};

