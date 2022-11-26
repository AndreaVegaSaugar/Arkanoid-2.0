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
	Paddle(Vector2D p, int h, int w, Texture* t, Game* g, Vector2D d, int s, int rL, int lL) : MovingObject(p, h, w, t, d), game(g), speed(s), rightLimit(rL), leftLimit(lL) {};
	virtual void update();
	virtual void loadFromFile();
	virtual void saveToFile();
	void handleEvents(SDL_Event event); // cambiar a singular
	bool collides(SDL_Rect ballRect, Vector2D& collisionVector);
	void setPos(Vector2D p) { pos = p; };
	void setWidth(int width) { w = width; }
	void restartPaddle() { pos = Vector2D((double)((WIN_WIDTH / 2) - 50), (double)WIN_HEIGHT - 100); w = PADDLE_WIDTH; h = PADDLE_HEIGHT; };

protected:
	Vector2D collision(const SDL_Rect& ballRect, const SDL_Rect& collision);
};

