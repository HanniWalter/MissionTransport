#include "Track.h"




int Track::getLengthPart(int part)
{
	part = part % (points.size() - 2);
	int x1 = points.at(part).at(0);
	int y1 = points.at(part).at(1);
	int x2 = points.at(part + 1).at(0);
	int y2 = points.at(part + 1).at(1);
	return sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2));
}

int Track::getTrackProgressDiv(int position)
{
	position %= this->getLentgh();
	int returner = 0;
	while (position>=0)
	{
		position -= getLengthPart(returner);
		returner++;
	}
	return returner - 1;
}

int Track::getTrackProgressMod(int position)
{
	position %= this->getLentgh();
	for (int i = 0; i < getTrackProgressDiv(position); i++)
	{
		position -= getLengthPart(i);
	}
	return position;
}

Track::Track(std::vector<std::vector<int>> points, Intersection* i1, Intersection* i2)
{
	this->points = points;
	this->i1 = i1;
	this->i2 = i2;
	
}

Track::Track()
{
}

Track::~Track()
{
}

std::vector<std::vector<int>> Track::getPoints()
{
	return points;
}

Intersection* Track::geti1()
{
	return i1;
}

Intersection* Track::geti2()
{
	return i2;
}

Intersection* Track::getOtherEnd(Intersection* i)
{
	if (i==i1) {
		return i2;
	}
	if (i == i2) {
		return i1;
	}
	return nullptr;
}

unsigned int Track::getLentgh()
{
	int returner = 0;
	for (int i = 0;i<points.size()-1;i++)
	{
		returner += getLengthPart(i);
	}
	return returner;
}

float Track::getX(int position)
{
	int part = getTrackProgressDiv(position);
	int x1 = points.at(part).at(0);
	int x2 = points.at(part + 1).at(0);
	float progress =(getLengthPart(part) / getTrackProgressMod(position) );
	return x1 + x2 * progress;
}

float Track::getY(int position)
{
	int part = getTrackProgressDiv(position);
	int y1 = points.at(part).at(0);
	int y2 = points.at(part + 1).at(0);
	float progress = (getLengthPart(part) / getTrackProgressMod(position));
	return y1 + y2 * progress;
}

int Track::getD(int position)
{
	int part = getTrackProgressDiv(position);
	int x1 = points.at(part).at(0);
	int y1 = points.at(part).at(1);
	int x2 = points.at(part + 1).at(0);
	int y2 = points.at(part + 1).at(1);
	return atan2(x1-x2,y1-y2)/3.14159265*180 ;
}
