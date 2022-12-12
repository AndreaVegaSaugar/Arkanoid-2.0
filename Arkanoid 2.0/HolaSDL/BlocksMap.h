#pragma once
#include "checkML.h"
#include"Block.h"
#include<fstream>
#include <string>
#include "ArkanoidObject.h"

using namespace std;

// Clase BLOCKSMAP que hereda de ARKANOIDOBJECT
class PlayState;
class BlocksMap : public ArkanoidObject
{
private:
	Block*** gameMap = nullptr;
	int rows = 0;
	int cols = 0;
	int cellW = 0;
	int cellH = 0;
	PlayState* game = 0;

public:
	// Constructoras de la clase
	BlocksMap() {};
	BlocksMap(int mW, int mH, Texture* t, PlayState* g) : ArkanoidObject(), gameMap(nullptr), rows(0), cols(0), cellW(0), cellH(0), game(g) { texture = t; h = mH; w = mW; };
	
	// Destructora de la clase
	virtual ~BlocksMap();

	// Metodos publicos de la clase
	void loadMap(const string& file);
	virtual void render() const;
	virtual void loadFromFile(ifstream& loadFile);
	virtual void saveToFile(ofstream& saveFile);
	int getNumBlocks();
	bool collides(SDL_Rect ballRect, Vector2D& collisonVector, const Vector2D dir, Vector2D& pos);

protected:
	void createMap(ifstream& map);
	Vector2D collision(const SDL_Rect& result, const SDL_Rect& ballRect, Block* b, const Vector2D dir);

};



