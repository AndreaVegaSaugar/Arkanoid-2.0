#pragma once
#include "checkML.h"
#include "Vector2D.h"
#include "Texture.h"
#include "ArkanoidObject.h"

class Game;
class Time: public ArkanoidObject
{
private:
	int deltaTime = 0;
	int secondsRow_C = 0;
	int secondsCol_C = 0;
	int secondsRow_D = 0;
	int secondsCol_D = 0;
	int secondsRow_U = 0;
	int secondsCol_U = 0;
	Game* game = nullptr;

public:
	Time(Vector2D p, int h, int w, Texture* t, Game* g):ArkanoidObject(p, h, w, t), game(g){}

	void resetTime();
	virtual void render() const;
	virtual void update();
	void convertSeconds(int sec, int& row, int& col);
	virtual void loadFromFile(string file) {};
	virtual void saveToFile() {};
	~Time();

};