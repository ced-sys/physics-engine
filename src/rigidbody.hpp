#pragma once
#include "vector2.hpp"

class RigidBody{
public:
	Vector2 position;
	Vector2 velocity;
	Vector2 acceleration;
	float mass;

	RigidBody(float mass=1.0f, Vector2 position=Vector2());

	void applyForce(const Vector2& force);
	void update(float dt);
};
