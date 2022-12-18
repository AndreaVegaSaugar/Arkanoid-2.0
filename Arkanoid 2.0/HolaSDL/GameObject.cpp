#include "GameObject.h"

// Metodo generico getRect que heredan los GameObjects
SDL_Rect GameObject::getRect()const {

	SDL_Rect destRect;
	destRect.w = w;
	destRect.h = h;
	destRect.x = pos.getX();
	destRect.y = pos.getY();

	return destRect;
}