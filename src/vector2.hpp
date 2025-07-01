#pragma once
#include <cmath>

struct Vector2{
	float x, y;

	Vector2(float x=0.0f, float y=0.0f);

	Vector2 operator+(const Vector2& other) const;
	Vector2 operator-(const Vector2& other) const;
	Vector2 operator*(float scalar) const;

	float length() const;
	Vector2 normalized() const;
};


