#pragma once
#include "ArkanoidError.h"

// Clase FILENOTFOUNDERROR que hereda de ARKANOIDERROR
class FileNotFoundError : public ArkanoidError
{
public:
	FileNotFoundError(const string& s) : ArkanoidError("File not found error: " + s) {};
};

