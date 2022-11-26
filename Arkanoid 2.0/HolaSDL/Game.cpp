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
	paddle = new Paddle(Vector2D((double)WIN_WIDTH / 2, (double)WIN_HEIGHT - 100), PADDLE_HEIGHT, PADDLE_WIDTH, textures[PaddleTx], this, Vector2D(0, 0), 2.7, MAP_WIDTH + WALL_WIDTH, WALL_WIDTH);
	//paddle->loadFromFile();

	//Creamos el mapa
	map = new BlocksMap(MAP_HEIGHT, MAP_WIDTH, textures[BrickTx], this);

	//Creamos timer
	timer = new Time(Vector2D(WALL_WIDTH, WIN_HEIGHT - 50), TIME_HEIGHT, TIME_WIDTH, textures[NumsTx], this);

	//Creamos vidas
	life = new Life(Vector2D(UI_POS_X, WIN_HEIGHT - 50), UI_SIZE, textures[Heart], textures[NumsTx], NUM_LIVES, textures[Cross]);
	
	//Insertamos gameObjects a la lista
	gameObjects.push_back(rightWall);
	gameObjects.push_back(leftWall);
	gameObjects.push_back(topWall);
	gameObjects.push_back(ball);
	gameObjects.push_back(paddle);
	gameObjects.push_back(map);
	gameObjects.push_back(timer);
	gameObjects.push_back(life);

	rewardIterator = --gameObjects.end(); 
	
	try {
		map->loadMap(levels[level]);
		//map->loadFromFile();
	}
	catch (string e) {
		throw e;
	}

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
	//ball->saveToFile();
	//paddle->saveToFile();
	//map->saveToFile();
}
void Game::update() 
{
	if (CurrentState == win && level < (NUM_LEVELS - 1)) nextLevel();
	else if (CurrentState == lose && life->lives > 1) restartLevel();
	
	for (auto it = gameObjects.begin(); it != gameObjects.end(); ++it) {
		(*it)->update();
	}
	
}
void Game::render() {
	SDL_RenderClear(renderer); 
	if (CurrentState == win && level >= (NUM_LEVELS - 1))
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
	if (map->getNumBlocks() <= 0) CurrentState = win;
}

void Game::restartLevel()
{
	CurrentState = play;
	--life->lives;
	load();
}

void Game::nextLevel()
{
	CurrentState = play;
	if (life->lives > 3) life->lives = 3;
	++level;
	timer->resetTime();
	map->~BlocksMap();
	map->loadMap(levels[level]);
	load();
}

void Game::load()
{
	ball->restartBall();
	paddle->restartPaddle();
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
		winLevel(); 
		return true; 
	}
	if (rectBall.y + rectBall.h >= WIN_HEIGHT) CurrentState = lose;
	auto it = rewardIterator;
	++it;
	for (; it != gameObjects.end();) {
		if (static_cast<Reward*>(*it)->collides(paddle->getRect(), colVector)) {
			instanciateReward(static_cast<Reward*>(*it)->getTipe());
			delete* it;
			*it = nullptr;
			it = gameObjects.erase(it);
			
		}
		else if ((static_cast<Reward*>(*it)->getRect().y + static_cast<Reward*>(*it)->getRect().h) >= WIN_HEIGHT) {
			delete* it;
			*it = nullptr;
			it = gameObjects.erase(it);
		}
		else ++it;
	}
	return false;
}

void Game::generateRewards(Vector2D posAux) {

	srand(time(NULL) * _getpid() * rand());

	int num = rand() % 3; 
	if (num == 1) {
		int num2 = rand() % 300;
		cout << num2 << endl;
		if (num2 < 20) {
			if(level < 2) gameObjects.push_back(new Reward(posAux, REWARD_HEIGHT, REWARD_WIDTH, Vector2D(0, 1), textures[Rewards], 'L', textures[Rewards]->getNumCols()));
		}
		else if (num2 < 100) {
			gameObjects.push_back(new Reward(posAux, REWARD_HEIGHT, REWARD_WIDTH, Vector2D(0, 1), textures[Rewards], 'R', textures[Rewards]->getNumCols()));
			}
		else if (num2 < 200) {
			gameObjects.push_back(new Reward(posAux, REWARD_HEIGHT, REWARD_WIDTH, Vector2D(0, 1), textures[Rewards], 'S', textures[Rewards]->getNumCols()));
		}
		else if (num2 < 300) {
			gameObjects.push_back(new Reward(posAux, REWARD_HEIGHT, REWARD_WIDTH, Vector2D(0, 1), textures[Rewards], 'E', textures[Rewards]->getNumCols()));
		}
	}

}

void Game::instanciateReward(char tipo) {
	switch (tipo) {
	case 'L': { CurrentState = win;  nextLevel(); }break;
	case 'E': {  paddle->setWidth(paddle->getRect().w * 1.2);  }break;
	case 'R': {if(life->lives < 9) ++life->lives; }break;
	case 'S': {paddle->setWidth(paddle->getRect().w * 0.7); }break;
	}
}

void Game::loadFromFile(string nameFile) {
	ifstream loadFile(nameFile);
	for (auto it = gameObjects.begin(); it != gameObjects.end(); ++it) {
		string type;
		loadFile >> type;
		if (type == "MAP") map->loadFromFile(nameFile);
		else if (type == "BALL")ball->loadFromFile(nameFile);
		else if (type == "PADDLE")paddle->loadFromFile(nameFile);
		else if (type == "LIFE")life->loadFromFile(nameFile);
		else if (type == "TIME")timer->loadFromFile(nameFile);
		else if (type == "REWARDS") {
			Vector2D posAux;
			char tipo = 'L';
			gameObjects.push_back(new Reward(posAux, REWARD_HEIGHT, REWARD_WIDTH, Vector2D(0, 1), textures[Rewards], tipo, textures[Rewards]->getNumCols()));

		}
	}
	loadFile.close();
}
void Game::menuWindow() {
	SDL_Event event;
	int xMouse, yMouse;

	bool click = false;
	while (SDL_PollEvent(&event) && !click) {
		SDL_Rect rectTitle;
		rectTitle.x = 0; rectTitle.y = 0;
		rectTitle.w = WIN_WIDTH; rectTitle.h = WIN_HEIGHT;
		textures[Title]->render(rectTitle);

		SDL_Rect rectStart;
		rectStart.x = 0; rectStart.y = 0;
		rectStart.w = 100; rectStart.h = 50;
		textures[Title]->render(rectStart);

		SDL_Rect rectLoad;
		rectLoad.x = 0; rectLoad.y = 0;
		rectLoad.w = 100; rectLoad.h = 50;
		textures[Title]->render(rectLoad);

		SDL_Point mousePos;
		mousePos.x = xMouse;
		mousePos.y = yMouse;
		SDL_RenderClear(renderer);
		if (event.type == SDL_MOUSEMOTION)
		{
			SDL_GetGlobalMouseState(&xMouse, &yMouse);
		}
		if (event.type == SDL_QUIT) click = true;
		if (SDL_PointInRect(&mousePos, &rectStart) && event.type == SDL_MOUSEBUTTONDOWN) {
			cout << "hola";
		}
		
		//manejar eventos, si se hace click a uno de los botonees se
		// sale del bucle
		SDL_RenderPresent(renderer);
	}
	
}