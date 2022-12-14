#include "checkML.h"
#include "Time.h"
#include <iostream>
#include "PlayState.h"

// Resetea el tiempo
void Time::resetTime()
{
	deltaTime = 0;
	secondsRow_U = 0;
	secondsCol_U = 0;
	secondsRow_D = 0;
	secondsCol_D = 0;
	secondsRow_C = 0;
	secondsCol_C = 0;
}

// Actualiza el tiempo
void Time::update() 
{
	if (deltaTime >= 999) game->timeLimit();
	deltaTime = (SDL_GetTicks() / 1000) + extra;
	convertSeconds(deltaTime / 100, secondsRow_C, secondsCol_C);
	convertSeconds((deltaTime / 10) % 10, secondsRow_D, secondsCol_D);
	convertSeconds(deltaTime % 10, secondsRow_U, secondsCol_U);
	render(); 
}

// Asigna una fila y columna de la textura segun los segundos
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

// Renderiza el tiempo
void Time::render() const
{
	SDL_Rect destRect; SDL_Rect destRectS1; SDL_Rect destRectS2;

	destRectS1 = destRectS2 = destRect = getRect();
	destRectS1.x = destRect.x + w;
	destRectS2.x = destRectS1.x + w;

	texture->renderFrame(destRect, secondsRow_C, secondsCol_C);
	texture->renderFrame(destRectS1, secondsRow_D, secondsCol_D);
	texture->renderFrame(destRectS2, secondsRow_U, secondsCol_U);
}

// Guarda los datos relevantes del objeto
void Time::saveToFile(ofstream& saveFile)
{
	saveFile << "Time " << deltaTime << endl;
}

// Lee de archivo los datos relevantes del objeto y los modifica
void Time::loadFromFile(ifstream& loadFile)
{
	int time;
	loadFile >> time;
	extra = time;
	if (loadFile.fail() || extra < 0) throw (FileFormatError("Error in reading time from save file"));
}

// Cambia el tiempo
void Time::changeTime(int newTime) {
	extra -= newTime;
}