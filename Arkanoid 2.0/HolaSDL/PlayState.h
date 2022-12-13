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
	States CurrentState = play;

	bool collides(SDL_Rect destRect, Vector2D& colVector);
	void loadGame(string nameFile);
	void newGame();
	int getWallSize() { return WALL_WIDTH; }
	void rewardType(char tipo);
	//void timeLimit() { CurrentState = lose; life->lives = 0; }
	PlayState();
	~PlayState();
	static const string s_playID;


protected:
	virtual void render() const;
	virtual void handleEvents();
	virtual void update();
	virtual string getStateID() const { return s_playID; }
	
	
	void winLevel();
	void nextLevel();
	void restartLevel();
	void load();
	void generateRewards(Vector2D posAux);
	void saveToFile(string code);
};

