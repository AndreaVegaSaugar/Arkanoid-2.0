#pragma once
#include <exception>
#include <stdexcept>

using namespace std;

// Clase padre de las excepciones definidas en la practica

class ArkanoidError : public logic_error
{
public:
	ArkanoidError(const string& s) : logic_error("Arkanoid error: " + s) {};
};
