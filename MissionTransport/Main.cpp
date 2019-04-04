#include "Display.h"
#include "World.h"
#include <chrono>
//#include "SDL.h"

int main(int iHate, char* SDL[]) {

	World world = World(1);
	Display display(&world);
	//Event handler for GameEvennts

	//refferenzzeit möglichst nah an der Gameloop
	std::chrono::high_resolution_clock::time_point Oldtime = std::chrono::high_resolution_clock::now();
	// gameloop
	for (;;) {
		//Tick
		std::chrono::high_resolution_clock::duration ticktime = std::chrono::high_resolution_clock::now() - Oldtime;
		unsigned int tick = std::chrono::duration_cast<std::chrono::microseconds>(ticktime).count();
		Oldtime = std::chrono::high_resolution_clock::now();

		//update all objects
		world.update(tick);

		//render display
		display.render();
	}

	return 42;
}