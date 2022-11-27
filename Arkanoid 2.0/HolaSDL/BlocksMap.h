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
	int rows = 0;
	int cols = 0;
	int cellW = 0;
	int cellH = 0;
	Game* game = 0;

public:
	BlocksMap() {};
	BlocksMap(int mW, int mH, Texture* t, Game* g) : ArkanoidObject(), gameMap(nullptr), rows(0), cols(0), cellW(0), cellH(0), game(g) { texture = t; h = mH; w = mW; };
	void loadMap(const string& file);
	virtual ~BlocksMap();
	virtual void render() const;
	virtual void loadFromFile(ifstream& loadFile);
	virtual void saveToFile(ofstream& saveFile);
	int getNumBlocks();
	bool collides(SDL_Rect ballRect, Vector2D& collisonVector, const Vector2D dir, Vector2D& pos);

protected:
	Vector2D collision(const SDL_Rect& result, const SDL_Rect& ballRect, Block* b, const Vector2D dir);

};



