#pragma once
#include "GameObject.h"

class MenuButton : public GameObject
{
private:
	Texture* texture = nullptr;

public:
	void handleEvents();
};

