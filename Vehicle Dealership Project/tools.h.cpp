#include "inventory.h.cpp"

class Tools : public Inventory {
protected:
	string toolName;

public:
	Tools(string toolName, int quantity, double price) : Inventory(quantity, price), toolName(toolName) {}

	void buy(int amount) override {
		quantity += amount;
		/* Some code to reduce account balance when it is implemented*/
	}

	void sell(int amount) override {
		if (amount >= quantity) {
			cout << "Insufficient tools.\n";
			return;
		}
		quantity -= amount;
		cout << "Transaction complete\n";
		/* some code to charge the customer and increase the dealership account balance */
	}

	void display() override {
		cout << "Tool Name: " << toolName << "\n";
		cout << "Quantity: " << quantity << "\n";
		cout << "Price: " << price << "\n";
	}
};