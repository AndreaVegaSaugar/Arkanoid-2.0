#include "GameState.h"
#include "Game.h"
void GameState:: update() {
			
		for (auto it = gameObjects.begin(); it != gameObjects.end() && !deleted;) {
				(*it)->update();
				if (!deleted) ++it;
				else return;
				//++it;
		}
			
};

void GameState::render() const {
			
		for (auto it = gameObjects.begin(); it != gameObjects.end() && !deleted;) {
				(*it)->render();
				if (!deleted) ++it;
				else return;
				//++it;
		}
			
};

void GameState::handleEvent(SDL_Event event) {
		
	for (auto it = gameObjects.begin(); it != gameObjects.end() && !deleted;) {
			(*it)->handleEvent(event);
			 if (!deleted) ++it;
			 else return;
			 //++it;
	}
		
};

