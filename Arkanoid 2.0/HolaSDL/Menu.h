#pragma once
#include "Texture.h"
#include "Vector2D.h"
#include "Time.h"
#include "GameObject.h"

// Clase MENU que hereda de GAMEOBJECT
class PlayState;
class Menu: public GameObject
{
private:
	Texture* textureTitle = nullptr;
	Texture* textureStart = nullptr;
	Texture* textureLoad = nullptr;
	
	SDL_Rect rectTitle;
	SDL_Rect rectStart;
	SDL_Rect rectLoad;

	PlayState* game = nullptr;
	Time* timer = nullptr;


public:
	// Constructoras de la clase
	Menu() : GameObject(){}
	Menu(Texture* tTitle, Texture* tStart, Texture* tLoad, int w, int h, int bH, int bW, PlayState* g, Time* t);

	// Metodos publicos de la clase
	virtual void render() const;
	virtual void handleEvents(SDL_Event event, string& file, char& optionButton);
};

