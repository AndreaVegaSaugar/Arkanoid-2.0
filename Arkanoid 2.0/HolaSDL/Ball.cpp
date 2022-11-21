#include "checkML.h"
#include "Ball.h"
#include "Game.h"

 void Ball::update()
{
	Vector2D colVector;
	if (game->collides(getRect(), colVector))
	{
		colVector.normalize();
		dir = dir - colVector * (2 * (dir * colVector));
	}
	pos = pos + dir;
}

