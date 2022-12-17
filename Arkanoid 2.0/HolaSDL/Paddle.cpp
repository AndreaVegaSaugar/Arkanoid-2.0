#include "checkML.h"
#include "Paddle.h"
#include "PlayState.h"
#include <iostream>

using namespace std;

// Actualiza la posicion del paddle
void Paddle::update()
{
	if (pos.getX() + w > leftLimit && pos.getX() < rightLimit) {
		move();
	}

	if (pos.getX() <= leftLimit) {
		pos = Vector2D(leftLimit, pos.getY());
	}
	else if (pos.getX() + w >= rightLimit) {
		pos = Vector2D(rightLimit - w, pos.getY());
	}
}

// Controla el input del teclado para el movimiento del paddle
void Paddle::handleEvent(SDL_Event event) // cambiar a singular
{
	if (event.type == SDL_KEYDOWN) {
		if (event.key.keysym.sym == SDLK_LEFT) dir = Vector2D(-1, 0);
		else if (event.key.keysym.sym == SDLK_RIGHT)dir = Vector2D(1, 0);
	}
	else {
		dir = Vector2D(0, 0);
	}
}

// Controla las colisiones del paddle
bool Paddle::collides(SDL_Rect Rect, Vector2D& collisionVector, const Vector2D& dir) {
	SDL_Rect result;
	bool collide = false;
	
	if (SDL_IntersectRect(&Rect, &getRect(), &result)) {
		collisionVector = collision(Rect, result, dir);
		collisionVector.normalize();
		collide = true;
	}
	return collide;
}

// Metodo auxiliar para controlar colisiones
Vector2D Paddle::collision(const SDL_Rect& ballRect, const SDL_Rect& result, const Vector2D& dir) {

	Vector2D colVect = Vector2D(0, 0);

	float ballCenterX = ballRect.x + (0.5f * ballRect.w);
	float ballCenterY = ballRect.y + (0.5f * ballRect.h);

	float paddleCenterX = pos.getX() + (w / 2);
	float paddleCenterY = pos.getY() + (h / 2);

	if (result.h < result.w && dir.getY() > 0) 
	{
		colVect = Vector2D(-(result.x - pos.getX() - (w / 2)) / (w / 2), 2.5);
	}
	else {
		if (ballCenterX < pos.getX() && dir.getY() > 0) { colVect = Vector2D(-1, -1); }
		else if ( ballCenterX > (pos.getX() + w) && dir.getY() > 0) { colVect = Vector2D(1, -1); }
		else colVect = Vector2D(0, -1);
	}

	colVect.normalize();
	return colVect;
}

// Lee de archivo los datos relevantes del objeto y los modifica
void Paddle::loadFromFile(ifstream& loadFile)
{
	double info1, info2;
	
	loadFile >> info1 >> info2;
	pos = Vector2D(info1, info2);
	if (loadFile.fail() || info1 < 0 || info2 < 0) throw (FileFormatError("Error in reading paddle position from save file"));
	loadFile >> info1 >> info2;
	h = info1; w = info2;
	if (loadFile.fail() || h <= 0 || w <= 0) throw (FileFormatError("Error in reading paddle size from save file"));
}

// Guarda los datos relevantes del objeto
void Paddle::saveToFile(ofstream& saveFile)
{
	saveFile << "Paddle " << pos.getX() << " " << pos.getY() << " " << h << " " << w << endl;
}