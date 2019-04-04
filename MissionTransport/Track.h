#pragma once


#include "GameObject.h"
#include <vector>
#include <math.h>

class Intersection;
class Track:
	public GameObject
{
private:
	int getLengthPart(int part);
	int getTrackProgressDiv(int position);
	int getTrackProgressMod(int position);
	std::vector<std::vector<int>> points;
	Intersection* i1;
	Intersection* i2;
public:
	Track(std::vector<std::vector<int>> points, Intersection* i1, Intersection* i2);
	Track();
	~Track();
	std::vector<std::vector<int>> getPoints();
	Intersection* geti1();
	Intersection* geti2();
	Intersection* getOtherEnd(Intersection* i);
	unsigned int getLentgh();

	float getX(int position);
	float getY(int position);
	int getD(int position);
};  
