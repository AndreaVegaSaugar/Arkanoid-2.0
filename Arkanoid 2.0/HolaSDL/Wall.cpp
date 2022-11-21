#include "checkML.h"
#include "Wall.h"

using namespace std;

// Devuelve el vector de colision de la pelota con la pared y devuelve true en caso de producirse
bool Wall::collides(SDL_Rect ballRect, Vector2D& collisonVector)
{
	collisonVector = colVector;
	return SDL_HasIntersection(&ballRect, &getRect());
}
