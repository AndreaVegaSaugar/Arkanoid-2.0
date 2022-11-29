#pragma once
#include "ArkanoidError.h"

class FileFormatError : public ArkanoidError
{
public:
	FileFormatError(const string& s) : ArkanoidError("File format error: " + s) {};
};

