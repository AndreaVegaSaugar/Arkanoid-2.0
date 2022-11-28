#include "Menu.h"
#include "Game.h"
#include <iostream>

Menu::Menu(Texture* tTitle, Texture* tStart, Texture* tLoad, int w, int h, int bH, int bW,  Game* g, Time* t) {

	textureTitle = tTitle;
	textureStart = tStart;
	textureLoad = tLoad;
	rectTitle.x = 0; rectTitle.y = 0; rectTitle.w = w; rectTitle.h = h;
	rectStart.x = 245; rectStart.y = 350; rectStart.w = bW; rectStart.h = bH;
	rectLoad.x = 230; rectLoad.y = 200; rectLoad.w = bW; rectLoad.h = bH;
	game = g;
	timer = t;
}
void Menu::render(){
	
	textureTitle->render(rectTitle);
	textureStart->render(rectStart);
	textureLoad->render(rectLoad);
	
}

void Menu::handleEvents(SDL_Event event, bool& click) {
	SDL_Point mousePos;
	SDL_GetMouseState(&mousePos.x, &mousePos.y);
	if (SDL_PointInRect(&mousePos, &rectStart) && event.type == SDL_MOUSEBUTTONDOWN) {
		game->newGame();
		click = true;
	}
	if (SDL_PointInRect(&mousePos, &rectLoad) && event.type == SDL_MOUSEBUTTONDOWN) {
		cout << "Introduce code of your last game: ";;
		string file;
		cin >> file;
		game->loadGame(file);
		click = true;

	}
	if (event.type == SDL_QUIT) click = true;
}