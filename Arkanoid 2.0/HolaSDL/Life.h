#pragma once
#include "checkML.h"
#include "Vector2D.h"
#include "Texture.h"
#include "ArkanoidObject.h"

// Clase VIDA que hereda de ARKANOIDOBJECT
class Life :public ArkanoidObject
{
public: 
	int lives = 3;

private:

	Texture* heart = nullptr;
	Texture* x = nullptr;
	Texture* number = nullptr;
	
	int row = 0;
	int col = 0;

public:
	// Constructoras de la clase
	Life(){}
	Life(Vector2D p, int s, Texture* t, Texture* n, int l, Texture* x);

	// Metodos publicos de la clase
	virtual void render() const;
	virtual void update();
	virtual void loadFromFile(ifstream& loadFile);
	virtual void saveToFile(ofstream& saveFile);
	void resetLife();

};

