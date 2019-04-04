#include "Display.h"

int Display::paintObjects()
{
	for (int i = 0; i < world->getTracks().size(); i++)
	{
		paintTrack(world->getTracks().at(i));
	}
	for (int i = 0; i < world->getIntersections().size(); i++)
	{
		paintObject(world->getIntersections().at(i));
	}
	return 0;
}

int Display::paintObject(GameObject object)
{
	if (object.getpicture() == std::string("STATION"))
	{
		filledCircleColor(renderer, object.getX(), object.getY(), 10, 0xff0000ff);
		filledCircleColor(renderer, object.getX(), object.getY(), 8, BACKGROUND);
	}
	return 0;
}

int Display::paintTrack(Track t)
{
	for (int i = 0; i < t.getPoints().size()-1; i++)
	{
		thickLineColor(renderer, 
			t.getPoints().at(i).at(0), 
			t.getPoints().at(i).at(1), 
			t.getPoints().at(i + 1).at(0), 
			t.getPoints().at(i + 1).at(1), 
			4, 
			0xff0000ff);
	}
	return 0;
}


int Display::init()
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		throw std::string("SDL could not Initialize!");
	}
	window = SDL_CreateWindow("MissionTransport", 100, 100, 500, 500, SDL_WINDOW_SHOWN);//TODO Fullscreen or so
	if (window == NULL) {
		throw std::string("Window could not be created!");
	}
	//int imgFlags = IMG_INIT_PNG;
	//if (!(IMG_Init(imgFlags) & imgFlags)) {
	//	throw std::string("SDL_image could not initialize!");
	//}
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (renderer == NULL) {
		throw std::string("SDL_surface could not created!");
	}
	surface = SDL_GetWindowSurface(window);
	return 0;
}


Display::Display()
{
}

Display::Display(World* world)
{
	this->world = world;
	try
	{
		init();
	}
	catch (std::string ex)
	{
		std::cout << ex;
	}
}

Display::~Display()
{
	//Destroy window 
	SDL_DestroyWindow(window); 
	//Quit SDL subsystems 
	SDL_Quit(); 
}

int Display::render()
{
	SDL_RenderClear(renderer);
	SDL_SetRenderDrawColor(renderer, 0xE0, 0xE0, 0xE0, 0xFF);
	SDL_RenderClear(renderer);
	paintObjects();
	SDL_RenderPresent(renderer);	
	return 0;
}