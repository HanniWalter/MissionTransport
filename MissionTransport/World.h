#pragma once
#include <list>
#include <vector>
#include <stdio.h> 
#include <iostream>
#include "DateTime.h"
#include "Station.h"
#include "GameObject.h"
#include "Track.h"
#include "Fabric.h"
#include <optional>
#include "console.h"
#include <optional>


//singleton but creat object at a setup methode not getInstance()
class World
{
private:
	static std::optional<std::shared_ptr<World>> instance ;


	int MaxX;
	int MaxY;
	DateTime dateTime;
	int speedMultiplier = 60000;

	std::vector<Station> stations;
	std::vector<Intersection> intersections;
	std::vector<Track> tracks;
	std::vector<Fabric> fabrics;
	World();	
	void create();
	World(int MaxX, int MaxY, DateTime dateTime, int speedMultiplier, std::vector<Station> stations, std::vector<Intersection> intersections, std::vector<Track> tracks, std::vector<Fabric> fabrics);

public:
	~World();
	static std::optional<std::shared_ptr<World>> getInstance();
	static void createFormPreset(int Pre);

	int print();
	int update(int ticktime);

	std::vector<Station> getStations();
	std::vector<Intersection> getIntersections();
	std::vector<Track> getTracks();
	std::vector<Fabric> getFabrics();

	int addFabric(Fabric f);
	int addFabric(int x, int y, int cin, int cout, std::vector<std::vector<int>> p);
	int addStation(Station s);
	int addStation(int x, int y);
	int addIntersection(Intersection i);
	int addIntersection(int x, int y);
	int addTrack(Track t);
	int addTrack(std::vector<std::vector<int>>);
	int addTrack(Intersection i1, std::vector<std::vector<int>> points, Intersection i2);

};