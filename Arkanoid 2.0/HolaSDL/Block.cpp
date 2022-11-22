#include "checkML.h"
#include "Block.h"
#include "Game.h"

using namespace std;

Block::Block(Vector2D p, int h, int w, int c, Texture* t, Game* g) : ArkanoidObject(p, h, w, t)
{
	color = c;
	game = g;

	switch (color) {
	case 1: { row = 0; col = 0; }break;
	case 2: { row = 0; col = 1; }break;
	case 3: { row = 0; col = 2; }break;
	case 4: { row = 1; col = 0; }break;
	case 5: { row = 1; col = 1; }break;
	case 6: { row = 1; col = 2; }break;
	}
}

void Block::render() const
{
	texture->renderFrame(getRect(), row, col);
}

SDL_Rect Block::getRect() const
{
	SDL_Rect destRect;
	destRect.w = w;
	destRect.h = h;
	destRect.x = (pos.getX() * w) + game->getWallSize();
	destRect.y = (pos.getY() * h) + game->getWallSize();

	return destRect;
}