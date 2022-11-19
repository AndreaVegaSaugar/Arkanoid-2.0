
#pragma once
#include "GameObject.h"
#include "checkML.h"
#include "Vector2D.h"
#include "Texture.h"

class ArkanoidObject : public GameObject
{
protected:
	// Argumentos de la clase
	Vector2D pos;
	int h;
	int w;
	Texture* texture;

public:
	//Constructora y destructora
	ArkanoidObject(Vector2D position, int height, int width, Texture* _texture) : GameObject(), pos(position), h(height), w(width), texture(_texture) {};
	~ArkanoidObject();

	// Métodos
	virtual void loadFromFile();
	virtual void saveToFile();
	SDL_Rect getRect()const;
};

