#include "PauseState.h"

PauseState::PauseState(Game* game, string _menuID, Texture* t, Vector2D p, int w, int h, MenuButton* rB, MenuButton* sB, MenuButton* mB) : MenuGameState(game, _menuID, t, p, w, h), resume(rB), save(sB), MainMenu(mB)
{
	/*rectResume.x = 245; rectResume.y = 200; rectResume.w = BUTTON_WIDTH; rectResume.h = BUTTON_HEIGHT;
	rectSave.x = 245; rectSave.y = 350; rectSave.w = BUTTON_WIDTH; rectSave.h = BUTTON_HEIGHT;
	rectMainMenu.x = 245; rectMainMenu.y = 500; rectMainMenu.w = BUTTON_WIDTH; rectMainMenu.h = BUTTON_HEIGHT;*/
}

void PauseState::update()
{

}

void PauseState::render()
{
	textureB->render(rectB);
	resume->render();
	save->render();
	MainMenu->render();
}

void PauseState::handleEvents()
{

}

void PauseState::resumeGame(Game* game)
{
	game;
}

void PauseState::saveGame(Game* game)
{
	game->;
}

void PauseState::goToMainMenu(Game* game)
{

}