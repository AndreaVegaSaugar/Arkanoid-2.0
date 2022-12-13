#pragma once
#include "MenuGameState.h"
class MainMenuState: public MenuGameState
{
public:
	virtual void update();
	virtual void render() const;
	virtual void handleEvents() {};
};

