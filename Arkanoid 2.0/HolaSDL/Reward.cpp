#include "Reward.h"

Reward:: Reward(Vector2D p, int h, int w, Vector2D d, Texture* t, int tipo) : MovingObject(p, h, w, t, d)
{
	tipoReward = tipo;

	switch (tipo) {
	case 1: { row = 0; col = 0; }break;
	case 2: { row = 1; col = 0; }break;
	case 3: { row = 2; col = 0; }break;
	case 4: { row = 3; col = 0; }break;
	case 5: { row = 4; col = 0; }break;
	case 6: { row = 5; col = 0; }break;
	case 7: { row = 6; col = 0; }break;
	case 8: { row = 7; col = 0; }break;
	case 9: { row = 8; col = 0; }break;
	case 10: { row = 9; col = 0; }break;
	}
}

void Reward::movingAnimation() {

}
