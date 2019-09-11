#include "Fabric.h"
#include "production.h"
#include "Util.h"

Fabric::Fabric()
{
}

Fabric::Fabric(int x, int y, int cin, int cout, std::vector<std::vector<int>> p)
{
	GameObject(x,y);
	this->a = Stock::fabricStock(cin);
	this->b = Stock::fabricStock(cout);
	this->productions = p;
}

Fabric::~Fabric()
{
}

void Fabric::printFabric()
{
	printGameObject();
	print("Instock:  ");
	a.printStock();
	print("Outstock: ");
	b.printStock();
}

void Fabric::update(int k)
{
	if (k > 5)
	{
		for (int i = 0; i < productions.size(); i++) {
			int pi = productions.at(i).at(0);
			Production p = productions.at(i).at(0);
			for (int j = 0; j < pi;j++) p.produce(&a, &b);
		}
	}
}
 
int Fabric::load(int i, Good g)
{
	return a.load(i,g);	
}

int Fabric::unload(int i, Good g)
{
	return b.unload(i,g);
}


