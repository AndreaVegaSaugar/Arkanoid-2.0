#include "MenuButton.h"
#include "Game.h"

MenuButton:: MenuButton(Game* _game,Vector2D position, int height, int width, Texture* _texture, void(*_callback) (Game* game)) :
	GameObject(position, height, width, _texture) {
	pos = position;
	h = height;
	w = width;
	texture = _texture;
	callback = _callback;
	g = _game;
}

void MenuButton::render() const
{
	texture->renderFrame(getRect(), row, col);
}

void MenuButton::handleEvent() const
{
	SDL_Event event;
	while (SDL_PollEvent(&event)) {  // no estoy segura de este while, maybe hay que pasarle un evento como al del menu
		SDL_Point mousePos;
		SDL_GetMouseState(&mousePos.x, &mousePos.y);
		if (SDL_PointInRect(&mousePos, &getRect())) {
			// cambiar fila de la textura, not sure porque es un metodo const
			if (event.type == SDL_MOUSEBUTTONDOWN) {
				callback(g);
			}
			
		}
	}
}