#pragma once
#include "checkML.h"
#include "Vector2D.h"
#include "Texture.h"
#include "MovingObject.h"

using namespace std;

// Clase BALL que hereda de MOVINGOBJECT
class PlayState;
class Ball : public MovingObject
{
private:
	PlayState* game = nullptr;

public:
	// Constructora de la clase
	Ball(Vector2D p, int size, Vector2D d, Texture* t, PlayState* g, double s) : MovingObject(p, size, size, t, d, s), game(g) {};

	// Metodos publicos de la clase
    virtual void update();
	virtual void loadFromFile(ifstream& loadFile);
	virtual void saveToFile(ofstream& saveFile);

	// Getters
	Vector2D getDir() { return dir; }
	Vector2D getPos() { return pos; }
	int getSize() { return w; }

	// Metodos que usa el game para resetear la bola
	void setSize(int size) { w = size; h = size; };
	void restartBall() { pos = (Vector2D(WIN_WIDTH / 2, WIN_HEIGHT / 2)); dir = (Vector2D(1, -1)); h = BALL_SIZE; w = BALL_SIZE; }
};
