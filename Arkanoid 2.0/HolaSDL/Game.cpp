#include "Game.h"
#include <iostream>
#include "checkML.h"
using namespace std;
//Game::Game() {
//	// We first initialize SDL
//	SDL_Init(SDL_INIT_EVERYTHING);
//	window = SDL_CreateWindow("Arkanoid", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
//		WIN_WIDTH, WIN_HEIGHT, SDL_WINDOW_SHOWN);
//	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
//	if (window == nullptr || renderer == nullptr) throw string("Error loading SDL window or renderer");
//
//	//Nos creamos las texturas
//	for (uint i = 0; i < NUM_TEXTURES; ++i)
//	{
//		try {
//			textures[i] = new Texture(renderer, texture[i].filename, texture[i].rows, texture[i].cols);
//		}
//		catch (string e) {
//			throw e;
//		}
//	}
//
//	//Creamos las paredes
//	wall[0] = Wall(Vector2D(0, WALL_WIDTH), WIN_HEIGHT, WALL_WIDTH, textures[SideWallTx], Vector2D(1, 0));
//	wall[1] = Wall(Vector2D(WIN_WIDTH - WALL_WIDTH, WALL_WIDTH), WIN_HEIGHT, WALL_WIDTH, textures[SideWallTx], Vector2D(-1, 0));
//	wall[2] = Wall(Vector2D(0, 0), WALL_WIDTH, WIN_WIDTH, textures[TopWallTx], Vector2D(0, 1));
//
//	//Creamos la bola
//	ball = new Ball(Vector2D((double)WIN_WIDTH / 2, (double)WIN_HEIGHT / 2), BALL_SIZE, Vector2D(1, -1), textures[BallTx], this);
//
//	//Creamos el paddle
//	paddle = new Paddle(Vector2D((double)WIN_WIDTH / 2, (double)WIN_HEIGHT - 100), PADDLE_WIDTH, PADDLE_HEIGHT, textures[PaddleTx], this, 2, MAP_WIDTH + WALL_WIDTH, WALL_WIDTH);
//
//	//Creamos el mapa
//	map = new BlocksMap(MAP_WIDTH, MAP_HEIGHT, textures[BrickTx], this);
//	try {
//		map->loadMap(levels[level]);
//	}
//	catch (string e) {
//		throw e;
//	}
//
//	//Creamos timer
//	time = Time(Vector2D(WALL_WIDTH, WIN_HEIGHT - 50), TIME_HEIGHT, TIME_WIDTH, textures[NumsTx], this);
//}
//Game::~Game() {
//	for (uint i = 0; i < NUM_TEXTURES; ++i) delete textures[i];
//	delete ball;
//	delete paddle;
//	delete map;
//	SDL_DestroyRenderer(renderer);
//	SDL_DestroyWindow(window);
//	SDL_Quit();
//}
//void Game::run() {
//
//	uint frames = 0;
//	while (!exit && !gameOver && !win)
//	{
//		uint32_t startTime, frameTime, deltaTime, timeStart;
//		startTime = SDL_GetTicks();
//		timeStart = SDL_GetTicks();
//		int seconds = 0;
//		while (!exit && !gameOver && !win) { // Bucle del juego
//			handleEvents();
//			frameTime = SDL_GetTicks() - startTime; // Tiempo desde última actualización
//			deltaTime = SDL_GetTicks() - timeStart;
//			// Cada vez que pase un segundo se llamará al update de la clase time, al cual le 
//			// pasaremos los segundos transcurridos actuales. Cuando pasen 999 segundos el juego terminará 
//			if (deltaTime >= 1000) {
//				time.update(++seconds);
//				timeStart = SDL_GetTicks();
//			}
//			if (frameTime >= FRAME_RATE) {
//				update(); // Actualiza el estado de todos los objetos del juego
//				startTime = SDL_GetTicks();
//
//			}
//			render(); // Renderiza todos los objetos del juego
//		}
//	}
//	if (win && level < (NUM_LEVELS - 1)) nextLevel();
//	else if (win && level >= (NUM_LEVELS - 1)) youWin();
//	else if (gameOver && lives > 1) restartLevel();
//	else if (gameOver && lives <= 1) GameOver();
//}
//void Game::update() {
//	ball->update();
//	paddle->update();
//}
//void Game::render() {
//	SDL_RenderClear(renderer);
//	for (int i = 0; i < 3; ++i) wall[i].render();
//	ball->render();
//	map->render();
//	paddle->render();
//	time.render();
//	SDL_RenderPresent(renderer);
//}
//void Game::handleEvents() {
//	SDL_Event event;
//	while (SDL_PollEvent(&event) && !exit) {
//		if (event.type == SDL_QUIT) exit = true;
//		paddle->handleEvents(event);
//	}
//}
//void Game::winLevel() {
//	if (map->getNumBlocks() <= 0) win = true;
//}
//void Game::restartLevel()
//{
//	gameOver = false;
//	--lives;
//	cout << "Te quedan " << lives << " vida(s)" << endl;
//	loadLevel();
//}
//void Game::GameOver()
//{
//	SDL_Rect rect;
//	rect.x = 0; rect.y = 0;
//	rect.w = WIN_WIDTH; rect.h = WIN_HEIGHT;
//
//	while (!exit)
//	{
//		handleEvents();
//		SDL_RenderClear(renderer);
//		textures[GameOverTx]->render(rect);
//		SDL_RenderPresent(renderer);
//	}
//}
//void Game::youWin()
//{
//	SDL_Rect rect;
//	rect.x = 0; rect.y = 0;
//	rect.w = WIN_WIDTH; rect.h = WIN_HEIGHT;
//
//	while (!exit)
//	{
//		handleEvents();
//		SDL_RenderClear(renderer);
//		textures[YouWinTx]->render(rect);
//		SDL_RenderPresent(renderer);
//	}
//}
//void Game::nextLevel()
//{
//	win = false;
//	++level;
//	loadLevel();
//
//}
//void Game::loadLevel() {
//	map->loadMap(levels[level]);
//	ball->setPos(Vector2D((double)WIN_WIDTH / 2, (double)WIN_HEIGHT / 2));
//	ball->setDir(Vector2D(1, -1));
//	paddle->setPos(Vector2D(350, 550));
//	run();
//}
//bool Game::collides(SDL_Rect rectBall, Vector2D& colVector)
//{
//	for (int i = 0; i < 3; ++i)
//		if (wall[i].collides((rectBall), colVector)) return true;
//
//	if (paddle->collides((rectBall), colVector)) return true;
//	if (map->collides((rectBall), colVector, ball->getDir())) { winLevel();  return true; }
//	if (rectBall.y + rectBall.h >= WIN_HEIGHT) gameOver = true;
//
//	return false;
//}
