#include <iostream>
#include "vector2.hpp"
#include "rigidbody.hpp"

int main(){
	Vector2 a(3.0f,4.0f);
	Vector2 b(1.0f, 2.0f);

	Vector2 sum=a+b;
	Vector2 diff=a-b;
	Vector2 scaled=a*2.0f;

	std::cout<<"Sum: ("<<sum.x<<", "<<sum.y <<")\n";
	std::cout<<"Diff:("<<diff.x<<", "<<diff.y<<")\n";
	std::cout<<"Scaled: ("<<scaled.x<<", "<<scaled.y<<")\n";

	std::cout<<"Length of a: "<<a.length()<<"\n";

	Vector2 norm=a.normalized();
	std::cout<<"Normalized a: (" <<norm.x<<", "<<norm.y<<")\n";

	std::cout<<"\n--- RigidBody Simulation ---\n";

	RigidBody body(2.0f, Vector2(0.0f, 0.0f)); //Mass=2kg
	Vector2 gravity(0.0f, -9.8f); //gravity
	
	for (int i=0; i<5; ++i){
		body.applyForce(gravity * body.mass);
		body.update(1.0f);

		std::cout<<"Time: "<<(i+1)<<"s-Position: ("
			<<body.position.x<<", "<<body.position.y<<")\n";
	}
	return 0;
}
