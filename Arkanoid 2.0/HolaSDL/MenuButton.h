#pragma once
#include "GameObject.h"
#include "ArkanoidObject.h"
#include "checkML.h"

class Game;
// Clase MENUBUTTON	que hereda de GAMEOBJECT
class MenuButton : public GameObject
{
	// Enum de estados del boton (pulsado / no pulsado)
	enum States {
		notPointed = 0,
		pointed = 1,
	};
private:
	void (*callback) (Game* game);
	int pointer = 0;
	Game* g;
	int current = notPointed;
	

public:
	
	// Constructora de la clase
	MenuButton(Game* _game, Vector2D position, int height, int width, Texture* _texture, void(*_callback) (Game* game));

	// Metodos publicos de la clase
	virtual void render() const;
	virtual void handleEvent(SDL_Event event);
	
};

