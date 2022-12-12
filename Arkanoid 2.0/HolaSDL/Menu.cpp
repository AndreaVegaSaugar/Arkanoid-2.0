#include "Menu.h"
#include "PlayState.h"
#include <iostream>

// Constructora de la clase
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

// Renderiza los elementos del menu en pantalla
void Menu::render() const {
	
	textureTitle->render(rectTitle);
	textureStart->render(rectStart);
	textureLoad->render(rectLoad);
}

// Detecta los clicks del raton y si se producen en los botones
void Menu::handleEvents(SDL_Event event, string& file, char& optionButton) {
	SDL_Point mousePos;
	SDL_GetMouseState(&mousePos.x, &mousePos.y);
	if (SDL_PointInRect(&mousePos, &rectStart) && event.type == SDL_MOUSEBUTTONDOWN) {
		optionButton = 'n';
	}
	if (SDL_PointInRect(&mousePos, &rectLoad) && event.type == SDL_MOUSEBUTTONDOWN) {
		cout << "Introduce code of your last game: ";
		cin >> file;
		optionButton = 'l';
	}
}