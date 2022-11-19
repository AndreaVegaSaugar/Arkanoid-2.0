#include "checkML.h"
#include "BlocksMap.h"
#include "Game.h"
#include <iostream>

using namespace std;

BlocksMap::BlocksMap(int mW, int mH, Texture* t, Game* g)
{
	rows = 0;
	cols = 0;

	mapW = mW;
	mapH = mH;

	cellW = 0;
	cellH = 0;

	texture = t;
	game = g;

	gameMap = nullptr;
}

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

		cellW = mapW / cols;
		cellH = mapH / rows;

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

bool BlocksMap::isBlock(int i, int j) {
	return gameMap[i][j]->getColor() != 0;
}

bool BlocksMap::collides(SDL_Rect ballRect, Vector2D& collisionVector, Vector2D dir)
{
	bool collide = false;
	int n = 0;
	SDL_Rect result;
	while (n < rows && !collide) {
		int m = 0;
		while (m < cols && !collide) {
			if (isBlock(n, m) && SDL_IntersectRect(&gameMap[n][m]->getDestRect(), &ballRect, &result)) {
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
	Vector2D colVect;
	colVect.setX(0); colVect.setY(0);

	if (result.h < result.w) {
		if (dir.getY() < 0 && result.y < b->getPos().getY() + b->getHeight()) { colVect = Vector2D(0, 1); }
		if (dir.getY() > 0 && result.y <= b->getPos().getY()) { colVect = Vector2D(0, -1); }
	}
	else {
		if (dir.getX() < 0 && result.x <= b->getPos().getX() + b->getWidth() && result.x >= b->getPos().getX()) { colVect = Vector2D(1, 0); }
		if (dir.getX() > 0 && result.x >= b->getPos().getX() && result.x + result.w <= b->getPos().getX() + b->getWidth()) { colVect = Vector2D(-1, 0); }
	}

	//float ballCenterX = ballRect.x + (0.5f * ballRect.w);
	//float ballCenterY = ballRect.y + (0.5f * ballRect.h);

	//float aux1 = ballRect.y + ballRect.h;
	//float aux2 = ballRect.x + ballRect.w;

	//if ((ballCenterX < b->getPos().getX()) /*&& ((aux1) > b->getPos().getY()) && ((ballRect.y) < (b->getPos().getY() + b->getHeight()))*/) colVect = Vector2D(1, 0);
	//else if ((ballCenterY > b->getPos().getY()) /* && ((aux2) > b->getPos().getX()) && ((ballRect.x) < (b->getPos().getX() + b->getWidth()))*/) colVect = Vector2D(0, 1);
	//else if ((ballCenterX > b->getPos().getX() + b->getWidth()) /* && ((aux1) > b->getPos().getY()) && ((ballRect.y) < (b->getPos().getY() + b->getHeight()))*/) colVect = Vector2D(-1, 0);
	//else if ((ballCenterY < (b->getPos().getY() + b->getHeight())) /* && ((aux2) > b->getPos().getX()) && ((ballRect.x) < (b->getPos().getX() + b->getWidth())) */ ) colVect = Vector2D(0, -1);

	return colVect;
}