#pragma once
#include "ArkanoidError.h"

// Clase FILEFORMATERROR que hereda de ARKANOIDERROR
class FileFormatError : public ArkanoidError
{
public:
	FileFormatError(const string& s) : ArkanoidError("File format error: " + s) {};
};

