#include "checkML.h"
#include "Block.h"
#include "Game.h"
using namespace std;

Block::Block(Vector2D p, int w, int h, int c, Texture* t, Game* g) : ArkanoidObject(p, w, h, t)
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
	SDL_Rect destRect = getRect();
	destRect.x += game->getWallSize();
	destRect.y += game->getWallSize();
	texture->renderFrame(destRect, row, col);
}
