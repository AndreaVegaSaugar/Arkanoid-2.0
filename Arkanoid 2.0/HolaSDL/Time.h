#pragma once
#include "checkML.h"
#include "Vector2D.h"
#include "Texture.h"
#include "ArkanoidObject.h"

class PlayState;
class Time: public ArkanoidObject
{
private:
	int deltaTime = 0;
	int extra = 0;
	int secondsRow_C = 0;
	int secondsCol_C = 0;
	int secondsRow_D = 0;
	int secondsCol_D = 0;
	int secondsRow_U = 0;
	int secondsCol_U = 0;
	PlayState* game = nullptr;

public:
	Time(){}
	Time(Vector2D p, int h, int w, Texture* t, PlayState* g):ArkanoidObject(p, h, w, t), game(g){}

	void resetTime();
	virtual void render() const;
	virtual void update();
	void convertSeconds(int sec, int& row, int& col);
	virtual void loadFromFile(ifstream& loadFile);
	virtual void saveToFile(ofstream& saveFile);
	void changeTime(int time);
	~Time() {};

};