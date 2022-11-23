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
using namespace std;
using uint = unsigned int;


//Constantes del juego
const uint NUM_TEXTURES = 9;
const uint WIN_WIDTH = 800;
const uint WIN_HEIGHT = 600;
const uint WALL_WIDTH = 14;
const uint BALL_SIZE = 20;
const uint FRAME_RATE = 5;
const uint MAP_WIDTH = WIN_WIDTH - WALL_WIDTH * 2;
const uint MAP_HEIGHT = (WIN_HEIGHT - WALL_WIDTH * 2) / 2;
const uint PADDLE_WIDTH = MAP_WIDTH / 8;
const uint PADDLE_HEIGHT = 20;
const uint TIME_WIDTH = 20;
const uint TIME_HEIGHT = 40;
const uint NUM_LIVES = 3;
const uint NUM_LEVELS = 3;
const uint REWARD_HEIGHT = 20;
const uint REWARD_WIDTH = 40;


// Enumerado con el nombre de las texturas del juego
const enum TextureNames {
	BallTx = 0, PaddleTx = 1, BrickTx = 2, NumsTx = 3,
	GameOverTx = 4, SideWallTx = 5, TopWallTx = 6, YouWinTx = 7, Rewards = 8
};


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

	// Booleanos de control del juego
	bool exit = false;
	bool gameOver = false;
	bool win = false;

	// Array estatico de tipo estructura para guardar informacion de las texturas
	Textures texture[NUM_TEXTURES] = { {"../images/ball2.png", 1, 1}, {"../images/paddle2.png", 1, 1},
							{"../images/bricks2.png", 2, 3}, {"../images/digits2.jpeg", 3, 4},
							{"../images/gameover1.png", 1, 1}, {"../images/side2.png", 1, 1},
							{"../images/topside.png", 1, 1}, {"../images/youwin.png", 1, 1} , {"../images/rewards.png", 10, 8} };

	string levels[NUM_LEVELS] = { { "level01.txt" }, { "level02.txt" }, { "level03.txt" } };
	// Lista de todos los GameObjects
	list<ArkanoidObject*> gameObjects;
	list<ArkanoidObject*>::iterator rewardIterator;
	Texture* textures[NUM_TEXTURES];
	Ball* ball = nullptr;
	Paddle* paddle = nullptr;
	Wall* topWall;
	Wall* leftWall;
	Wall* rightWall;
	BlocksMap* map = nullptr;
	//Time time;
	Reward* rewards;
	// Ints de control de juego
	int level = 0;
	int lives = NUM_LIVES;


public:
	//Constructuctora y destructora de Game
	Game();
	~Game();


	void run();
	void render();
	void handleEvents();
	void update();
	bool collides(SDL_Rect destRect, Vector2D& colVector);

	int getWallSize() { return WALL_WIDTH; }

protected:
	void winLevel();
	void nextLevel();
	void restartLevel();
<<<<<<< Updated upstream
	void load();
=======
	void loadLevel();
	void generateRewards(Vector2D posAux);
	void instanciateReward(char tipo);
>>>>>>> Stashed changes

};


