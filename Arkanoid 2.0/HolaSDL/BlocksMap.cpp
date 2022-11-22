#include "checkML.h"
#include "BlocksMap.h"
#include "Game.h"
#include <iostream>

using namespace std;

BlocksMap::~BlocksMap()
{
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; ++j) {
			delete[] gameMap[i][j];
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

		int color;
		gameMap = new Block * *[rows];
		for (int i = 0; i < rows; ++i)
		{
			gameMap[i] = new Block * [cols];

			for (int j = 0; j < cols; ++j)
			{
				map >> color;
				if (color != 0) gameMap[i][j] = new Block(Vector2D(j, i), cellW, cellH, color, texture, game);
				else gameMap[i][j] = nullptr;
			}
		}
	}
	else throw "Error loading level file from" + file;
	map.close();
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

bool BlocksMap::collides(SDL_Rect ballRect, Vector2D& collisionVector, const Vector2D dir)
{
	bool collide = false;
	int n = 0;
	SDL_Rect result;
	while (n < rows && !collide) {
		int m = 0;
		while (m < cols && !collide) {
			if ((gameMap[n][m] != nullptr) && SDL_IntersectRect(&gameMap[n][m]->getRect(), &ballRect, &result))
			{
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