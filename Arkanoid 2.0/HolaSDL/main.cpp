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
	try
	{
		Game* game = new Game();
		game->run();
		delete(game);
	}
	catch (exception e)
	{
		cout << e.what();
	}
	return 0;
}