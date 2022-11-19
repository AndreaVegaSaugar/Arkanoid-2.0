#include "checkML.h"
#include "Time.h"
#include <iostream>
#include "Game.h"
Time::Time(Vector2D p, int h, int w, Texture* t, Game* g) {
	pos = p;
	height = h;
	width = w;
	texture = t;
	game = g;
}

Time:: ~Time() {

}
void Time::update(int deltaTime) {
	this->deltaTime = deltaTime;
}

void Time::convertSeconds(int sec, int& row, int& col) {
	switch (sec) {
	case 0: {row = 0; col = 0; }break;
	case 1: {row = 0; col = 1; }break;
	case 2: {row = 0; col = 2; }break;
	case 3: {row = 0; col = 3; }break;
	case 4: {row = 1; col = 0; }break;
	case 5: {row = 1; col = 1; }break;
	case 6: {row = 1; col = 2; }break;
	case 7: {row = 1; col = 3; }break;
	case 8: {row = 2; col = 0; }break;
	case 9: {row = 2; col = 1; }break;
	}
}

void Time::render()
{
	SDL_Rect destRect; SDL_Rect destRectS1; SDL_Rect destRectS2;

	destRectS1 = destRectS2 = destRect = getDestRect();
	destRectS1.x = destRect.x + width;
	destRectS2.x = destRectS1.x + width;
	cout << deltaTime << endl;
	convertSeconds(deltaTime / 100, secondsRow_C, secondsCol_C);
	convertSeconds((deltaTime / 10) % 10, secondsRow_D, secondsCol_D);
	convertSeconds(deltaTime % 10, secondsRow_U, secondsCol_U);

	if (deltaTime == 999) game->GameOver();
	texture->renderFrame(destRect, secondsRow_C, secondsCol_C);
	texture->renderFrame(destRectS1, secondsRow_D, secondsCol_D);
	texture->renderFrame(destRectS2, secondsRow_U, secondsCol_U);

}
SDL_Rect Time::getDestRect() const {
	SDL_Rect destRect;
	destRect.w = width;
	destRect.h = height;
	destRect.x = pos.getX();
	destRect.y = pos.getY();

	return destRect;
}
