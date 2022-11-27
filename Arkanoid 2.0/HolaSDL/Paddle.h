#pragma once
#include "checkML.h"
#include "Vector2D.h"
#include "Texture.h"
#include "Ball.h"
#include "MovingObject.h"

using namespace std;

class Game;
class Paddle : public MovingObject
{
private:
	int rightLimit = 0;
	int leftLimit = 0;
	int speed = 0;
	Game* game = nullptr;
	Ball* ball = nullptr;

public:
	Paddle(Vector2D p, int h, int w, Texture* t, Game* g, Ball* b, Vector2D d, int s, int rL, int lL) : MovingObject(p, h, w, t, d), game(g), ball(b), speed(s), rightLimit(rL), leftLimit(lL) {};
	virtual void update();
	virtual void loadFromFile(string file);
	virtual void saveToFile(ofstream& saveFile);
	void handleEvents(SDL_Event event); // cambiar a singular
	bool collides(SDL_Rect ballRect, Vector2D& collisionVector);
	void setPos(Vector2D p) { pos = p; };
	void setWidth(int width) { w = width; }
	void restartPaddle() { pos = Vector2D((double)((WIN_WIDTH / 2) - 50), (double)WIN_HEIGHT - 100); w = PADDLE_WIDTH; h = PADDLE_HEIGHT; };

protected:
	Vector2D collision(const SDL_Rect& ballRect, const SDL_Rect& collision);
};

