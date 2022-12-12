#include "Game.h"
#include <iostream>
#include "checkML.h"
#include <time.h>
#include <random>

using namespace std;

Game::Game() {
	// We first initialize SDL
	SDL_Init(SDL_INIT_EVERYTHING);
	window = SDL_CreateWindow("Arkanoid", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		WIN_WIDTH, WIN_HEIGHT, SDL_WINDOW_SHOWN);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (window == nullptr || renderer == nullptr) throw (SDLError(SDL_GetError()));

	//Nos creamos las texturas
	for (uint i = 0; i < NUM_TEXTURES; ++i)
	{
		try {
			textures[i] = new Texture(renderer, texture[i].filename, texture[i].rows, texture[i].cols);
		}
		catch (SDLError e) {
			throw e;
		}
	}

	

}

//Destructora de la clase
Game::~Game() {
	for (uint i = 0; i < NUM_TEXTURES; ++i) delete textures[i];
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

// Bucle principal del juego, que incluye un manejo basico del tiempo
void Game::run()
{
	while (!exit)
	{
		//	uint32_t startTime, frameTime;
		//	menuWindow = Menu(textures[Title], textures[Start], textures[Load], WIN_WIDTH, WIN_HEIGHT, BUTTON_HEIGHT, BUTTON_WIDTH, this, timer);
		//	startTime = SDL_GetTicks();
		//	while (!exit) { // Bucle del juego
		//		handleEvents();
		//		if (CurrentState != pause) {

		//			frameTime = SDL_GetTicks() - startTime; // Tiempo desde última actualización
		//			if (frameTime >= FRAME_RATE) {
		//				update(); // Actualiza el estado de todos los objetos del juego
		//				startTime = SDL_GetTicks();
		//			}
		//			render(); // Renderiza todos los objetos del juego
		//		}
		//	}
		//}
	}
}
// Actualiza el estado del juego y todos sus GameObjects segun el estado
void Game::update() 
{
	/*if (CurrentState == win && level < (NUM_LEVELS - 1)) nextLevel();
	else if (CurrentState == lose && life->lives > 1) restartLevel();
	else if (CurrentState == play)
	{
		for (auto it = gameObjects.begin(); it != gameObjects.end();) {
			(*it)->update();
			if (*it == nullptr) it = gameObjects.erase(it);
			else ++it;
		}
	}*/
}

// Renderiza todos los GameObjects y texturas correspondientes segun el estado del juego
void Game::render() {
	SDL_RenderClear(renderer); 

	/*if (CurrentState == win && level >= (NUM_LEVELS - 1))
	{
		SDL_Rect rect;
		rect.x = 0; rect.y = 0;
		rect.w = WIN_WIDTH; rect.h = WIN_HEIGHT;
		textures[YouWinTx]->render(rect);
	}
	else if (CurrentState == lose && life->lives <= 1)
	{
		SDL_Rect rect;
		rect.x = 0; rect.y = 0;
		rect.w = WIN_WIDTH; rect.h = WIN_HEIGHT;
		textures[GameOverTx]->render(rect);
	}
	else if (CurrentState == menu) {
		menuWindow.render();
	}
	else
	{
		for (auto it = gameObjects.begin(); it != gameObjects.end(); ++it) {
			(*it)->render();
		}
	}*/
	SDL_RenderPresent(renderer);
}

// Controlar los eventos del juego segun el estado de este
void Game::handleEvents() {
	/*SDL_Event event;
	while (SDL_PollEvent(&event) && !exit) {
		if (event.type == SDL_QUIT) exit = true;
		if ((CurrentState == play || CurrentState == pause) && event.type == SDL_KEYDOWN) {
			if (event.key.keysym.sym == SDLK_s) {
				string saveCode;
				cout << "Introduce the code to save game: ";
				cin >> saveCode;
				saveToFile(saveCode);
			}
			if (event.key.keysym.sym == SDLK_p && CurrentState != pause) CurrentState = pause;
			else if (event.key.keysym.sym == SDLK_p && CurrentState == pause) CurrentState = play;
		}
		else if (CurrentState == menu) {
			string file;
			char optionButton;
			menuWindow.handleEvents(event, file, optionButton);
			if (optionButton == 'n') newGame();
			else if (optionButton == 'l')
			{
				try{
					loadGame(file);
				}
				catch (FileFormatError e) {
					cout << e.what() << endl;
				}
				catch (FileNotFoundError e) {
					cout << e.what() << endl;
					cout << "We couldn't find a save file with that name so we will start a new game for you";
					newGame();
				}
			}
		}
		if(CurrentState == play) paddle->handleEvents(event);
	}*/
}
