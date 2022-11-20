#pragma once
#include "checkML.h"
#include"Block.h"
#include<fstream>
#include <string>
#include "ArkanoidObject.h"

using namespace std;

class Game;
class BlocksMap : public ArkanoidObject
{
private:
	Block*** gameMap;
	int rows;
	int cols;
	int cellW;
	int cellH;
	Game* game;

public:

	BlocksMap(int mW, int mH, Texture* t, Game* g) : ArkanoidObject(Vector2D(0, 0), mH, mW, t), gameMap(nullptr), rows(0), cols(0), cellW(0), cellH(0), game(g) {};
	void loadMap(const string& file);
	~BlocksMap();
	void render() const override;
	void update();
	int getNumBlocks();
	bool collides(SDL_Rect ballRect, Vector2D& collisonVector, Vector2D dir);
	bool isBlock(int i, int j);

protected:
	Vector2D collision(const SDL_Rect& result, const SDL_Rect& ballRect, Block* b, Vector2D dir);

};



