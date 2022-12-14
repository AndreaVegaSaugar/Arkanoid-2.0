#include "checkML.h"
#include "Ball.h"
#include "PlayState.h"

// Actualiza la posicion y direccion de la bola teniendo en cuenta sus colisiones
void Ball::update()
{
	Vector2D colVector; // Declaracion vector de colision que enviaremos al game
	if (game->collides(getRect(), colVector))
	{
		colVector.normalize(); 
		dir = dir - colVector * (2 * (dir * colVector));
	}
	dir.normalize(); // Normalizamos vector para mantener la velocidad de la bola constante
	move(); 
}

// Lee de archivo los datos relevantes del objeto y los modifica
void Ball::loadFromFile(ifstream& loadFile)
{
	double info1, info2;

	loadFile >> info1 >> info2;
	pos = Vector2D(info1, info2);
	if (loadFile.fail() || info1 < 0 || info2 < 0) throw (FileFormatError("Error in reading ball position from save file"));
	loadFile >> info1 >> info2;
	dir = Vector2D(info1, info2);
	if (loadFile.fail()) throw (FileFormatError("Error in reading ball direction from save file"));
	loadFile >> info1 >> info2;
	w = info1; h = info2;
	if (loadFile.fail() || info1 <= 0 || info2 <= 0) throw (FileFormatError("Error in reading ball size from save file"));
}

// Guarda los datos relevantes del objeto
void Ball::saveToFile(ofstream& saveFile)
{
	saveFile << "Ball " << pos.getX() << " " << pos.getY() << " " << dir.getX() << " " << dir.getY() << " " << w << " " << h << endl;
	
}