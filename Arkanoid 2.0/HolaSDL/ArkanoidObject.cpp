#include "ArkanoidObject.h"

SDL_Rect ArkanoidObject::getRect()const {
	SDL_Rect destRect;
	destRect.w = w;
	destRect.h = h;
	destRect.x = pos.getX();
	destRect.y = pos.getY();
	
	return destRect;
}

void ArkanoidObject::render() const
{
	texture->render(getRect());
}
