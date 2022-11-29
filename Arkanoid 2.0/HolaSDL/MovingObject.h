#pragma once
#include "ArkanoidObject.h"

// Clase padre de BALL, PADDLE Y REWARD

class MovingObject : public ArkanoidObject
{
protected:
	Vector2D dir;

public:
	MovingObject(Vector2D pos, int h, int w, Texture* texture, Vector2D d): ArkanoidObject(pos,h,w,texture), dir(d){};
	virtual void loadFromFile(ifstream& loadFile) {};
	virtual void saveToFile(ofstream& saveFile) {};
};

