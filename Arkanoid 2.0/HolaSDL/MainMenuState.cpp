#include "MainMenuState.h"

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