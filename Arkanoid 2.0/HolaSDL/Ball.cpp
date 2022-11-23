#include "checkML.h"
#include "Ball.h"
#include "Game.h"

void Ball::update()
{
	Vector2D colVector;
	if (game->collides(getRect(), colVector))
	{
		colVector.normalize();
		dir = dir - colVector * (2 * (dir * colVector));
	}
	pos = pos + dir;
}

void Ball::loadFromFile()
{
	ifstream saveFile;
	saveFile.open("saveFile");
	string id, info;
	while (id != "Ball") saveFile >> id;	//saveFile.peek(); por si el getline coge la linea siguiente

	if (id == "Ball") 
	{
		getline(saveFile, info);
		int x = ((int)info[3]), y = ((int)info[5]);
		pos = Vector2D(x, y);
		x = ((int)info[7]), y = ((int)info[9]);
		dir = Vector2D(x, y);
	}

	saveFile.close();
}

// nombre, posX, posY, dirX, dirY
void Ball::saveToFile() 
{
	ofstream saveFile;
	saveFile.open("saveFile", std::ios::app);
	dir.normalize();
	saveFile << "Ball " << pos.getX() << " " << pos.getY() << " " << dir.getX() << " " << dir.getY() << endl;
	saveFile.close();
}