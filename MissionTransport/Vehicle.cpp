#include "Vehicle.h"
#include "Line.h"


Vehicle::Vehicle()
{
}


Vehicle::~Vehicle()
{
}

void Vehicle::updateVehicle(int tick)
{
	positionTrack += tick * speed;/////////
	if (positionTrack > lastTrack->getLentgh()) {
		lastIntersection = lastTrack->getOtherEnd(lastIntersection);
		if (lastIntersection = line->at(positionLine)) {
			positionLine++;
			positionLine %= line->getLength();
		}
		lastTrack = lastIntersection->getNextTrack(line->at(positionTrack));
	}
}

int Vehicle::getX()
{
	return lastTrack->getX(positionTrack);
}

int Vehicle::getY()
{
	return lastTrack->getY(positionTrack);
}

int Vehicle::getD()
{
	return lastTrack->getD(positionTrack);
}

void Vehicle::setLine(Line* l, int positionLine)
{
	this->line = l;
	this->positionLine = positionLine;
}