// Claudia Zarzuela Amor
// Andrea Vega Saugar

#include "SDL.h"
#include "SDL_image.h"
#include "checkML.h"
#include <iostream>
#include <windows.h>
#include "Game.h"
#undef main

using namespace std;

// Llama a la constructora de GAME, a su bucle principal y controla excepciones
int main(int argc, char* argv[]) 
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF); // Check Memory Leaks

	// Bucle principal del juego con control de excepciones
	try
	{
		Game* game = new Game();
		game->run();
		delete(game);
	}
	catch (exception e) // Todos los fallos posibles son irrecuperables (excepto uno que ya esta controlado) y por tanto el comportamiento sera el mismo para todos por lo que no hacemos distincion entre excepciones
	{
		cout << e.what();
	}
	return 0;
}