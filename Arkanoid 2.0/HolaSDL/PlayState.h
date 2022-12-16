#pragma once
#include "GameState.h"
#include "Ball.h"
#include "Paddle.h"
#include "Wall.h"
#include "BlocksMap.h"
#include "Time.h"
#include "Life.h"
#include "Menu.h"
#include "PauseState.h"
#include "EndState.h"
#include "MainMenuState.h"
#include "Reward.h"
#include "Game.h"

class PlayState :public GameState
{
	enum States {
		win = 0,
		lose = 1,
		play = 2,
	};
private:

	string levels[NUM_LEVELS] = { { "level01.txt" }, { "level02.txt" }, { "level03.txt" } };
	// Lista de todos los GameObjects
	//Menu menuWindow;
	// Ints de control de juego
	list<GameObject*>::iterator rewardIterator;
	Ball* ball = nullptr;
	Paddle* paddle = nullptr;
	Wall* topWall = nullptr;
	Wall* leftWall = nullptr;
	Wall* rightWall = nullptr;
	BlocksMap* map = nullptr;
	Time* timer = nullptr;
	Life* life = nullptr;
	int level = 0;
	bool canCollide = true;
	States CurrentState = play;
	string playID;

public://No se si tiene que ser protected
	PlayState(Game* game);
	~PlayState();
	bool collides(SDL_Rect destRect, Vector2D& colVector);
	void loadGame(string nameFile);
	void newGame();
	void rewardType(char tipo);
	void timeLimit() { CurrentState = lose; life->lives = 0; }
	virtual void render() const {};
	//virtual string getStateID() const { return playID; }
	int getWallSize() { return WALL_WIDTH; }
	
	
	void winLevel();
	void nextLevel();
	void restartLevel();
	void load();
	void generateRewards(Vector2D posAux);
	void saveToFile(string code);
};

