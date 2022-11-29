#include "checkML.h"
#include "BlocksMap.h"
#include "Game.h"
#include <iostream>

using namespace std;

BlocksMap::~BlocksMap()
{
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; ++j) {
			if (gameMap[i][j] != nullptr) delete[] gameMap[i][j];
		}
		delete gameMap[i];
	}
	delete[] gameMap;
}

void BlocksMap::loadMap(const string& file)
{
	ifstream map;
	map.open(file);
	if (map.is_open())
	{
		int r, c;
		map >> r >> c;

		rows = r;
		cols = c;

		cellW = w / cols;
		cellH = h / rows;
		
		createMap(map);
	}
	else throw (FileNotFoundError("Error trying to open file: " + file));
	map.close();
}

void BlocksMap::createMap(ifstream& map) {
	int color;
	gameMap = new Block * *[rows];
	for (int i = 0; i < rows; ++i)
	{
		gameMap[i] = new Block * [cols];

		for (int j = 0; j < cols; ++j)
		{
			map >> color;
			if(map.fail() || color < 0 || color > 6) throw (FileFormatError("Error in reading map from level/save file"));
			if (color != 0) gameMap[i][j] = new Block(Vector2D(j, i), cellW, cellH, color, texture, game);
			else gameMap[i][j] = nullptr;
		}
	}
	if(getNumBlocks() == 0) throw (FileFormatError("Incorrect map in level/save file"));
}

void BlocksMap::render()const
{
	for (int n = 0; n < rows; ++n)
	{
		for (int m = 0; m < cols; ++m)
		{
			if (gameMap[n][m] != nullptr) gameMap[n][m]->render();
		}
	}
}

int BlocksMap::getNumBlocks()
{
	int cont = 0;
	for (int n = 0; n < rows; ++n)
	{
		for (int m = 0; m < cols; ++m)
		{
			if (gameMap[n][m] != nullptr) ++cont;
		}
	}

	return cont;
}

bool BlocksMap::collides(SDL_Rect ballRect, Vector2D& collisionVector, const Vector2D dir, Vector2D& pos)
{
	bool collide = false;
	int n = 0;
	SDL_Rect result;
	while (n < rows && !collide) {
		int m = 0;
		while (m < cols && !collide) {
			if ((gameMap[n][m] != nullptr) && SDL_IntersectRect(&gameMap[n][m]->getRect(), &ballRect, &result))
			{				
				pos = Vector2D(gameMap[n][m]->getRect().x, gameMap[n][m]->getRect().y);
				collisionVector = collision(result, ballRect, gameMap[n][m], dir);
				collide = true;
				gameMap[n][m] = nullptr;
			}
			++m;
		}
		++n;
	}

	return collide;
}

Vector2D BlocksMap::collision(const SDL_Rect& result, const SDL_Rect& ballRect, Block* b, const Vector2D dir)
{
	Vector2D colVect = Vector2D(0, 0);

	if (result.h < result.w) {
		if (dir.getY() < 0) { colVect = Vector2D(0, 1); }
		if (dir.getY() > 0) { colVect = Vector2D(0, -1); }
	}
	else {
		if (dir.getX() < 0) { colVect = Vector2D(1, 0); }
		if (dir.getX() > 0) { colVect = Vector2D(-1, 0); }
	}

	return colVect;
}

void BlocksMap::loadFromFile(ifstream& loadFile)
{
	int info1, info2;
	loadFile >> info1 >> info2;
	rows = info1; cols = info2;
	if (loadFile.fail() || info1 <= 0 || info2 <= 0) throw (FileFormatError("Error in reading map from save file"));
	cellH = h/ info1; cellW = w /info2;
	createMap(loadFile);
}

//Ball, posx, posy, dirx, diry
void BlocksMap::saveToFile(ofstream& saveFile)
{
	saveFile << "BlocksMap " << rows << " " << cols <<  endl;

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if(gameMap[i][j] == nullptr) saveFile << "0" << " ";
			else saveFile << gameMap[i][j]->getColor() << " ";
		}
		saveFile << endl;
	}

}