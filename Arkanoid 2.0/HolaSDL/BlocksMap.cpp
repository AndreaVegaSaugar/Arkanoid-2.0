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
				gameMap[i][j] = new Block(Vector2D(j, i), cellW, cellH, color, texture, game);

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
			gameMap[n][m]->render();
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
			if (isBlock(n, m)) ++cont;
		}
	}

	return cont;
}

bool BlocksMap::collides(SDL_Rect ballRect, Vector2D& collisionVector, Vector2D dir)
{
	bool collide = false;
	int n = 0;
	SDL_Rect result;
	while (n < rows && !collide) {
		int m = 0;
		while (m < cols && !collide) {
			if (isBlock(n, m) && SDL_IntersectRect(&gameMap[n][m]->getRect(), &ballRect, &result)) {
				collisionVector = collision(result, ballRect, gameMap[n][m], dir);
				collide = true;
				gameMap[n][m]->deleteBlock();

			}
			++m;
		}
		++n;
	}

	return collide;
}
Vector2D BlocksMap::collision(const SDL_Rect& result, const SDL_Rect& ballRect, Block* b, Vector2D dir)
{
	Vector2D colVect = Vector2D(0, 0);
	SDL_Rect blockPos = b->getRect();
	if (result.h < result.w) {
		if (dir.getY() < 0 && result.y < blockPos.x + blockPos.h) { colVect = Vector2D(0, 1); }
		if (dir.getY() > 0 && result.y <= blockPos.y) { colVect = Vector2D(0, -1); }
	}
	else {
		if (dir.getX() < 0 && result.x <= blockPos.x + blockPos.w && result.x >= blockPos.x) { colVect = Vector2D(1, 0); }
		if (dir.getX() > 0 && result.x >= blockPos.x && result.x + result.w <= blockPos.x + blockPos.w) { colVect = Vector2D(-1, 0); }
	}

	return colVect;
}