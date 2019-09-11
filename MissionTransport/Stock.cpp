#include "Stock.h"
#include "Enums.h"
#include "Util.h"

#include "Fabric.h"

void Stock::add(int c, Good g)
{
	if (CombinedStock==true) {
		for (int i = 0; i < listofAmmount.size(); i++) {
			if (listofGoods.at(i) == g) {
				listofAmmount.at(i) += c;
				return;
			}
		}
		listofGoods.push_back(g);
		listofAmmount.push_back(c);
		return;
	}
	else
	{
		OnlyGood = g;
		onlyamount += c;
	}
}

void Stock::take(int c, Good g)
{
	if(CombinedStock){
		for (int i = 0; i < listofAmmount.size(); i++) {
			if (listofGoods.at(i) == g) {
				listofAmmount.at(i) -= c;
				if (listofAmmount.at(i) == 0) {
					listofGoods.erase(listofGoods.begin()+i);
					listofAmmount.erase(listofAmmount.begin()+i);
				}
				return;
			}
		}
	}
	else
	{
		onlyamount -= c;
		if (onlyamount == 0) {
			OnlyGood = None;
		}
	}
}

Stock::Stock()
{
}


Stock::Stock(StockTyp st, Good Good, int capacity)//for trailers
{
	this->stocktyp = st;
	this->OnlyGood = Good;
	this->capacity = capacity;
	
}

Stock::~Stock()
{
}

Stock Stock::fabricStock(int capacity)
{
	Stock f;
	f.stocktyp = All;
	f.CombinedStock = true;
	f.capacity = capacity;
	f.listofGoods = {};
	f.listofAmmount = {};
	return f;
}

void Stock::printStock()
{
	print("Stocktyp:	");
	print(enumToSting(stocktyp));
	
	
	if (CombinedStock) {
		println("	Combined");
		for (int i = 0; i < listofGoods.size();i++) {
			print(enumToSting(listofGoods.at(i)));
			print(":	");
			println(listofAmmount.at(i));
		}
		if (listofGoods.size() == 0) {
			println("empty");
		}
	}
	else
	{
		println("	Not Combined");
		print(enumToSting(OnlyGood));
		print(":	");
		println(onlyamount);
	}

	//std::string t();
	//t << stocktyp;
	//print();
}

int Stock::load(int c, Good g)
{
	c = min(c, checkCapacity(g));
	if (c > 0) { this->add(c, g); }
	return c;
}

int Stock::unload(int c, Good g)
{
	c = min(c,check(g));
	if(c>0){ this->take(c, g); }
	return c;
}

int Stock::check(Good g)
{
	if (CombinedStock) {
		for (int i = 0; i < listofGoods.size(); i++)
		{
			if (listofGoods.at(i) == g) {
				return listofAmmount.at(i);
			}
		}
		return 0;
	}
	else {
		if (OnlyGood==g) {
			return onlyamount;
		}
		return 0;
	}
}

int Stock::checkCapacity(Good g)//should work, not testet
{
	if(CombinedStock){
		int r = 0;
		if ((!stocktyp==GoodToStockTyp(g))&&(!stocktyp==All)) {
			return 0;
		}
		for (int i = 0; i < listofGoods.size(); i++)
		{
			r += listofAmmount.at(i);
		}
		return capacity - r;
	}
	else 
	{
		if ((!stocktyp == GoodToStockTyp(g)) && (!stocktyp == All)) {
			return 0;
		}
		else
		{
			return capacity - onlyamount;
		}
	}
}
