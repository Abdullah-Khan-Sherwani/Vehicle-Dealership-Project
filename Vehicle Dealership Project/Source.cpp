#include "customers-employees.h.cpp"
#include "vehicle_file.h.cpp"
#include "inventory.h.cpp"
#include "tools.h.cpp"
#include "Accounts-T.h.cpp"
vehicles vehicle;

int main() {
	map<string, vector<string>> CompanyLog;   /*Will store information of all sales with customer mail as key. Will be used by employees only*/

	cout << "====== Welcome to HAT Dealership sponsored by Ibad Bhai ======\n";
	cout << "Create an account to continue: \nEnter 1 if you are an employee and 2 if you are a customer: ";
	int acctype; cin >> acctype;

	switch (acctype) {
	case 1: {
		Account* emp = Employee::signup();
		break;
	}
	case 2: {
		Account* cust = Customer::signup();
		break;
	}
	}


}