#include "MenuButton.h"
#include "Game.h"

// Constructora de la clase, que asigna la funcion que realizara el boton segun el metdo callback que recibe
MenuButton:: MenuButton(Game* _game,Vector2D position, int height, int width, Texture* _texture, void(*_callback) (Game* game)) :
	GameObject(position, height, width, _texture) {
	pos = position;
	h = height;
	w = width;
	texture = _texture;
	callback = _callback;
	g = _game;
}

// Renderiza el boton en pantalla segun su estado (pulsado / no pulsado)
void MenuButton::render() const
{
	 texture->renderFrame(getRect(), 0, current);
}

// Cambia el estado del boton si el raton pasa por encima y llama a su metodo callback si es pulsado
void MenuButton::handleEvent(SDL_Event event)
{
	SDL_Point mousePos;
	SDL_GetMouseState(&mousePos.x, &mousePos.y);
	if (SDL_PointInRect(&mousePos, &getRect())) {
		// cambiar fila de la textura, not sure porque es un metodo const
		if (event.type == SDL_MOUSEBUTTONDOWN) {
			callback(g);
		}
		current = pointed;
	}
	else current = notPointed;
}