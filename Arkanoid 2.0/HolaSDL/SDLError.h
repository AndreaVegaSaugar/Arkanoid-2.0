#pragma once
#include "ArkanoidError.h"

class SDLError : public ArkanoidError
{
public:
public:
	SDLError(const string& s) : ArkanoidError("SDL error: " + s) {};
};

