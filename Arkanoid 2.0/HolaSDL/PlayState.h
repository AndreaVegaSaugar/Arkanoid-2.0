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
	
private:

	string levels[NUM_LEVELS] = { { "level01.txt" }, { "level02.txt" }, { "level03.txt" } };
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
	static const string playID;

public://No se si tiene que ser protected
	bool erased = false;
	PlayState(Game* game, string current);
	~PlayState();
	bool collides(SDL_Rect destRect, Vector2D& colVector);
	bool collideReward(SDL_Rect destRect);
	void destroyReward();
	void prepareRewardToErase();
	void loadGame(string nameFile);
	void newGame();
	void timeLimit() { life->lives = 0; }
	int getWallSize() { return WALL_WIDTH; }
	void paddleSize(char c);
	void ballSize();
	void extraLives();
	void update();
	void winLevel();
	void nextLevel();
	void restartLevel();
	void load();
	void generateRewards(Vector2D posAux);
	void saveToFile(string code);
	void handleEvent(SDL_Event event);
	virtual string getStateID() const { return playID; }
};

