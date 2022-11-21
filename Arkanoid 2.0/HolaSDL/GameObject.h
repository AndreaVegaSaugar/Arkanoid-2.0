#pragma once
#include "Vector2D.h"
#include "Texture.h"
class GameObject
{
public:
 
	virtual void render()const = 0;
	virtual void update() {};
	void handleEvent()const {};

};

