#pragma once
#include "Texture.h"
#include "Vector2D.h"
#include "Time.h"

class Game;
class Menu
{
private:
	Texture* textureTitle = nullptr;
	Texture* textureStart = nullptr;
	Texture* textureLoad = nullptr;
	
	SDL_Rect rectTitle;
	SDL_Rect rectStart;
	SDL_Rect rectLoad;

	Game* game = nullptr;
	Time* timer = nullptr;


public:
	Menu(){}
	Menu(Texture* tTitle, Texture* tStart, Texture* tLoad, int w, int h, int bH, int bW, Game* g, Time* t);
	void render();
	void handleEvents(SDL_Event event, bool& click);
};

