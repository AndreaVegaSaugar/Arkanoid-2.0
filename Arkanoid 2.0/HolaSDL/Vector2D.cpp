#include "checkML.h"
#include "Vector2D.h"

using namespace std;

double Vector2D::module()
{
	return sqrt((pow(x, 2) + (pow(y, 2))));
}

Vector2D Vector2D::normalize()
{
	return Vector2D(x / module(), y / module());
}

Vector2D Vector2D::operator+(const Vector2D& v1) const
{
	return Vector2D(v1.x + x, v1.y + y);
}

Vector2D Vector2D::operator-(const Vector2D& v1) const
{
	return Vector2D(x - v1.x, y - v1.y);
}

Vector2D Vector2D::operator*(double d) const
{
	return Vector2D(x * d, y * d);
}

double Vector2D::operator*(const Vector2D& v1) const
{
	return (v1.x * x + v1.y * y);
}
