#include "Station.h"



Station::Station()
{
}

Station::Station(int X, int Y,std::string pic)
{
	Intersection(X, Y, pic);
}

Station::Station(int X, int Y)
{
	this->setX(X);
	this->setY(Y);
	this->setPic( std::string("STATION"));
}

Station::~Station()
{
}

void Station::printStation()
{
	printIntersection();
}
