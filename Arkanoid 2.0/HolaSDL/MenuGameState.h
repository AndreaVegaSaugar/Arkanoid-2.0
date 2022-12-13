#pragma once
#include "GameState.h"
class MenuGameState: public GameState
{
private:
	static const string s_menuID; 
public:
	virtual void update();
	virtual void render() const;
	virtual string getStateID() const { return s_menuID; }
};

