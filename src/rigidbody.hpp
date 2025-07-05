#pragma once
#include "vector2.hpp"

class RigidBody {
public:
    Vector2 position;
    Vector2 velocity;
    Vector2 acceleration;
    float mass;

    // Constructor
    RigidBody(float mass = 1.0f, Vector2 position = Vector2());

    // Physics methods
    void applyForce(const Vector2& force);
    void update(float dt);
    void checkGroundCollision(float restitution = 0.5f);
    void checkWallCollision(float minX, float maxX, float restitution = 0.5f);
    void applyAirDrag(float dragCoefficient);
    void applyGroundFriction(float frictionCoefficient);
};
