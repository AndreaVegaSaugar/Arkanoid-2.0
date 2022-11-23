
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
	int h;
	int w;
	Texture* texture;

public:
	//Constructora y destructora uwu ladrame como se hace un metodo virtual mejor
	ArkanoidObject() {};
	ArkanoidObject(Vector2D position, int height, int width, Texture* _texture) : GameObject(), pos(position), h(height), w(width), texture(_texture) {};
	//virtual ~ArkanoidObject();

	// Métodos
	virtual void loadFromFile() = 0;
	virtual void saveToFile() = 0;
	virtual void render() const;
	SDL_Rect getRect()const ;
};

// todo metodo destructor tiene que ser virtual