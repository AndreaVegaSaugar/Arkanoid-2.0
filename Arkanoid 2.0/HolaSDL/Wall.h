#pragma once
#include "checkML.h"
#include "ArkanoidObject.h"

using namespace std;

// Case WALL
class Wall : public ArkanoidObject
{
private:
	Vector2D colVector;

public:
	// Constructora(s)
	Wall(Vector2D p, int h, int w, Texture* t, Vector2D cVect) : ArkanoidObject(p, h, w, t), colVector(cVect) {};

	// Metodos publicos de la clase
	void render() const override;
	void update() {};
	bool collides(SDL_Rect ballRect, Vector2D& collisonVector);
};

