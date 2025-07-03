#include "rigidbody.hpp"

RigidBody::RigidBody(float mass, Vector2 position)
	:mass(mass), position(position), velocity(0, 0), acceleration(0, 0) {}

void RigidBody::applyForce(const Vector2& force){
	acceleration=acceleration+(force *(1.0f /mass));
}

void RigidBody::update(float dt) {
	velocity=velocity+acceleration*dt;
	position=position+velocity*dt;
	acceleration=Vector2(0, 0); //Reset after each update
}
