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

	// Constructoras y destructora de la clase
	GameObject() {};
	GameObject(Vector2D position, int height, int width, Texture* _texture) : pos(position), h(height), w(width), texture(_texture) {};
	virtual ~GameObject() {};

	// Metodos publicos de la clase
	virtual void render()const = 0;
	virtual void update() {};
	virtual void handleEvent(SDL_Event event){};

	// Getters
	SDL_Rect getRect()const;
};

