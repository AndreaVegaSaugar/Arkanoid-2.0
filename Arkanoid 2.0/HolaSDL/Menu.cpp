#include "Menu.h"
#include "Game.h"
#include <iostream>

Menu::Menu(Texture* tTitle, Texture* tStart, Texture* tLoad, int w, int h, int bH, int bW,  Game* g, Time* t): GameObject() {

	textureTitle = tTitle;
	textureStart = tStart;
	textureLoad = tLoad;
	rectTitle.x = 0; rectTitle.y = 0; rectTitle.w = w; rectTitle.h = h;
	rectStart.x = 245; rectStart.y = 350; rectStart.w = bW; rectStart.h = bH;
	rectLoad.x = 245; rectLoad.y = 200; rectLoad.w = bW; rectLoad.h = bH;
	game = g;
	timer = t;
}
void Menu::render() const {
	
	textureTitle->render(rectTitle);
	textureStart->render(rectStart);
	textureLoad->render(rectLoad);
	
}

void Menu::handleEvents(SDL_Event event, bool& click, bool& exit, string& file, char& optionButton) {
	SDL_Point mousePos;
	SDL_GetMouseState(&mousePos.x, &mousePos.y);
	if (SDL_PointInRect(&mousePos, &rectStart) && event.type == SDL_MOUSEBUTTONDOWN) {
		cout << "pulse start";
		click= true;
		optionButton = 'n';
	}
	if (SDL_PointInRect(&mousePos, &rectLoad) && event.type == SDL_MOUSEBUTTONDOWN) {
		cout << "Introduce code of your last game: ";
		try
		{
			cin >> file;
			click = true;
			optionButton = 'l';
		}
		catch (exception)
		{
			throw("aaaaaaaaaaaaaa");  // PREGUNTAR EXCEPCIONES EN GENERAL
		}
	}
	if (event.type == SDL_QUIT) exit = true;
}