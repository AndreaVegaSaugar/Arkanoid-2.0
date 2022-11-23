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
	string id, info1, info2;
	int aux1, aux2;
	while (id != "Ball") saveFile >> id;
	if (id == "Ball")
	{
		//char c;
		//while (c != '\n') 
		{
			//getline(saveFile, info);
			saveFile >> info1 >> info2;
			aux1 = stoi(info1); aux2 = stoi(info2);
			pos = Vector2D(aux1, aux2);
			saveFile >> info1 >> info2;
			aux1 = stoi(info1); aux2 = stoi(info2);
			dir = Vector2D(aux1, aux2);
			//c = getchar();
		}
	}
	saveFile.close();
}

//Ball, posx, posy, dirx, diry
void Ball::saveToFile() 
{
	ofstream saveFile;
	saveFile.open("saveFile"/*, std::ios::app*/);
	saveFile << "Ball " << pos.getX() << " " << pos.getY() << " " << dir.getX() << " " << dir.getY() << endl;
	saveFile.close();
}