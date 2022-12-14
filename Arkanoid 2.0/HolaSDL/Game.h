#pragma once
#include <SDL_image.h>
#include "checkML.h"
#include <string>
#include <list>
#include "GameStateMachine.h"
#include "MainMenuState.h"

using namespace std;

using uint = unsigned int;

//Enumerado de estados del juego
enum GameStates { 
	PLAY = 0,
	PAUSE = 1,
	END = 2,
	MENU = 3
};

// Enumerado con el nombre de las texturas del juego
static const enum TextureNames {
	BallTx = 0, PaddleTx = 1, BrickTx = 2, NumsTx = 3,
	GameOverTx = 4, SideWallTx = 5, TopWallTx = 6, YouWinTx = 7, Rewards = 8, Heart = 9, Cross = 10, 
	Title = 11, Start = 12, Load = 13, Play = 14, Exit = 15, Main = 16, Resume = 17, Restart = 18
};

// Estructura que contiene variables para el nombre de las imagenes de la textura y su numero de filas y columnas
struct Textures
{
	string filename;
	int rows;
	int cols;
};

class Game {
public:
	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;

	//// Estado actual del juego
	//int CurrentState = menu;

	// Booleano de control del juego
	bool exit = false;
		
	// Array estatico de tipo estructura para guardar informacion de las texturas
	Textures texture[NUM_TEXTURES] = { {"../images/ball2.png", 1, 1}, {"../images/paddle2.png", 1, 1}, {"../images/bricks2.png", 2, 3},
									 {"../images/digits2.jpeg", 3, 4},{"../images/gameover1.png", 1, 1}, {"../images/side2.png", 1, 1},
									 {"../images/topside.png", 1, 1}, {"../images/youwin.png", 1, 1} , {"../images/rewards.png", 10, 8},
									 {"../images/heart.png", 1, 1} , {"../images/cross.png", 1, 1},  {"../images/Title.png", 1, 1},
									 {"../images/Start.png", 1,1}, { "../images/Load.png", 1, 1 }, { "../images/play.png", 1, 3 }, 
									 { "../images/exit.png", 1, 3 }, { "../images/main.png", 1, 3 }, { "../images/resume.png", 1, 3 },
									 { "../images/restart.png", 1, 3 } };

	Texture* textures[NUM_TEXTURES];

	// Estado actual del juego
	GameStateMachine* gameStateMachine = nullptr;

public:
	//Constructuctora y destructora de Game
	Game();
	~Game();

	void run();
	void render() const;
	void update();
	void handleEvents();
	GameStateMachine* getStateMachine() { return gameStateMachine; }
}; 


