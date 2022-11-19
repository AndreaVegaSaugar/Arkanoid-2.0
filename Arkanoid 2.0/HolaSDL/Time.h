#pragma once
#include "checkML.h"
#include "Vector2D.h"
#include "Texture.h"

class Game;
class Time
{
private:
	Vector2D pos;
	unsigned int height = 0;
	unsigned int width = 0;
	Texture* texture = nullptr;
	int deltaTime = 0;
	int secondsRow_C = 0;
	int secondsCol_C = 0;
	int secondsRow_D = 0;
	int secondsCol_D = 0;
	int secondsRow_U = 0;
	int secondsCol_U = 0;
	Game* game;

public:
	Time() {};
	Time(Vector2D p, int h, int w, Texture* t, Game* g);

	void render();
	void update(int dT);
	void convertSeconds(int sec, int& row, int& col);
	SDL_Rect Time::getDestRect() const;
	~Time();

};