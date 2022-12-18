#include "ArkanoidObject.h"

// Metodo render generico que usan los Arkanoid Objects
void ArkanoidObject::render() const
{
	texture->render(getRect());
}
