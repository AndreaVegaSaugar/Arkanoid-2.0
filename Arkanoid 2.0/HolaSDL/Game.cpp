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
	gameStateMachine = new GameStateMachine();
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
	uint32_t startTime, frameTime;
	while (!exit)
	{
		if (gameStateMachine->currentState() != nullptr) {
			startTime = SDL_GetTicks();
			gameStateMachine->currentState()->handleEvents();
		}
	}
}
void Game::render() const
{
	SDL_RenderClear(renderer);
	gameStateMachine->currentState()->render();
	SDL_RenderPresent(renderer);
}
void Game::update()
{
	gameStateMachine->currentState()->update();
}