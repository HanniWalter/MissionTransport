#pragma once
#include <vector>
#include "Enums.h"

class Fabric;
class Stock 
{
	StockTyp stocktyp;
	bool CombinedStock;
	int capacity;
	std::vector<Good> listofGoods;
	std::vector<int> listofAmmount;
	Good OnlyGood;
	int onlyamount;
	//Fabric* destination;

	void add(int c, Good g);
	void take(int c, Good g);
public:
	Stock();
	Stock(StockTyp st, Good Good, int capacity);
	~Stock();
	static Stock fabricStock(int capacity);

	void printStock();
	
	int load(int, Good);
	int unload(int, Good);
	int check(Good);
	int checkCapacity(Good g);


};