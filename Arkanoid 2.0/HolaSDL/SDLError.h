#pragma once
#include "ArkanoidError.h"

class SDLError : public ArkanoidError
{
public:
public:
	SDLError(const string& s) : ArkanoidError("SDL error: " + s) {};
	virtual const char* what() const throw()
	{
		return "An SDL error occurred";
	};
};

