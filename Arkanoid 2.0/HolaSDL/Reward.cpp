#include "Reward.h"

void Reward::setFilCol()
{
	switch (tipeReward) {
	case 'L': { row = 0; col = 0; }break;
	case 'E': { row = 1; col = 0; }break;
	case 'R': { row = 4; col = 0; }break;
	case 'S': { row = 3; col = 0; }break;
	}
}

Reward::Reward(Vector2D p, int h, int w, Vector2D d, Texture* t, char tipo, int tC) : MovingObject(p, h, w, t, d)
{
	tipeReward = tipo;
	totalCol = tC;
	setFilCol();
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
	double x, y;
	loadFile >> x >> y;
	pos = Vector2D(x, y);
	if (loadFile.fail() || x < 0 || y < 0) throw (FileFormatError("Error in reading reward position from save file"));
	char tipo;
	loadFile >> tipo;
	tipeReward = tipo;
	if (loadFile.fail() || tipo == ' ') throw (FileFormatError("Error in reading reward type from save file"));
	setFilCol();
}