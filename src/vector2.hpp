#pragma once
#include <cmath>

struct Vector2{
	float x, y;

	Vector2(float x=0.0f, float y=0.0f);

	Vector2 operator+(const Vector2& other) const;
	Vector2 operator-(const Vector2& other) const;
	Vector2 operator*(float scalar) const;
	Vector2 operator+=(const Vector2& other);
	Vector2 operator*=(float scalar);
	Vector2 operator/(float scalar) const;

	float length() const;
	Vector2 normalized() const;
};

// Non-member function for scalar * Vector2
Vector2 operator*(float scalar, const Vector2& vec);
