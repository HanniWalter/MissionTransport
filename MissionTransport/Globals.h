#pragma once
#include "World.h"
#include "Display.h"
#include <vector>
#include "production.h"

Display* GlobalDisplay;

std::vector<Production> GlobalProduction;

bool GSDisplayLoadet = false;
bool GSRunning = false;
bool GSTicking = false;