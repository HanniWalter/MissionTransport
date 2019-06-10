#pragma once
#include "World.h"
#include "Display.h"

World* GlobalWorld;
Display* GlobalDisplay;


int GSDisplayMode; // 1 = console only 2 = display
bool GSDisplayLoadet = false;
bool GSWorldLoadet = false;
bool GSRunning = false;
bool GSTicking = false;