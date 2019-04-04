#pragma once;
#include "Main.cpp"

class Line;
class Intersection;
class Track;
class Vehicle

{
private:
	Line* line;
	int positionLine;
	int positionTrack;
	Intersection* lastIntersection;
	Track* lastTrack;
	int speed;

public:
	Vehicle();
	~Vehicle();
	void updateVehicle(int tick);


	int getX();
	int getY();
	int getD();

	void setLine(Line* l,int positionLine);


};

