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
	if (window == nullptr || renderer == nullptr) throw (SDLError("Error loading SDL window or renderer"));

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

	paddle = new Paddle(Vector2D((double)WIN_WIDTH / 2, (double)WIN_HEIGHT - 100), PADDLE_HEIGHT, PADDLE_WIDTH, textures[PaddleTx], this, Vector2D(0, 0), 2.7, MAP_WIDTH + WALL_WIDTH, WALL_WIDTH);
	//paddle->loadFromFile();

	//Creamos timer
	timer = new Time(Vector2D(WALL_WIDTH, WIN_HEIGHT - 50), TIME_HEIGHT, TIME_WIDTH, textures[NumsTx], this);

	//Creamos vidas
	life = new Life(Vector2D(UI_POS_X, WIN_HEIGHT - 50), UI_SIZE, textures[Heart], textures[NumsTx], NUM_LIVES, textures[Cross]);
	
	//Crear mapa vacio
	map = new BlocksMap(MAP_HEIGHT, MAP_WIDTH, textures[BrickTx], this);


	//Insertamos gameObjects a la lista
	gameObjects.push_back(life);
	gameObjects.push_back(timer);
	gameObjects.push_back(rightWall);
	gameObjects.push_back(leftWall);
	gameObjects.push_back(topWall);
	gameObjects.push_back(ball);
	gameObjects.push_back(paddle);
	gameObjects.push_back(map);

	rewardIterator = --gameObjects.end(); 

}

Game::~Game() {
	for (auto it = gameObjects.begin(); it != gameObjects.end(); ++it)
	{
		delete* it;
	}
	for (uint i = 0; i < NUM_TEXTURES; ++i) delete textures[i];
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

void Game::run() {

	while (!exit)
	{
		uint32_t startTime, frameTime;
		menuWindow = Menu(textures[Title], textures[Start], textures[Load], WIN_WIDTH, WIN_HEIGHT, BUTTON_HEIGHT, BUTTON_WIDTH, this, timer);
		startTime = SDL_GetTicks();
		while (!exit) { // Bucle del juego
			handleEvents();
			if (CurrentState != pause) {

				frameTime = SDL_GetTicks() - startTime; // Tiempo desde última actualización
				if (frameTime >= FRAME_RATE) {
					update(); // Actualiza el estado de todos los objetos del juego
					startTime = SDL_GetTicks();
				}
				render(); // Renderiza todos los objetos del juego
			}
		}
	}
}

void Game::update() 
{
	if (CurrentState == win && level < (NUM_LEVELS - 1)) nextLevel();
	else if (CurrentState == lose && life->lives > 1) restartLevel();
	else if (CurrentState == play)
	{
		for (auto it = gameObjects.begin(); it != gameObjects.end(); ++it) {
			(*it)->update();
		}
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
	else if (CurrentState == menu) {
		menuWindow.render();
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
		if (CurrentState == menu) {
			string file;
			char optionButton;
			menuWindow.handleEvents(event, file, optionButton);
			if (optionButton == 'n') newGame();
			else if (optionButton == 'l')
			{
				try{
					loadGame(file);
				}
				catch (FileFormatError e){
					cout << e.what() << endl;
				}
				catch (FileNotFoundError e){
					cout << e.what() << endl;
					cout << "We couldn't find a save file with that name so we will start a new game for you";
					newGame();
				}

			}
		}
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
	auto it = rewardIterator;
	for (; it != gameObjects.end();) {
		delete* it;
		*it = nullptr;
		it = gameObjects.erase(it);
	}

	CurrentState = play;
	life->resetLife();
	++level;
	timer->resetTime();
	map = new BlocksMap(MAP_HEIGHT, MAP_WIDTH, textures[BrickTx], this);
	gameObjects.push_back(map);
	rewardIterator = --gameObjects.end();
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
	Vector2D posAux; char type = ' ';

	if (topWall->collides((rectBall), colVector)) { canCollide = true; return true; }
	if (rightWall->collides((rectBall), colVector)) { canCollide = true; return true; }
	if (leftWall->collides((rectBall), colVector)) { canCollide = true; return true; }

	if (canCollide) {
		if (paddle->collides((rectBall), colVector, ball->getDir())) { canCollide = false;  return true; }
	}

	if (map->collides((rectBall), colVector, ball->getDir(), posAux)){
		canCollide = true;
		generateRewards(posAux);
		winLevel(); 
		return true; 
	}
	if (rectBall.y + rectBall.h >= WIN_HEIGHT) CurrentState = lose;

	auto it = rewardIterator;
	++it;
	for (; it != gameObjects.end();) {
		Reward* reward = static_cast<Reward*>(*it);
		if (reward->collides(paddle->getRect())) {
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
		int num2 = rand() % 400;
		if (num2 < 20) {
			if(level < 2) gameObjects.push_back(new Reward(posAux, REWARD_HEIGHT, REWARD_WIDTH, Vector2D(0, 1), textures[Rewards], 'L', textures[Rewards]->getNumCols(), this));
		}
		else if (num2 < 100) {
			gameObjects.push_back(new Reward(posAux, REWARD_HEIGHT, REWARD_WIDTH, Vector2D(0, 1), textures[Rewards], 'R', textures[Rewards]->getNumCols(), this));
			}
		else if (num2 < 200) {
			gameObjects.push_back(new Reward(posAux, REWARD_HEIGHT, REWARD_WIDTH, Vector2D(0, 1), textures[Rewards], 'S', textures[Rewards]->getNumCols(), this));
		}
		else if (num2 < 300) {
			gameObjects.push_back(new Reward(posAux, REWARD_HEIGHT, REWARD_WIDTH, Vector2D(0, 1), textures[Rewards], 'E', textures[Rewards]->getNumCols(), this));
		}
		else if (num2 < 400) {
			gameObjects.push_back(new Reward(posAux, REWARD_HEIGHT, REWARD_WIDTH, Vector2D(0, 1), textures[Rewards], 'D', textures[Rewards]->getNumCols(), this));
		}
	}

}

void Game::rewardType(char tipo) {
	switch (tipo) {
	case 'L': { CurrentState = win; }break;
	case 'E': {  ball->setSize(BALL_SIZE); if (paddle->getWidth() == PADDLE_WIDTH) paddle->setWidth(paddle->getRect().w * 1.3); else paddle->setWidth(PADDLE_WIDTH); }break;
	case 'R': { if (life->lives < 9) paddle->setWidth(PADDLE_WIDTH); ball->setSize(BALL_SIZE); ++life->lives; }break;
	case 'S': {  ball->setSize(BALL_SIZE); if (paddle->getWidth() == PADDLE_WIDTH) paddle->setWidth(paddle->getRect().w * 0.7); else paddle->setWidth(PADDLE_WIDTH); }break;
	case 'D': { if(ball->getSize() == BALL_SIZE) ball->setSize(ball->getRect().w * 1.5); else ball->setSize(BALL_SIZE); }
	}
}

void Game:: newGame() {
	try {
		map->loadMap(levels[level]);
	}
	catch (string e) {
		throw e;
	}
	CurrentState = play;
	timer->changeTime(SDL_GetTicks() / 1000);
}

void Game::loadGame(string nameFile) {
	ifstream loadFile(nameFile);
	if (loadFile.is_open())
	{
		for (auto it = gameObjects.begin(); it != gameObjects.end(); ++it) {
			string type;
			loadFile >> type;
			if (type == "Level") {
				int l;
				loadFile >> l;
				level = l;
			}
			else if (type == "Life") {
				life->loadFromFile(loadFile);
			}
			else if (type == "Time") {
				timer->loadFromFile(loadFile);
			}
			else if (type == "Ball") {
				ball->loadFromFile(loadFile);
			}
			else if (type == "Paddle") {
				paddle->loadFromFile(loadFile);
			}
			else if (type == "BlocksMap") {
				map->loadFromFile(loadFile);
			}
			else if (type == "Reward") {
				Reward* reward = new Reward(Vector2D(0, 0), REWARD_HEIGHT, REWARD_WIDTH, Vector2D(0, 1), textures[Rewards], 'L', textures[Rewards]->getNumCols(), this);
				reward->loadFromFile(loadFile);
				gameObjects.push_back(reward);
			}
		}
	}
	else throw (FileNotFoundError("Error trying to open file: " + nameFile));
	loadFile.close();
	CurrentState = play;
	timer->changeTime(SDL_GetTicks() / 1000);
}

void Game::saveToFile(string code) {
	int cont = 0;
	ofstream saveFile;
	saveFile.open(code);
	saveFile << "Level " << level << endl;
	auto aux = rewardIterator;
	++aux;
	for (auto it = gameObjects.begin(); it != aux; ++it) {
		(*it)->saveToFile(saveFile);
		++cont;
	}

	saveFile << gameObjects.size()-cont << endl;
	auto it = rewardIterator;
	++it;
	for (; it != gameObjects.end();++it) {
		(*it)->saveToFile(saveFile);
	}
	saveFile.close();
}