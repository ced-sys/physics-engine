#include "vector2.hpp"

Vector2::Vector2(float x, float y) : x(x), y(y) {}

Vector2 Vector2::operator+(const Vector2& other) const{
	return Vector2(x+other.x, y+other.y);
}

Vector2 Vector2::operator-(const Vector2& other) const{
	return Vector2(x-other.x, y-other.y);
}

Vector2 Vector2::operator*(float scalar) const{
	return Vector2(x* scalar, y* scalar);
}

float Vector2::length() const{
	return std::sqrt(x*x+y*y);
}

Vector2 Vector2::normalized() const{
	float len=length();
	if (len==0.0f) return Vector2(0.0f, 0.0f);
	return Vector2(x/len, y/len);
}

