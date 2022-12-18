#include "checkML.h"
#include "Block.h"
#include "PlayState.h"

using namespace std;

// Constructora de la clase
Block::Block(Vector2D p, int h, int w, int c, Texture* t, PlayState* g) : ArkanoidObject(p, h, w, t)
{
	color = c;
	game = g;

	switch (color) { // Ajustamos la fila y columna de la textura segun el color del bloque
	case 1: { row = 0; col = 0; }break;
	case 2: { row = 0; col = 1; }break;
	case 3: { row = 0; col = 2; }break;  
	case 4: { row = 1; col = 0; }break;
	case 5: { row = 1; col = 1; }break;
	case 6: { row = 1; col = 2; }break;
	}
}

// Renderiza el bloque segun su fila y columna
void Block::render() const
{
	texture->renderFrame(getRect(), row, col);
}

// Devuelve el rectangulo destino del bloque
SDL_Rect Block::getRect() const
{
	SDL_Rect destRect;
	destRect.w = w;
	destRect.h = h;
	destRect.x = (pos.getX() * w) + game->getWallSize();
	destRect.y = (pos.getY() * h) + game->getWallSize();

	return destRect;
}