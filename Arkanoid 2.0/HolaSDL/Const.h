#pragma once
using uint = unsigned int;
//Constantes del juego
const uint NUM_TEXTURES = 19;
const uint WIN_WIDTH = 800;
const uint WIN_HEIGHT = 600;
const uint WALL_WIDTH = 14;
const uint BALL_SIZE = 17;
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
const uint UI_POS_X = WIN_WIDTH - WALL_WIDTH - 80;
const uint UI_SIZE = 25;
const uint BUTTON_WIDTH = 150;
const uint BUTTON_HEIGHT = 30;
class Const
{
};

