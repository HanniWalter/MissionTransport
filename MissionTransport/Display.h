#pragma once
#define SDL_MAIN_HANDLED
#include <stdio.h>
#include "World.h"
#include "SDL2_gfxPrimitives.h" 
#include <iostream>

#include <SDL.h>
//#include <SDL_image.h>
#include "GameObject.h"
#include "World.h"
#include <vector>
#include "Track.h"
#include <SDL_ttf.h>

class Display {
private:
	static std::shared_ptr <Display> instanceptr;

	bool displayCreationFLAG = false;

	int HEIGHT = 700;
	int WIDTH = 1500;
	int BACKGROUND = 0xF0F0F0FF;
	SDL_Window* window = NULL;
	SDL_Surface* surface = NULL;
	SDL_Renderer* renderer = NULL;
	void initSDL();

	void EventLoop();

public:
	Display();
	static std::shared_ptr <Display>  getInstancePtr();
	~Display() = default;

	bool ConsoleFLAG;

	void render();
	void renderConsole();
};

/*
extern World* GlobalWorld;
class Display
{
private:

	int paintObjects();
	int paintObject(GameObject object);
	int paintTrack(Track t);
public:
	~Display();//schlieﬂe das display todo
	int render();
};
*/