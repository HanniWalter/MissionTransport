#pragma once
#include "GameObject.h";
#include <vector>;
#include "Stock.h"

class Stock;
class Production;
class Fabric :
	public GameObject
{
private:
	std::vector<std::vector<int>> productions;
	Stock a;//input
	Stock b;//output
	Fabric();
public:
	Fabric(int x, int y, int cin, int cout, std::vector<std::vector<int>> p);
	~Fabric();
	void printFabric();
	void update(int i);//TODO	
	
	int load(int i, Good g);
	int unload(int i, Good g);
};
