#include "Reward.h"

Reward::Reward(Vector2D p, int h, int w, Vector2D d, Texture* t, char tipo) : MovingObject(p, h, w, t, d)
{
	tipeReward = tipo;

	switch (tipeReward) {
		case 'L': { row = 0; col = 0; }break;
		case 'E': { row = 1; col = 0; }break;
		case 'C': { row = 2; col = 0; }break;
		case 'S': { row = 3; col = 0; }break;
	}
}

void Reward::render() const
{
	texture->renderFrame(getRect(), row, col);
}

void Reward::movingAnimation() {

}
void Reward::update() {
	pos = pos + dir;
}
bool Reward::collides(SDL_Rect ballRect, Vector2D& collisionVector) {
	SDL_Rect col;
	return SDL_IntersectRect(&ballRect, &getRect(), &col);
}