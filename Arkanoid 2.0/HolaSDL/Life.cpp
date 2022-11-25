#include "Life.h"

Life::Life(Vector2D p, int h, int w, Texture* t, int l, Texture* he, Texture* x) : ArkanoidObject(p, h, w, t)
{
	life = l;
	heart = he;
	this->x = x;
	switch (life) {
	case 0: row = 0; col = 0; break;
	case 1: row = 0; col = 1; break;
	case 2: row = 0; col = 2; break;
	case 3: row = 0; col = 3; break;
	case 4: row = 1; col = 0; break;
	case 5: row = 1; col = 1; break;
	case 6: row = 1; col = 2; break;
	case 7: row = 1; col = 3; break;
	case 8: row = 2; col = 0; break;
	case 9: row = 2; col = 1; break;
	}
}
void Life::render() const
{
	heart->render(getRect());
	x->render(getRect());
	texture->renderFrame(getRect(), row, col);

}
