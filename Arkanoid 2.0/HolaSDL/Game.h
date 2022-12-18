#pragma once
#include <SDL_image.h>
#include "checkML.h"
#include <string>
#include <list>
#include "GameStateMachine.h"
//#include "MainMenuState.h"
#include "PlayState.h"

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
	Title = 11, Start = 12, Load = 13, Exit = 14, Main = 15, Resume = 16, Restart = 17, Save = 18, Pause = 19
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
public:
	//// Estado actual del juego
	//int CurrentState = menu;

	// Booleano de control del juego
	bool exit = false;
		
	// Array estatico de tipo estructura para guardar informacion de las texturas
	Textures texture[NUM_TEXTURES] = { {"../images/ball2.png", 1, 1}, {"../images/paddle2.png", 1, 1}, {"../images/bricks2.png", 2, 3},
									 {"../images/digits2.jpeg", 3, 4},{"../images/gameover1.png", 1, 1}, {"../images/side2.png", 1, 1},
									 {"../images/topside.png", 1, 1}, {"../images/youwin.png", 1, 1} , {"../images/rewards.png", 10, 8},
									 {"../images/heart.png", 1, 1} , {"../images/cross.png", 1, 1},  {"../images/Title.png", 1, 1},
									 {"../images/start.png", 1, 2}, { "../images/load.png", 1, 2 }, { "../images/exit.png", 1, 2 },
									 { "../images/mainmenu.png", 1, 2 }, { "../images/resume.png", 1, 2 }, { "../images/restart.png", 1, 2 }, 
									 { "../images/save.png", 1, 2},  { "../images/pause.png", 1, 1} };

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
	void exitGame() {exit = true;}
	GameStateMachine* getStateMachine() { return gameStateMachine; }
	Texture* getTexture(int tx) { return textures[tx]; }
}; 


