#include <SDL2/SDL.h>
#include "rigidbody.hpp"

const int WINDOW_WIDTH=800;
const int WINDOW_HEIGHT=600;

void render(RigidBody& body, SDL_Renderer* renderer) {
	//Convert physics coordinates to screen space
	int x= static_cast<int>(body.position.x * 20); //Scale
	int y=WINDOW_HEIGHT-static_cast<int>(body.position.y* 20); //invert y

	SDL_SetRenderDrawColor(renderer, 30, 30, 30, 255); //Dark background

	SDL_RenderClear(renderer);

	//Draw the ball
	SDL_SetRenderDrawColor(renderer, 255, 100, 100, 255);
	SDL_Rect ball={x-10, y-10, 20, 20};
	SDL_RenderFillRect(renderer, &ball);

	SDL_RenderPresent(renderer);
}
