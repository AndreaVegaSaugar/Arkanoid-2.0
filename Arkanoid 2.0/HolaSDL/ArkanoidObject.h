
#pragma once
#include "GameObject.h"
#include "checkML.h"
#include "Vector2D.h"
#include "Texture.h"
#include <iostream>
#include <fstream>
#include <string>

// Clase padre junto con GAMEOBJECT de todos los gameObjects

class ArkanoidObject : public GameObject
{
protected:
	// Argumentos de la clase
	Vector2D pos;
	int h = 0;
	int w = 0;
	Texture* texture = nullptr;

public:
	//Constructora y destructora 
	ArkanoidObject() {};
	ArkanoidObject(Vector2D position, int height, int width, Texture* _texture) : GameObject(), pos(position), h(height), w(width), texture(_texture) {};

	// Métodos
	virtual void loadFromFile(ifstream& loadFile) {};
	virtual void saveToFile(ofstream& saveFile) {};
	virtual void render() const;
	
	// Destructora de la clase
	virtual ~ArkanoidObject() {};

	SDL_Rect getRect()const ;
};
