#include "World.h"		


std::optional<std::shared_ptr<World>> World::instance = {};

World::World()
{

}

void World::create()
{
	World world = *this;
	//std::optional<World> optional = world;
	instance = std::make_shared<World>( world);
}


World::World(int MaxX, int MaxY, DateTime dateTime, int speedMultiplier, std::vector<Station> stations, std::vector<Intersection> intersections, std::vector<Track> tracks, std::vector<Fabric> fabrics)
{
	this->MaxX=MaxX;
	this->MaxY=MaxY;
	this->dateTime=dateTime;
	this->speedMultiplier = speedMultiplier;
	this->stations = stations;
	this->intersections = intersections;
	this->tracks = tracks;
	this->fabrics;
	create();
}

World::~World()
{
}

std::optional<std::shared_ptr<World>> World::getInstance()
{
	return World::instance;
}

void World::createFormPreset(int Pre){

	{
		if (Pre == 1) {
			World(100, 100, DateTime(2000, 1, 1, 9, 0, 0, 0), 6000, {}, {}, {}, {});

			std::shared_ptr<World> wptr = getInstance().value();
			wptr->addStation(100, 100);
			wptr->addStation(300, 100);
			wptr->addStation(200, 300);

			wptr->addTrack(wptr->getStations().at(2), { {300,300} }, wptr->getStations().at(1));
			
		}
	}


	
}


int World::print()
{
	std::shared_ptr<Console> consoleptr = Console::getInstancePtr();

	consoleptr->print(std::to_string(MaxX) + ";" + std::to_string(MaxY) + "         " + dateTime.getDateTime());
	consoleptr->print("Stations: " + std::to_string(stations.size()));
	consoleptr->print("Intersections: " + std::to_string(intersections.size()));
	consoleptr->print("Tracks: " + std::to_string(tracks.size()));
	consoleptr->print("Fabrics: " + std::to_string(fabrics.size()));

	return 0;
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

int World::addFabric(Fabric f)
{
	return 0;
}

int World::addFabric(int x, int y, int cin, int cout, std::vector<std::vector<int>> p)
{
	Fabric f = Fabric(x,y,cin,cout,p);
	return addFabric(f);
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
