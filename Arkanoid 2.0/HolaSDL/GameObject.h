#pragma once
#include "Vector2D.h"
#include "Texture.h"

//Constantes del juego
static const uint NUM_TEXTURES = 11;
static const uint WIN_WIDTH = 800;
static const uint WIN_HEIGHT = 600;
static const uint WALL_WIDTH = 14;
static const uint BALL_SIZE = 17;
static const uint FRAME_RATE = 5;
static const uint MAP_WIDTH = WIN_WIDTH - WALL_WIDTH * 2;
static const uint MAP_HEIGHT = (WIN_HEIGHT - WALL_WIDTH * 2) / 2;
static const uint PADDLE_WIDTH = MAP_WIDTH / 8;
static const uint PADDLE_HEIGHT = 20;
static const uint TIME_WIDTH = 20;
static const uint TIME_HEIGHT = 40;
static const uint NUM_LIVES = 3;
static const uint NUM_LEVELS = 3;
static const uint REWARD_HEIGHT = 20;
static const uint REWARD_WIDTH = 40;
static const uint UI_POS_X = WIN_WIDTH - WALL_WIDTH - 80;
static const uint UI_SIZE = 25;

class GameObject
{
public:
 
	virtual void render()const = 0;
	virtual void update() {};
	void handleEvent()const {};

};

