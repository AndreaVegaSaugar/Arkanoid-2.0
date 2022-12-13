#pragma once
#include "MenuGameState.h"
class PauseState:public MenuGameState
{
private:
	static const string s_pauseID;
public:
	virtual void update() {};
	virtual void render() const {};
	virtual void handleEvents() {};
	virtual string getStateID() const { return s_pauseID; }

	PauseState():MenuGameState() {};
	~PauseState() {};
};

