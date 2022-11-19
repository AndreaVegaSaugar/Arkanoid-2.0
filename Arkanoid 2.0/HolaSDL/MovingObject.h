#pragma once
#include "ArkanoidObject.h"

class MovingObject : public ArkanoidObject
{
protected:
	Vector2D dir;

public:
	virtual void loadFromFile();
	virtual void saveToFile();
};

