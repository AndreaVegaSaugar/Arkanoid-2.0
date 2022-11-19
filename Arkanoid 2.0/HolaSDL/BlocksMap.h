#pragma once
#include "checkML.h"
#include"Block.h"
#include<fstream>
#include <string>

using namespace std;

class Game;
class BlocksMap
{
private:
	Block*** gameMap;
	int rows;
	int cols;
	int cellW;
	int cellH;
	Game* game;

public:
	BlocksMap() : gameMap(nullptr), rows(0), cols(0), cellW(0), cellH(0), texture(nullptr), game(nullptr) {};
	BlocksMap(int mW, int mH, Texture* t, Game* g);
	void loadMap(const string& file);
	~BlocksMap();
	void render() const;
	int getNumBlocks();
	bool collides(SDL_Rect ballRect, Vector2D& collisonVector, Vector2D dir);
	bool isBlock(int i, int j);

protected:
	Vector2D collision(const SDL_Rect& result, const SDL_Rect& ballRect, Block* b, Vector2D dir);

};



