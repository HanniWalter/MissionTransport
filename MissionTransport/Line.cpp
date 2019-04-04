#include "Line.h"



Intersection* Line::at(int i)
{
	return stops.at(i);
}

Line::Line()
{
}

Line::Line(std::vector<Intersection*> stops)
{
	this->change(stops);
}


Line::~Line()
{
}

void Line::change(std::vector<Intersection*> stops)
{
	this->stops = stops;
}

std::vector<Intersection*> Line::getStops()
{
	return stops;
}

int Line::getLength()
{
	return stops.size();
}
