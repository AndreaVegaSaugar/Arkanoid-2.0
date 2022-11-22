#pragma once
#include "checkML.h"
#include "Vector2D.h"
#include "Texture.h"
#include "MovingObject.h"
using namespace std;

class Game;
class Paddle : public MovingObject
{
private:
	int rightLimit;
	int leftLimit;
	int speed;
	Game* game;

public:
	Paddle(Vector2D p, int h, int w, Texture* t, Game* g, int s, int rL, int lL);
	virtual void update();
	virtual void loadFromFile() {};
	virtual void saveToFile() {};
	void handleEvents(SDL_Event event);
	SDL_Rect getDestRect()const;
	bool collides(SDL_Rect ballRect, Vector2D& collisionVector);
	void setPos(Vector2D p) { pos = p; };

protected:
	Vector2D collision(const SDL_Rect& ballRect, const SDL_Rect& collision);
};

