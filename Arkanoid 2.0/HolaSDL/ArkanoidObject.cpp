#include "ArkanoidObject.h"

// Devuelve el rectangulo destino
SDL_Rect ArkanoidObject::getRect()const {

	SDL_Rect destRect;
	destRect.w = w;
	destRect.h = h;
	destRect.x = pos.getX();
	destRect.y = pos.getY();
	
	return destRect;
}

// Renderiza el rectangulo destino
void ArkanoidObject::render() const
{
	texture->render(getRect());
}
