#include "checkML.h"
#include "Paddle.h"
#include"Game.h"
#include <iostream>
using namespace std;

Paddle::Paddle(Vector2D p, int w, int h, Texture* t, Game* g, int s, int rL, int lL) : MovingObject(p, h, w, t, Vector2D(0,0))
{
	game = g;
	speed = s;
	rightLimit = rL;
	leftLimit = lL;
}


void Paddle::update()
{
	if (pos.getX() + w > leftLimit && pos.getX() < rightLimit) {
		pos = Vector2D(pos.getX() + (dir.getX() * speed), pos.getY());
	}

	if (pos.getX() <= leftLimit) {
		pos = Vector2D(leftLimit, pos.getY());
	}
	else if (pos.getX() + w >= rightLimit) {
		pos = Vector2D(rightLimit - w, pos.getY());
	}
}

void Paddle::handleEvents(SDL_Event event)
{
	if (event.type == SDL_KEYDOWN) {
		cout << "Key down" << endl;
		if (event.key.keysym.sym == SDLK_LEFT) dir = Vector2D(-1, 0);
		else if (event.key.keysym.sym == SDLK_RIGHT)dir = Vector2D(1, 0);
	}
	else {
		dir = Vector2D(0, 0);
	}
}


bool Paddle::collides(SDL_Rect ballRect, Vector2D& collisionVector) {
	SDL_Rect col;
	bool collide = false;

	if (SDL_IntersectRect(&ballRect, &getRect(), &col)) {
		collisionVector = collision(ballRect, col);
		collide = true;
	}
	return collide;
}

Vector2D Paddle::collision(const SDL_Rect& ballRect, const SDL_Rect& collision) {

	Vector2D colVect = Vector2D(0, 0);

	float ballCenterX = ballRect.x + (0.5f * ballRect.w);
	float ballCenterY = ballRect.y + (0.5f * ballRect.h);

	float paddleCenterX = pos.getX() + (w / 2);
	float paddleCenterY = pos.getY() + (h / 2);

	if (ballCenterY < paddleCenterY) {
		colVect = Vector2D(-(collision.x - pos.getX() - (w / 2)) / (w / 2), 2.5);
		colVect.normalize();
	}
	else if (ballCenterX < pos.getX()) colVect = Vector2D(-1, 0);
	else if (ballCenterX > (pos.getX() + w)) colVect = Vector2D(1, 0);

	return colVect;

}