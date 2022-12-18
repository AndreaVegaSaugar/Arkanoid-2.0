#pragma once
#include "ArkanoidObject.h"
#include "checkML.h"
// Clase padre de BALL, PADDLE Y REWARD
class MovingObject : public ArkanoidObject
{
protected:
	Vector2D dir;
	double speed;

public:
	// Constructora de la clase
	MovingObject(Vector2D pos, int h, int w, Texture* texture, Vector2D d, int s): ArkanoidObject(pos,h,w,texture), dir(d), speed(s){};
	
	// Metodos publicos de la clase
	virtual void loadFromFile(ifstream& loadFile) {};
	virtual void saveToFile(ofstream& saveFile) {};
	void move();
};

