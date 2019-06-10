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

extern World* GlobalWorld;
class Display
{
private:
	int BACKGROUND = 0xF0F0F0FF;

	SDL_Window* window = NULL;
	SDL_Surface* surface = NULL;
	SDL_Renderer* renderer = NULL;
	World* world;

	int paintObjects();
	int paintObject(GameObject object);
	int paintTrack(Track t);
	int init();
public:
	Display();
	//Display(World* world);
	~Display();
	int render();
};