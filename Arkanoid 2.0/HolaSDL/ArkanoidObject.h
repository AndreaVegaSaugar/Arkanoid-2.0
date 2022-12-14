
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
public:
	//Constructora y destructora 
	ArkanoidObject():GameObject() {};
	ArkanoidObject(Vector2D position, int height, int width, Texture* _texture) : GameObject(position, height, width, _texture) {};

	// Métodos
	virtual void loadFromFile(ifstream& loadFile) = 0;
	virtual void saveToFile(ofstream& saveFile) = 0;
	virtual void render() const;
	
	// Destructora de la clase
	virtual ~ArkanoidObject() {};

	//SDL_Rect getRect()const ;
};
