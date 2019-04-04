#pragma once
#include <list>
#include <vector>
#include <stdio.h> 
#include <iostream>
#include "DateTime.h"
#include "Station.h"
#include "GameObject.h"
#include "Track.h"

class World
{
private:
	int MaxX;
	int MaxY;
	DateTime dateTime;
	int speedMultiplier = 60000;

	std::vector<Station> stations;
	std::vector<Intersection> intersections;
	std::vector<Track> tracks;

public:
	World();
	World(int Pre);
	~World();
	int update(int ticktime);
	std::vector<Station> getStations();
	std::vector<Intersection> getIntersections();
	std::vector<Track> getTracks();
	int addStation(Station s);
	int addStation(int x, int y);
	int addIntersection(Intersection i);
	int addIntersection(int x, int y);
	int addTrack(Track t);
	int addTrack(std::vector<std::vector<int>>);
	int addTrack(Intersection i1, std::vector<std::vector<int>> points, Intersection i2);
	int addTrack(std::vector<std::vector<int>> points, Intersection i1, Intersection i2);

};