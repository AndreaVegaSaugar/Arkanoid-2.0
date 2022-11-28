#include "Reward.h"

Reward::Reward(Vector2D p, int h, int w, Vector2D d, Texture* t, char tipo, int tC) : MovingObject(p, h, w, t, d)
{
	tipeReward = tipo;
	totalCol = tC;

	switch (tipeReward) {
		case 'L': { row = 0; col = 0; }break;
		case 'E': { row = 1; col = 0; }break;
		case 'R': { row = 4; col = 0; }break;
		case 'S': { row = 3; col = 0; }break;
	}
}

void Reward::render() const
{
	texture->renderFrame(getRect(), row, col);
}

void Reward::update() {
	pos = pos + dir;
	col = int(((SDL_GetTicks() / 100) % totalCol));
}
bool Reward::collides(SDL_Rect ballRect, Vector2D& collisionVector) {
	SDL_Rect col;
	return SDL_IntersectRect(&ballRect, &getRect(), &col);
}

void Reward::saveToFile(ofstream& saveFile)
{
	saveFile << "Reward " << pos.getX() << " " << pos.getY() << " " << tipeReward<< endl;

}
void Reward::loadFromFile(ifstream& loadFile)
{
	int x, y;
	loadFile >> x >> y;
	pos = Vector2D(x, y);
	char tipo;
	loadFile >> tipo;
	
	
}