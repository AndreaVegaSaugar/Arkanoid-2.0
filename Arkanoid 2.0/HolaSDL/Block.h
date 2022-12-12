#pragma once
#include "checkML.h"
#include "Vector2D.h"
#include "Texture.h"
#include "ArkanoidObject.h"

using namespace std;

// Clase BLOCK, que hereda de ARKANOIDOBJECT
class PlayState;
class Block : public ArkanoidObject
{
private:
	int color = 0;
	int row = 0;
	int col = 0;
	PlayState* game = nullptr;

public:
	// Constructora de la clase
	Block(Vector2D p, int h, int w, int c, Texture* t, PlayState* g);
	
	// Getter
	int getColor() { return color; };

	// Metodos publicos de la clase
	virtual void render() const;
	virtual void loadFromFile(ifstream& loadFile) {};
	virtual void saveToFile(ofstream& saveFile) {};
	void deleteBlock() { color = 0; };
	SDL_Rect getRect()const;
};