#pragma once
#include "checkML.h"
#include "ArkanoidObject.h"

using namespace std;

// Case WALL que hereda de ARKANOIDOBJECT
class Wall : public ArkanoidObject
{
private:
	Vector2D colVector;

public:
	// Constructoras de la clase
	Wall() :ArkanoidObject() {};
	Wall(Vector2D p, int h, int w, Texture* t, Vector2D cVect) : ArkanoidObject(p, h, w, t), colVector(cVect) {};

	// Metodos publicos de la clase
	virtual void loadFromFile(ifstream& loadFile) {};
	virtual void saveToFile(ofstream& saveFile) {};
	bool collides(SDL_Rect ballRect, Vector2D& collisonVector);
};

