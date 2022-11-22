#pragma once
#include "checkML.h"
#include "Vector2D.h"
#include "Texture.h"
#include "ArkanoidObject.h"


using namespace std;
class Game;
class Block : public ArkanoidObject
{
private:
	int color;
	int row;
	int col;
	Game* game;

public:
	Block(Vector2D p, int h, int w, int c, Texture* t, Game* g);
	virtual void render() const;
	virtual void loadFromFile() {};
	virtual void saveToFile() {};
	int getColor() { return color; };
	void deleteBlock() { color = 0; };
	
};