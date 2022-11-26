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
	int color = 0;
	int row = 0;
	int col = 0;
	Game* game = nullptr;

public:
	Block(Vector2D p, int h, int w, int c, Texture* t, Game* g);
	virtual void render() const;
	virtual void loadFromFile() {};
	virtual void saveToFile() {};
	int getColor() { return color; };
	void deleteBlock() { color = 0; };
	SDL_Rect getRect()const;
};