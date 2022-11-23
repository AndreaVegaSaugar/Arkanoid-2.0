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
	while (id != "Ball") saveFile >> id;
	if (id == "Ball")
	{
		getline(saveFile, info);
		pos = Vector2D((int)info[3], (int)info[5]);
		dir = Vector2D((int)info[7], (int)info[9]);
	}
	saveFile.close();
}

//Ball, posx, posy, dirx, diry
void Ball::saveToFile() 
{
	ofstream saveFile;
	saveFile.open("saveFile", std::ios::app);
	saveFile << "Ball " << pos.getX() << " " << pos.getY() << " " << dir.getX() << " " << dir.getY() << endl;
	saveFile.close();
}