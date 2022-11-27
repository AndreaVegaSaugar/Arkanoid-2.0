
#pragma once
#include "GameObject.h"
#include "checkML.h"
#include "Vector2D.h"
#include "Texture.h"
#include <iostream>
#include <fstream>
#include <string>

class ArkanoidObject : public GameObject
{
protected:
	// Argumentos de la clase
	Vector2D pos;
	int h = 0;
	int w = 0;
	Texture* texture = nullptr;

public:
	//Constructora y destructora uwu ladrame como se hace un metodo virtual mejor
	ArkanoidObject() {};
	ArkanoidObject(Vector2D position, int height, int width, Texture* _texture) : GameObject(), pos(position), h(height), w(width), texture(_texture) {};
	//virtual ~ArkanoidObject();

	// M�todos
	virtual void loadFromFile(string file) = 0;
	virtual void saveToFile(ofstream& saveFile) = 0;
	virtual void render() const;
	SDL_Rect getRect()const ;
};

// todo metodo destructor tiene que ser virtual