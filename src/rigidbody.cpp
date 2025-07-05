#include "rigidbody.hpp"

// Constructor
RigidBody::RigidBody(float m, Vector2 pos)
    : mass(m), position(pos), velocity(0.0f, 0.0f), acceleration(0.0f, 0.0f) {}

// Apply external force
void RigidBody::applyForce(const Vector2& force) {
    acceleration += force / mass;
}

// Integrate motion (Euler method)
void RigidBody::update(float dt) {
    velocity += acceleration * dt;
    position += velocity * dt;
    acceleration = Vector2(0.0f, 0.0f); // Reset for next frame
}

// Ground collision (bounce with energy loss)
void RigidBody::checkGroundCollision(float restitution) {
    if (position.y < 0.0f) {
        position.y = 0.0f;
        if (velocity.y < 0.0f)
            velocity.y = -velocity.y * restitution;
    }
}

// Air drag: F = -k * velocity
void RigidBody::applyAirDrag(float dragCoefficient) {
    Vector2 drag = velocity * -dragCoefficient;
    applyForce(drag);
}

// Ground friction (horizontal only)
void RigidBody::applyGroundFriction(float frictionCoefficient) {
    if (position.y <= 0.0f) {
        Vector2 friction = Vector2(velocity.x, 0.0f) * -frictionCoefficient;
        applyForce(friction);
    }
}

// Wall collision: left/right with restitution
void RigidBody::checkWallCollision(float minX, float maxX, float restitution) {
    if (position.x < minX) {
        position.x = minX;
        if (velocity.x < 0.0f)
            velocity.x = -velocity.x * restitution;
    } else if (position.x > maxX) {
        position.x = maxX;
        if (velocity.x > 0.0f)
            velocity.x = -velocity.x * restitution;
    }
}
