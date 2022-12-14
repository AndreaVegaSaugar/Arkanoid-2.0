#include "MenuButton.h"

MenuButton::MenuButton(Vector2D position, int height, int width, Texture* _texture, SDL_Rect bR, CallBack* funct) : GameObject(position, height, width, _texture), function(funct)
{
	  buttonRect.x = position.getX(); buttonRect.y = position.getY(); buttonRect.h = BUTTON_HEIGHT; buttonRect.w = BUTTON_WIDTH;
}

void MenuButton::render() const
{
	texture->renderFrame(getRect(), row, col);
}

void MenuButton::handleEvents() const
{
	SDL_Event event;
	while (SDL_PollEvent(&event)) {  // no estoy segura de este while, maybe hay que pasarle un evento como al del menu
		SDL_Point mousePos;
		SDL_GetMouseState(&mousePos.x, &mousePos.y);
		if (SDL_PointInRect(&mousePos, &buttonRect)) {
			// cambiar fila de la textura, not sure porque es un metodo const
			if (event.type == SDL_MOUSEBUTTONDOWN) {
				//optionButton = 'n';
				// Callback
				// fuction (game)
			}
		}
		if (SDL_PointInRect(&mousePos, &buttonRect)) {
			// cambiar fila de la textura, not sure porque es un metodo const
			if (event.type == SDL_MOUSEBUTTONDOWN) {
				//cout << "Introduce code of your last game: ";
				//cin >> file;
				//optionButton = 'l';
			}
		}
	}
}