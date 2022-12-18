#pragma once
#include "ArkanoidError.h"

// Clase SDLERROR que hereda de ARKANOIDERROR
class SDLError : public ArkanoidError
{
public:
public:
	SDLError(const string& s) : ArkanoidError("SDL error: " + s) {};
};

