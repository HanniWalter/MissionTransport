#include "World.h"		


World::World()
{

}

World::World(int Pre)
{
	if (Pre == 1) {
		dateTime =DateTime(2000, 1, 1, 9, 0, 0, 0);
		MaxX = 1000;
		MaxY = 1000;

		this->addStation(100, 100);
		this->addStation(300, 100);
		this->addStation(200, 300);
		
		this->addTrack(stations.at(2), { {300,300} }, stations.at(1));
	}
}

World::~World()
{
}

int World::update(int ticktime)
{
	int to_update = dateTime.addms(ticktime * speedMultiplier);
	return 0;
}

std::vector<Station> World::getStations()
{
	return stations;
}

std::vector<Intersection> World::getIntersections()
{
	return intersections;
}

std::vector<Track> World::getTracks()
{
	return tracks;
}

int World::addStation(Station s)
{
	this->stations.push_back(s);
	return 0;
}

int World::addStation(int x, int y)
{
	Station s(x, y);
	this->addStation(s);
	this->addIntersection(s);
	return 0;
}

int World::addIntersection(Intersection i)
{
	this->intersections.push_back(i);
	return 0;
}

int World::addIntersection(int x, int y)
{
	Intersection i(x, y);
	this -> addIntersection(i);
	return 0;
}

int World::addTrack(Track t)
{
	
	tracks.push_back(t);
	return 0;
}

int World::addTrack(std::vector<std::vector<int>> points)
{
	bool worked1 = false;
	bool worked2 = false;
	Intersection i1;
	Intersection i2;

	for (int i = 0; i < getIntersections().size(); i++) {
		if (getIntersections().at(i).getX() == points.at(0).at(0) &&
			getIntersections().at(i).getY() == points.at(0).at(1)) {
			i1 = getIntersections().at(0);
			worked1 = true;
		}
		if (getIntersections().at(i).getX() == points.at(points.size()-1).at(0) &&
			getIntersections().at(i).getY() == points.at(points.size()-1).at(1)) {
			i2 = getIntersections().at(i);
			worked2 = true;
		}
	}
	if (!(worked1||worked2))return 3;
	if (!worked1)return 1;
	if (!worked2)return 2;
	Track t(points, &i1,&i2);
	return addTrack(t);
}

int World::addTrack(Intersection i1, std::vector<std::vector<int>> points, Intersection i2)
{
	std::vector<std::vector<int>> newpoints;
	newpoints.push_back({ i1.getX(),i1.getY() });
	for (int i = 0; i < points.size(); i++) {
		newpoints.push_back(points.at(i));
	}
	newpoints.push_back({ i2.getX(),i2.getY() });
	Track t(newpoints, &i1, &i2);
	return addTrack(t);
}
