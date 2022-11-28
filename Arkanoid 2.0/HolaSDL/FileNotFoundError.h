#pragma once
#include "ArkanoidError.h"

class FileNotFoundError : public ArkanoidError
{
public:
	FileNotFoundError(const string& s) : ArkanoidError("File not found error: " + s) {};
};

