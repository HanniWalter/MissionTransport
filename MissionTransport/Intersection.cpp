#include "Intersection.h"
#include "track.h"


Intersection::Intersection()
{
}

Intersection::Intersection(int X, int Y, std::string pic)
{
	GameObject(X, Y, pic);
}

Intersection::Intersection(int X, int Y)
{
	Intersection(X, Y,std::string("INTERSECTION"));
}


Intersection::~Intersection()
{
}

std::vector<Track*> Intersection::getTracks()
{
	return tracks;
}

void Intersection::addTrack(Track* t)
{
	tracks.push_back(t);
}

void Intersection::remove(Track* t)
{
	for (int i = 0; i < tracks.size(); i++) {
		if (tracks.at(i) == t) {
			tracks.erase(tracks.begin()+i);
		}
	}
}

Track * Intersection::getNextTrack(Intersection * goal)
{
	return getNextTracks(goal).at(0);
}

bool Intersection::checkConection(Intersection * goal)
{
	std::vector<Intersection*> v;
	return checkConection(goal, &v);
}

bool Intersection::checkConection(Intersection * goal,std::vector<Intersection*>* ListOfUsedStations)
{
	if (this == goal) {
		return true;
	}
	ListOfUsedStations->push_back(this);

	for (int i = 0; i < tracks.size(); i++) {
		Track* hier = tracks.at(i);
		Intersection* dort = hier->getOtherEnd(this);
		
		bool IsIn = false;
		for (int i = 0; i < ListOfUsedStations->size();i++) {
			if (ListOfUsedStations->at(i)==dort)
			{
				IsIn = true;
				continue;
			}
		}
		if (!IsIn) {
			if (checkConection(dort,ListOfUsedStations)) {
				return true;
			}
		}
	}
	return false;
}

int Intersection::lengthOfTracks(std::vector<Track*> tracks)
{
	int returner = 0;
	for (int i = 0;i<tracks.size();i++)
	{
		returner += tracks.at(i)->getLentgh();
	}

	return returner;
}

std::vector<Track*> Intersection::getNextTracks(Intersection * goal)
{

	std::vector<std::vector<Track*>> possibleWays = { {} };
	std::vector<Intersection*> possibleIntersects = {this};
	std::vector<Intersection*> UsedIntersects = {this};

	//bring the best in front
	for(int i = 0; i < possibleWays.size() - 1; i++)
	{
		if (lengthOfTracks(possibleWays.at(i)) < lengthOfTracks(possibleWays.at(i + 1))) {
			auto save = possibleWays.at(i);
			possibleWays.at(i) = possibleWays.at(i+1);
			possibleWays.at(i+1) = save;
		}
	}

	//If ok return
	if (possibleIntersects[possibleIntersects.size() - 1] ==this) {
		return possibleWays[possibleIntersects.size() - 1];
	}

	//Do the interessting stuff
	Intersection* interresstingIntersect = possibleIntersects[possibleIntersects.size()-1];
	std::vector<Track*> InterestingWay = possibleWays[possibleWays.size()-1];
	possibleIntersects.pop_back();
	possibleWays.pop_back();
	for (int i = 0; i < interresstingIntersect->getTracks().size(); i++)
	{
		std::vector<Track*> newWay = InterestingWay;
		newWay.push_back(interresstingIntersect->getTracks().at(i));
		possibleWays.push_back(newWay);
	}

	return std::vector<Track*>();
}


