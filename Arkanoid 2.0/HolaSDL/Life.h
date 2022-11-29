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

	Texture* heart = nullptr;
	int size = 0;

	Texture* x = nullptr;
	

	Texture* number = nullptr;
	
	int row = 0;
	int col = 0;



public:
	Life(){}
	Life(Vector2D p, int s, Texture* t, Texture* n, int l, Texture* x);
	virtual void render() const;
	virtual void update();
	virtual void loadFromFile(ifstream& loadFile);
	virtual void saveToFile(ofstream& saveFile);
	void resetLife();

};

