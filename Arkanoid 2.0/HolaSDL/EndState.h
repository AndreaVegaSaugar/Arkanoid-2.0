#pragma once
#include "MenuGameState.h"
class EndState :public MenuGameState
{
public:
	virtual void update();
	virtual void render() const;
	virtual void handleEvents();
};

