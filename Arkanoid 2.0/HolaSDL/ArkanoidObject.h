
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
	virtual void render() const;
	virtual void loadFromFile(ifstream& loadFile) {}
	virtual void saveToFile(ofstream& saveFile) {};
	
	// Destructora de la clase
	virtual ~ArkanoidObject() {};
};
