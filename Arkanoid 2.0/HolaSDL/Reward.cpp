#include "Reward.h"
#include "Game.h"

Reward::Reward(Vector2D p, int h, int w, Vector2D d, Texture* t, char tipo, int tC, Game* g) : MovingObject(p, h, w, t, d)
{
	tipeReward = tipo;
	totalCol = tC;
	game = g;
	switch (tipeReward) {
		case 'L': { row = 0; col = 0; }break;
		case 'E': { row = 1; col = 0; }break;
		case 'R': { row = 4; col = 0; }break;
		case 'S': { row = 3; col = 0; }break;
		case 'C': { row = 2; col = 0; }break;
		case 'B': { row = 7; col = 0; }break;
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
bool Reward::collides(SDL_Rect ballRect) {
	SDL_Rect col;
	if (SDL_IntersectRect(&ballRect, &getRect(), &col)) {
		game->rewardType(tipeReward);
		return true;

	}
	else if (getRect().y + getRect().h >= WIN_HEIGHT) return true;
	else return false;
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