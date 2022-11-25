#pragma once
#include "checkML.h"
#include "Vector2D.h"
#include "Texture.h"
#include "ArkanoidObject.h"

class Life : public ArkanoidObject
{
private:
	int life = 0;
	int row = 0;
	int col = 0;
	Texture* heart;
	Texture* x;


public:
	Life(Vector2D p, int h, int w, Texture* t, int l, Texture* h, Texture* x);
	virtual void render() const;
	virtual void update();
	virtual void loadFromFile() {};
	virtual void saveToFile() {};
};

