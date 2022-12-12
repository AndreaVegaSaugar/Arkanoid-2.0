#pragma once
#include "checkML.h"
#include "Vector2D.h"
#include "Texture.h"
#include "MovingObject.h"
using namespace std;

// Clase REWARD que hereda de MOVINGOBJECT
class PlayState;
class Reward : public MovingObject
{
private:
	char tipeReward;
	int row = 0;
	int col = 0;
	int totalCol = 0;
	PlayState* game;

public:
	// Constructora de la clase
	Reward(Vector2D p, int h, int w, Vector2D d, Texture* t, char tipo, int tC, PlayState* g, int s);
	
	// Getters
	Vector2D getDir() { return dir; }
	void getTipe(char& c) { c = tipeReward; }
	
	// Metodos publicos de la clase
	virtual void update();
	virtual void render() const;
	virtual void loadFromFile(ifstream& loadFile);
	virtual void saveToFile(ofstream& saveFile);
	bool collides(SDL_Rect ballRect);
protected:
	void setFilCol();
};