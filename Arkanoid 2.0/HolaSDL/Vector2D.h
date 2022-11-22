#pragma once
#include "checkML.h"
#include <vector>
#include <math.h>

using namespace std;

class Vector2D
{
private:
	double x;
	double y;

public:
	Vector2D() : x(0), y(0) {};
	Vector2D(double X, double Y) : x(X), y(Y) {};
	double getX() const { return x; };
	double getY() const { return y; };
	void addX(int n) { x += n; }
	void addY(int n) { y += n; }
	double module();
	void normalize();

	Vector2D operator+(const Vector2D& v) const;
	Vector2D operator-(const Vector2D& v) const;
	Vector2D operator*(double d) const;
	double operator*(const Vector2D& v) const;
};
