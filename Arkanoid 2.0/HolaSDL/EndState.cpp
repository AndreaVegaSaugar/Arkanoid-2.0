#include "EndState.h"

void EndState::update()
{

}

void EndState::render()
{
	textureB->render(rectB);
	MainMenu->render();
	exit->render();
}

void EndState::handleEvents()
{

}

void EndState::goToMainMenu(Game* game)
{

}

void EndState::exitGame(Game* game)
{

}
