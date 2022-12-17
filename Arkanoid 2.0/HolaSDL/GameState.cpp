#include "GameState.h"
#include "Game.h"
void GameState:: update() {
	for (auto it = gameObjects.begin(); it != gameObjects.end();) {
		(*it)->update();
		if (*it == nullptr) it = gameObjects.erase(it);
		else ++it;
	}
};

void GameState::render() const {
	 
	for (auto it = gameObjects.begin(); it != gameObjects.end(); ++it) {
		(*it)->render();
	}
};

void GameState::handleEvent(SDL_Event event) {
	for (auto it = gameObjects.begin(); it != gameObjects.end(); ++it) {
		(*it)->handleEvent(event);
	}
};
