#pragma once
#include "Intersection.h"
class Station :
	public Intersection
{
public:
	Station();
	Station(int X, int Y, std::string pic);
	Station(int X, int Y);
	~Station();
};