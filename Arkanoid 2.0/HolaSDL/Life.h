#pragma once
#include "checkML.h"
#include "Vector2D.h"
#include "Texture.h"
#include "ArkanoidObject.h"


class Life :public ArkanoidObject
{
private:
	Vector2D pos;

	Texture* heart;
	int size;
	int life = 0;

	Texture* x;
	

	Texture* number;
	
	int row = 0;
	int col = 0;



public:
	Life(){}
	Life(Vector2D p, int s, Texture* t, int l, Texture* n, Texture* x);
	virtual void render() const;
	virtual void update(int l);
	virtual void loadFromFile() {};
	virtual void saveToFile() {};
};

