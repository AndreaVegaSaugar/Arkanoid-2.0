#include "SDL.h"
#include "SDL_image.h"
#include "checkML.h"
#include <iostream>
#include <windows.h>
#include "Game.h"
#undef main
using namespace std;

/*
IDEA DE SAVE/LOAD FILE: crear un nuevo metodo en la clase game aparte de la constructora que 
contiene todos los metodos LOADFROMFILE. Crear en la clase main un metodo menú que pregunte
al usuario si desea cargar partida y si es asi, despues de llamar a la construcora del game
se llamaria a ese metodo para que cambie los valores correspondientes de los objetos guardados.
*/


int main(int argc, char* argv[]) 
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF); // Check Memory Leaks
	Game* game = new Game();
	cout << "Welcome to ";
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 14);
	cout << "ARKANOID 2.0";
	SetConsoleTextAttribute(hConsole, 7);

	cout << "!" << endl << "Do you want to start a new game or load your previous one?";
	game->run();
	delete(game);
	return 0;
}