#include<iostream>
using namespace std;

class Inventory {
protected:
	int quantity;
	double price;

public:
	Inventory(int quantity, double price) : quantity(quantity), price(price) {}

	virtual void buy(int quantity) = 0;
	virtual void sell(int quantity) = 0;
	virtual void display() = 0;
};