#include "ArkanoidObject.h"
SDL_Rect ArkanoidObject::getRect()const {
	SDL_Rect destRect;
	destRect.w = w;
	destRect.h = h;
	destRect.x = pos.getX();
	//destRect.x = (pos.getX() * w);
	destRect.y = pos.getY();
	//destRect.y = (pos.getY() * h);

	return destRect;
}
