#include "Reward.h"
#include "Game.h"

// Asigna frame de la textura segun el tipo de reward
void Reward::setFilCol()
{
	switch (tipeReward) {
	case 'L': { row = 0; col = 0; }break;
	case 'E': { row = 1; col = 0; }break;
	case 'R': { row = 4; col = 0; }break;
	case 'S': { row = 3; col = 0; }break;
	case 'D': { row = 6; col = 0; }break;
	}
}

// Constructora de la clase
Reward::Reward(Vector2D p, int h, int w, Vector2D d, Texture* t, char tipo, int tC, Game* g, int s) : MovingObject(p, h, w, t, d, s)
{
	tipeReward = tipo;
	totalCol = tC;
	game = g;
	setFilCol();
}

// Renderiza lod rewards
void Reward::render() const
{
	texture->renderFrame(getRect(), row, col);
}

// Actualiza la posicion y la animacion de los rewards
void Reward::update() {
	move();
	col = int(((SDL_GetTicks() / 100) % totalCol));
}

// Controla las colisiones de los rewards
bool Reward::collides(SDL_Rect ballRect) {
	SDL_Rect col;
	if (SDL_IntersectRect(&ballRect, &getRect(), &col)) {
		game->rewardType(tipeReward);
		return true;
	}
	else if (getRect().y + getRect().h >= WIN_HEIGHT) return true;
	else return false;
}

// Guarda los datos relevantes del objeto
void Reward::saveToFile(ofstream& saveFile)
{
	saveFile << "Reward " << pos.getX() << " " << pos.getY() << " " << tipeReward<< endl;
}

// Lee de archivo los datos relevantes del objeto y los modifica
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