#include <string>
#include <iostream>
#include "Util.h"


std::string inputString(std::string out) {
	std::cout << out << std::endl;
	std::string returner;
	std::cin >> returner;
	return returner;
}

int inputInt(std::string out) {
	std::cout << out << std::endl;
	int returner;
	std::cin >> returner;
	return returner;
}

void println(std::string out) {
	std::cout << out << std::endl;
}

void println(int out) {
	std::cout << out << std::endl;
}

void print(std::string out) {
	std::cout << out;
}

void print(int out) {
	std::cout << out;
}

int d(int x1, int x2, int y1, int y2)
{
	return sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2));
}


int min(int a, int b) {
	if (a > b)return b;
	return a;
}

int max(int a, int b) {
	if (a < b)return b;
	return a;
}

std::string enumToSting(Good g)
{
	switch (g)
	{
	case None:
		return "NONE";
	case Coal:
		return "Coal";
	case Iron:
		return "Iron";
	default:
		return "enumToStringIncomplete";
	}
	return std::string();
}

std::string enumToSting(StockTyp g)
{
	switch (g)
	{
	case All:
		return "All";
	case Liquid:
		return "Liquid";
	case Bulk:
		return "Bulk";
	default:
		return "enumToStringIncomplete";
	}
}

StockTyp GoodToStockTyp(Good g)
{
	switch (g)
	{
	case Coal:
		return Bulk;
		break;
	case Iron:
		return Bulk;
		break;
	default:
		break;
	};
}

std::vector<GameObject*> getInRange(int range, GameObject center, std::vector<GameObject> input)
{
	int x1 = center.getX();
	int y1 = center.getY();
	std::vector<GameObject*> returnlist;
	for (int i = 0; i < input.size(); i++) {
		int x2 = input.at(i).getX();
		int y2 = input.at(i).getY();
		
		if (d(x1, x2, y1, y2) <= range) {
			returnlist.push_back(&input.at(i));
		}
	}
	return returnlist;
}


