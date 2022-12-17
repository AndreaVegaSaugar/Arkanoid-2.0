#pragma once
#include "Vector2D.h"
#include "Texture.h"
#include "checkML.h"
#include "ArkanoidError.h"
#include "FileFormatError.h"
#include "FileNotFoundError.h"
#include "SDLError.h"
#include "Const.h"
// Definicion clase padre GAMEOBJECT 
class GameObject
{
protected:
	// Argumentos de la clase
	Vector2D pos;
	int h = 0;
	int w = 0;
	Texture* texture = nullptr;

public:
	GameObject() {};
	GameObject(Vector2D position, int height, int width, Texture* _texture) : pos(position), h(height), w(width), texture(_texture) {};
	virtual void render()const = 0;
	virtual void update() {};
	virtual void handleEvent(SDL_Event event){};
	
	virtual void loadFromFile(ifstream& loadFile){}
	virtual void saveToFile(ofstream& saveFile) {};
	SDL_Rect getRect()const;
};

