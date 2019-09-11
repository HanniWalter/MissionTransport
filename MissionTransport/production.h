#pragma once
#include <vector>
//#include "enums.h"
#include "Fabric.h"



; class Stock;
class Production
{
	std::vector<int> inint;
	std::vector<int> outint;
	std::vector<Good> ingood;
	std::vector<Good> outgood;
public:
	Production();
	Production(int pre);
	~Production();
	void produce(Stock* inStock, Stock* outStock);
};

