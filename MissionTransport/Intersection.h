#pragma once

#include "GameObject.h"
#include <vector>
#include <set>


class Track;
class Intersection :
	public GameObject
{
private:
	std::vector<Track*> tracks;
	bool checkConection(Intersection* goal, std::vector<Intersection*>* ListOfUsedStations);
	int lengthOfTracks(std::vector<Track*> tracks);
	int lengthOfTracks(std::vector<Intersection*>);
public:
	Intersection();
	Intersection(int X, int Y, std::string pic);
	Intersection(int X, int Y);
	~Intersection();
	void printIntersection();
	std::vector<Track*> getTracks();
	void addTrack(Track* t);
	void remove(Track* t);

	Track* getNextTrack(Intersection* goal);
	//std::vector<Intersection*> getNextIntersections(Intersection* goal);
	std::vector<Track*> getNextTracks(Intersection* goal);//need
	//Intersection* getNextIntersection(Intersection* goal);
	bool checkConection(Intersection* goal);
};
