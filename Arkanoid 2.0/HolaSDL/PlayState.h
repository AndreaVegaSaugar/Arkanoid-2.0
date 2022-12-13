#pragma once
#include "GameState.h"
#include "Ball.h"
#include "Paddle.h"
#include "Wall.h"
#include "BlocksMap.h"
#include "Time.h"
#include "Life.h"
#include "Menu.h"

// Enumerado de estados de juego
enum GameStates { play, lose, win, menu, pause };
class PlayState :public GameState
{
private:

	// Estado actual del juego
	int CurrentState = menu;
	string ID = "PLAY";

	string levels[NUM_LEVELS] = { { "level01.txt" }, { "level02.txt" }, { "level03.txt" } };
	// Lista de todos los GameObjects
	list<GameObject*> gameObjects;
	list<GameObject*>::iterator rewardIterator;
	Ball* ball = nullptr;
	Paddle* paddle = nullptr;
	Wall* topWall = nullptr;
	Wall* leftWall = nullptr;
	Wall* rightWall = nullptr;
	BlocksMap* map = nullptr;
	Time* timer = nullptr;
	Life* life = nullptr;
	//Menu menuWindow;
	// Ints de control de juego
	int level = 0;
	bool canCollide = true;


	PlayState(Game* game, string _playID);
	~PlayState();
	bool collides(SDL_Rect destRect, Vector2D& colVector);
	void loadGame(string nameFile);
	void newGame();
	int getWallSize() { return WALL_WIDTH; }
	void rewardType(char tipo);
	void timeLimit() { CurrentState = lose; life->lives = 0; }

protected:
	void run();
	void render();
	void handleEvents();
	void update();
	void winLevel();
	void nextLevel();
	void restartLevel();
	void load();
	void generateRewards(Vector2D posAux);
	void saveToFile(string code);
};

