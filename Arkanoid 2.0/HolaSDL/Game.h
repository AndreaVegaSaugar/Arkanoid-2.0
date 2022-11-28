#pragma once
#include <SDL_image.h>
#include "Texture.h"
#include "Ball.h"
#include "Paddle.h"
#include "Wall.h"
#include "BlocksMap.h"
#include "Vector2D.h"
#include "Reward.h"
#include "checkML.h"
#include "Time.h"
#include <string>
#include <list>
#include "Life.h"
#include "Menu.h"


using namespace std;

using uint = unsigned int;


// Enumerado con el nombre de las texturas del juego
const enum TextureNames {
	BallTx = 0, PaddleTx = 1, BrickTx = 2, NumsTx = 3,
	GameOverTx = 4, SideWallTx = 5, TopWallTx = 6, YouWinTx = 7, Rewards = 8, Heart = 9, Cross = 10, 
	Title = 11, Start = 12, Load = 13
};

// Enumerado de estados de juego
enum GameStates {play, lose, win, menu};

// Estructura que contiene variables para el nombre de las imagenes de la textura y su numero de filas y columnas
struct Textures
{
	string filename;
	int rows;
	int cols;
};

class Game {
private:
	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;

	// Estado actual del juego
	int CurrentState = menu;

	// Booleano de control del juego
	bool exit = false;

	// Array estatico de tipo estructura para guardar informacion de las texturas
	Textures texture[NUM_TEXTURES] = { {"../images/ball2.png", 1, 1}, {"../images/paddle2.png", 1, 1}, {"../images/bricks2.png", 2, 3},
									 {"../images/digits2.jpeg", 3, 4},{"../images/gameover1.png", 1, 1}, {"../images/side2.png", 1, 1},
									 {"../images/topside.png", 1, 1}, {"../images/youwin.png", 1, 1} , {"../images/rewards.png", 10, 8},
									 {"../images/heart.png", 1, 1} , {"../images/cross.png", 1, 1},  {"../images/Title.png", 1, 1},
									 {"../images/Start.png", 1,1}, { "../images/Load.png", 1, 1 }};

	string levels[NUM_LEVELS] = { { "level01.txt" }, { "level02.txt" }, { "level03.txt" } };
	// Lista de todos los GameObjects
	list<ArkanoidObject*> gameObjects;
	list<ArkanoidObject*>::iterator rewardIterator;
	Texture* textures[NUM_TEXTURES];
	Ball* ball = nullptr;
	Paddle* paddle = nullptr;
	Wall* topWall = nullptr;
	Wall* leftWall = nullptr;
	Wall* rightWall = nullptr;
	BlocksMap* map = nullptr;
	Time* timer = nullptr;
	Life* life = nullptr;
	Menu menuWindow;
	// Ints de control de juego
	int level = 0;


public:
	//Constructuctora y destructora de Game
	Game();
	~Game();


	void run();
	void render();
	void handleEvents();
	void update();
	bool collides(SDL_Rect destRect, Vector2D& colVector);
	//void menuWindow();
	void loadGame(string nameFile);
	void newGame();
	int getWallSize() { return WALL_WIDTH; }

protected:
	void winLevel();
	void nextLevel();
	void restartLevel();
	void load();
	void generateRewards(Vector2D posAux);
	void instanciateReward(char tipo);
	void saveToFile(string code);
};


