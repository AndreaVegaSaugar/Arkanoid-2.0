#pragma once
#include "ArkanoidObject.h"

class MovingObject : public ArkanoidObject
{
protected:
	Vector2D dir;

public:
	MovingObject(Vector2D pos, int h, int w, Texture* texture, Vector2D d): ArkanoidObject(pos,h,w,texture), dir(d){};
	virtual void loadFromFile();
	virtual void saveToFile();
};

