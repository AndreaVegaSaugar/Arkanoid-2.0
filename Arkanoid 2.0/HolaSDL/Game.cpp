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
	gameStateMachine->pushState(new MainMenuState(this));
}

//Destructora de la clase
Game::~Game() {
	for (uint i = 0; i < NUM_TEXTURES; ++i) delete textures[i];
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

void Game::run()
{
	uint32_t startTime, frameTime;
	startTime = SDL_GetTicks();
	while (!exit)
	{
		handleEvents();
		frameTime = SDL_GetTicks() - startTime;
		if (frameTime >= FRAME_RATE) {
			update();
			startTime = SDL_GetTicks();
		}
		render();
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

void Game::handleEvents() {
	SDL_Event event;
	while (SDL_PollEvent(&event) && !exit) {
		gameStateMachine->currentState()->handleEvent(event);
		if (event.type == SDL_QUIT)
			exit = true;
	}
}