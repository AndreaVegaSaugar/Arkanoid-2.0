#pragma once
#include "checkML.h"
#include "Vector2D.h"
#include "Texture.h"
#include "ArkanoidObject.h"


class Life :public ArkanoidObject
{
public: 
	int lives = 3;

private:
	Vector2D pos;

	Texture* heart;
	int size;

	Texture* x;
	

	Texture* number;
	
	int row = 0;
	int col = 0;



public:
	Life(){}
	Life(Vector2D p, int s, Texture* t, Texture* n, int l, Texture* x);
	virtual void render() const;
	virtual void update();
	virtual void loadFromFile() {};
	virtual void saveToFile() {};

};

