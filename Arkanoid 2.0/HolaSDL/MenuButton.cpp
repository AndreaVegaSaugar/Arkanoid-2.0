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
void MenuButton::update() {
	if (pointer == 0) col = 0;
	else col = 1;
}
void MenuButton::handleEvent(SDL_Event event)
{
	SDL_Point mousePos;
	SDL_GetMouseState(&mousePos.x, &mousePos.y);
	if (SDL_PointInRect(&mousePos, &getRect())) {
		cout << "tocando";
		// cambiar fila de la textura, not sure porque es un metodo const
		if (event.type == SDL_MOUSEBUTTONDOWN) {
			cout << "click";
			callback(g);
		}
		pointer = 1;
	}
	pointer = 0;
}