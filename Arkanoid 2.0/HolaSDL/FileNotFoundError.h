#pragma once
#include "ArkanoidError.h"

class FileNotFoundError : public ArkanoidError
{
public:
	FileNotFoundError(const string& s) : ArkanoidError("file not found error: " + s) {};
	virtual const char* what() const throw()
	{
		return "We couldnt find the file:  ";
	};
};

