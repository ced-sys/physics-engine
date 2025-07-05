#include <SDL2?SDL.h>
#include <chrono>
#include <thread>
#include "rigidbody.hpp"
#include "visualizer.cpp"

int main(){
	SDL_Init(SDL_INIT_VIDEO);
	SDL_Window* window=SDL_CreateWindow("Physics Engine,
			SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
			WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
	SDL_Renderer* renderer=SDL_CreateRenderer(window, -1, SDL_RENDER_ACCELERATED);
	RigidBody body(1.0f, Vector2(20.0f, 20.0f));
	body.velocity=Vector2(2.0f, 0.0f);
	Vector2 gravity(0.0f, -9.8f);

	bool running=true;
	SDL_Event event;

	const float dt=0.016f; //~60FPS
	
	while(running){
		while(SDL_PollEvent(&event)){
			if (event.type==SDL_QUIT) running=false;
		}

		//Physics
		body.applyForce(gravity* body.mass);
		body.applyAirDrag(0.1f);
		body.applyGroundFriction(0.2f);
		body.update(dt);
		body.checkGroundCollision(0.6f);
		body.checkWallCollision(0.0f, 40.0f, 0.6f);

		render(body, renderer);
		std::this_thread::sleep_for(std::chrono::milliseconds(16));
	}

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}

