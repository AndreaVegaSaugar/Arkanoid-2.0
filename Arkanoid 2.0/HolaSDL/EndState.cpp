#include "EndState.h"

EndState::EndState(Game* game, string _menuID, Texture* t, Vector2D p, int w, int h, MenuButton* mB, MenuButton* eB) : MenuGameState(game, _menuID, t, p, w, h), MainMenu(mB), exit(eB)
{
	/*rectMainMenu.x = 245; rectMainMenu.y = 200; rectMainMenu.w = BUTTON_WIDTH; rectMainMenu.h = BUTTON_HEIGHT;
	rectExit.x = 245; rectExit.y = 350; rectExit.w = BUTTON_WIDTH; rectExit.h = BUTTON_HEIGHT;*/
}

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
