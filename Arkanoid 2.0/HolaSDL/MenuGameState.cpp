#include "MenuGameState.h"

MenuGameState::MenuGameState(Game* game): GameState(game)
{
	rectBack.x = 0; rectBack.y = 0; rectBack.w = WIN_WIDTH; rectBack.h = WIN_HEIGHT;
}

void MenuGameState::render() const {
	// Si falla el pause poner if de si background es igual a null
	if(background != nullptr)background->render(rectBack);
	GameState::render();
}
