#include "Game.h"
#include <iostream>
#include "checkML.h"
#include <time.h>
using namespace std;
Game::Game() {
	// We first initialize SDL
	SDL_Init(SDL_INIT_EVERYTHING);
	window = SDL_CreateWindow("Arkanoid", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		WIN_WIDTH, WIN_HEIGHT, SDL_WINDOW_SHOWN);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (window == nullptr || renderer == nullptr) throw string("Error loading SDL window or renderer");

	//Nos creamos las texturas
	for (uint i = 0; i < NUM_TEXTURES; ++i)
	{
		try {
			textures[i] = new Texture(renderer, texture[i].filename, texture[i].rows, texture[i].cols);
		}
		catch (string e) {
			throw e;
		}
	}

	//Creamos las paredes
	leftWall = new Wall(Vector2D(0, WALL_WIDTH), WIN_HEIGHT, WALL_WIDTH, textures[SideWallTx], Vector2D(1, 0));
	rightWall = new Wall(Vector2D(WIN_WIDTH - WALL_WIDTH, WALL_WIDTH), WIN_HEIGHT, WALL_WIDTH, textures[SideWallTx], Vector2D(-1, 0));
	topWall = new Wall(Vector2D(0, 0), WALL_WIDTH, WIN_WIDTH, textures[TopWallTx], Vector2D(0, 1));

	//Creamos la bola
	ball = new Ball(Vector2D((double)WIN_WIDTH / 2, (double)WIN_HEIGHT / 2), BALL_SIZE, Vector2D(1, -1), textures[BallTx], this);
	//ball->loadFromFile();

	//Creamos el paddle
	paddle = new Paddle(Vector2D((double)WIN_WIDTH / 2, (double)WIN_HEIGHT - 100), PADDLE_HEIGHT, PADDLE_WIDTH, textures[PaddleTx], this, Vector2D(0, 0), 2, MAP_WIDTH + WALL_WIDTH, WALL_WIDTH);

	//Creamos el mapa
	map = new BlocksMap(MAP_HEIGHT, MAP_WIDTH, textures[BrickTx], this);

	//Insertamos gameObjects a la lista
	gameObjects.push_back(rightWall);
	gameObjects.push_back(leftWall);
	gameObjects.push_back(topWall);
	gameObjects.push_back(ball);
	gameObjects.push_back(paddle);
	gameObjects.push_back(map);

	rewardIterator = --gameObjects.end();
	
	try {
		map->loadMap(levels[level]);
	}
	catch (string e) {
		throw e;
	}

	//Creamos timer
	//time = Time(Vector2D(WALL_WIDTH, WIN_HEIGHT - 50), TIME_HEIGHT, TIME_WIDTH, textures[NumsTx], this);
}
Game::~Game() {
	for (uint i = 0; i < NUM_TEXTURES; ++i) delete textures[i];
	delete ball;
	delete paddle;
	delete map;
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}
void Game::run() {

	uint frames = 0;
	while (!exit)
	{
		uint32_t startTime, frameTime;
		startTime = SDL_GetTicks();
		while (!exit) { // Bucle del juego
			handleEvents();
			frameTime = SDL_GetTicks() - startTime; // Tiempo desde última actualización
			if (frameTime >= FRAME_RATE) {
				update(); // Actualiza el estado de todos los objetos del juego
				startTime = SDL_GetTicks();
			}
			render(); // Renderiza todos los objetos del juego
		}
	}
	ball->saveToFile();
}
void Game::update() 
{
	if (win && level < (NUM_LEVELS - 1)) nextLevel();
	else if (gameOver && lives > 1) restartLevel();
	
	for (auto it = gameObjects.begin(); it != gameObjects.end(); ++it) {
		(*it)->update();
	}

}
void Game::render() {
	SDL_RenderClear(renderer); 
	if (win && level >= (NUM_LEVELS - 1))
	{
		SDL_Rect rect;
		rect.x = 0; rect.y = 0;
		rect.w = WIN_WIDTH; rect.h = WIN_HEIGHT;
		textures[YouWinTx]->render(rect);
	}
	else if (gameOver && lives <= 1)
	{
		SDL_Rect rect;
		rect.x = 0; rect.y = 0;
		rect.w = WIN_WIDTH; rect.h = WIN_HEIGHT;
		textures[GameOverTx]->render(rect);
	}
	else
	{
		for (auto it = gameObjects.begin(); it != gameObjects.end(); ++it) {
			(*it)->render();
		}
	}
	SDL_RenderPresent(renderer);
}

void Game::handleEvents() {
	SDL_Event event;
	while (SDL_PollEvent(&event) && !exit) {
		if (event.type == SDL_QUIT) exit = true;
		paddle->handleEvents(event);
	}
}

void Game::winLevel() {
	if (map->getNumBlocks() <= 0) win = true;
}

void Game::restartLevel()
{
	gameOver = false;
	--lives;
	cout << "Te quedan " << lives << " vida(s)" << endl;
	load();
}

void Game::nextLevel()
{
	win = false;
	++level;
	load();
}

void Game::load()
{
	map->~BlocksMap();
	map->loadMap(levels[level]);
	ball->restartBall();
	paddle->setPos(Vector2D((double)((WIN_WIDTH / 2) - 50), (double)WIN_HEIGHT - 100));
}

bool Game::collides(SDL_Rect rectBall, Vector2D& colVector)
{
	Vector2D posAux;
	if (topWall->collides((rectBall), colVector)) return true;
	if (rightWall->collides((rectBall), colVector)) return true;
	
	if (leftWall->collides((rectBall), colVector)) return true;
	

	if (paddle->collides((rectBall), colVector)) return true;
	if (map->collides((rectBall), colVector, ball->getDir(), posAux)){
		generateRewards(posAux);
		winLevel();  return true; 
	}
	if (rectBall.y + rectBall.h >= WIN_HEIGHT) gameOver = true;

	for (auto it = rewardIterator; it != gameObjects.end();) {
		if (static_cast<Reward*>(*it)->collides(paddle->getRect(), colVector)) {
			cout << "Entre weon" << endl;
			instanciateReward(static_cast<Reward*>(*it)->getTipe());
			delete* it;
			*it = nullptr;
			it = gameObjects.erase(it);
		}
		else ++it;
	}
	return false;
}

void Game::generateRewards(Vector2D posAux) {
	int num = rand() % 41;
	cout << num << endl;
	if (num < 10) {
		rewards = new Reward(posAux, REWARD_HEIGHT, REWARD_WIDTH, Vector2D(0, 1), textures[Rewards], 'L');
	}
	else if (num < 20) {
		rewards = new Reward(posAux, REWARD_HEIGHT, REWARD_WIDTH, Vector2D(0, 1), textures[Rewards], 'E');
	}
	else if (num < 30) {
		rewards = new Reward(posAux, REWARD_HEIGHT, REWARD_WIDTH, Vector2D(0, 1), textures[Rewards], 'C');
	}
	else if (num < 40) {
		rewards = new Reward(posAux, REWARD_HEIGHT, REWARD_WIDTH, Vector2D(0, 1), textures[Rewards], 'S');
	}
	gameObjects.push_back(rewards);

}

void Game::instanciateReward(char tipo) {
	switch (tipo) {
	case 'L': {cout << "Reward tipo L" << endl; }break;
	case 'E': { cout << "Reward tipo E" << endl; }break;
	case 'C': {cout << "Reward tipo C" << endl; }break;
	case 'S': {cout << "Reward tipo S" << endl; }break;
	}
}
