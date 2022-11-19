#include "checkML.h"
#include "Wall.h"

using namespace std;

// Llama a renderizar la textura
void Wall::render() const
{
	SDL_Rect destRect = getRect();
	texture->render(destRect);
}

// Devuelve el vector de colision de la pelota con la pared y devuelve true en caso de producirse
bool Wall::collides(SDL_Rect ballRect, Vector2D& collisonVector)
{
	collisonVector = colVector;
	return SDL_HasIntersection(&ballRect, &getRect());
}
