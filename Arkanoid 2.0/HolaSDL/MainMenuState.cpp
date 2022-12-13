#include "MainMenuState.h"

MainMenuState::MainMenuState(Game* game, string _menuID, Texture* t, Vector2D p, int w, int h, MenuButton* sB, MenuButton* lB, MenuButton* eB) : MenuGameState(game, _menuID, t, p, w, h), start(sB), load(lB), exit(eB)
{
	/*rectStart.x = 245; rectStart.y = 350; rectStart.w = BUTTON_WIDTH; rectStart.h = BUTTON_HEIGHT;
	rectLoad.x = 245; rectLoad.y = 200; rectLoad.w = BUTTON_WIDTH; rectLoad.h = BUTTON_HEIGHT;
	rectExit.x = 245; rectExit.y = 500; rectExit.w = BUTTON_WIDTH; rectExit.h = BUTTON_HEIGHT;*/
}

void MainMenuState::update()
{

}

void MainMenuState::render()
{
	textureB->render(rectB);
	start->render();
	load->render();
	exit->render();
}

void MainMenuState::handleEvents()
{

}

void MainMenuState::startGame(Game* game)
{

}

void MainMenuState::loadGame(Game* game)
{

}

void MainMenuState::exitGame(Game* game)
{

}