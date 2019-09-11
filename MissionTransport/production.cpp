#include "production.h"
#include "Stock.h"


Production::Production()
{
}

Production::Production(int pre)
{
	if (pre == 1) {
		this->outgood = { Coal };
		this->outint = { 1 };
	}
	if (pre == 2) {
		this->ingood = { Coal };
		this->inint = { 1 };
	}
}


Production::~Production()
{
}

void Production::produce(Stock* inStock, Stock* outStock)
{
	bool p = true;
	//check
	for (int i = 0; i < inint.size(); i++) {
		if (inStock->check(ingood.at(i)) < inint.at(i)) p = false;
	}

	for (int i = 0; i < outint.size(); i++) {
		if (outStock->checkCapacity(outgood.at(i)) < outint.at(i)) p = false;
	}
	//maybe cancel
	if (!p) return;
	//produce
	for (int i = 0; i < ingood.size(); i++) {
		inStock->unload(inint.at(i), ingood.at(i));
	}
	for (int i = 0; i < outgood.size(); i++) {
		outStock->load(outint.at(i),outgood.at(i));
	}
}
