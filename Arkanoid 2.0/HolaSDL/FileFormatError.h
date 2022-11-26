#pragma once
#include "ArkanoidError.h"

class FileFormatError : public ArkanoidError
{
public:
	FileFormatError(const string& s) : ArkanoidError("file format error: " + s) {};
	virtual const char* what() const throw()
	{
		return "A File Format Error has happened in: ";
	};
};

