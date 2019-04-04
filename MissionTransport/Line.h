#pragma once
#include <vector>
#include "Intersection.h"

class Line
{
private:
	std::vector<Intersection*> stops;
public:
	Intersection* at(int i);
	Line();
	Line(std::vector<Intersection*> stops);
	~Line();

	void change(std::vector<Intersection*>);

	std::vector<Intersection*> getStops();
	int getLength();
};

