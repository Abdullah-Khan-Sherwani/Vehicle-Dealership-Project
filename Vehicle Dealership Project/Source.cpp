#include "vehicle_file.cpp"
//#include "inventory.h.cpp"
//#include "tools.h.cpp"
//#include "Accounts-T.h.cpp"
#include "customers-employees.h"
vehicles vehicle;
map<string, vector<string>> CompanyLog;   /*Will store information of all sales with customer mail as key. Will be used by employees only*/

// General function for switch case range check
bool isWithinRange(int number, int min, int max) {
	return (number >= min && number <= max);
}


void customerMenu(Account* acc) {
	int choice = -1;
	while (choice != 0) {
		cout << "1: Car\n2: Bike\n0: Exit\n";
		int choice; cin >> choice;
		while (isWithinRange(choice, 0, 2)) {
			cout << "Incorrect choice, enter again:\n";
			cin >> choice;
		}

		switch (choice) {

			//For Cars
		case 1: {

			bool carflag = true;
			while (carflag) {
				string vehicle_type = "C";
				system("cls");

				// Switch case for displaying cars
				cout << "1: Display all Cars\n2: Sort Cars by model\n3: Sort cars by make\n4: Sort cars by year\n5:Search Cars within price Range\n0: to exit\n";
				int displaychoice; cin >> displaychoice;
				while (isWithinRange(displaychoice, 0, 5)); {
					cout << "Incorrect choice, enter again:\n";
					cin >> displaychoice;
				}

				switch (displaychoice)
				{
				case 1: {
					vehicle.display_all_cars();
					// buy sell function here
					break;
				}
				case 2: {
					cout << "Enter Vehicle model (first letter in capital):\n";
					string model; cin >> model;
					vehicle.display_by_model(model, vehicle_type);
					// buy sell function here
					break;
				}
				case 3: {
					cout << "Enter vehicle make (first letter in capital):\n";
					string make; cin >> make;
					vehicle.display_by_make(make, vehicle_type);
					// buy sell function here
					break;
				}
				case 4: {
					cout << "Enter year to search vehicles from:\n";
					int year; cin >> year;
					vehicle.display_by_year(year, vehicle_type);
					// buy sell function here
					break;
				}
				case 5: {
					cout << "Enter upper and lower price range to seacrh vehicles from:\n";
					float upper, lower; cin >> upper >> lower;
					vehicle.display_within_price_range(lower, upper, vehicle_type);
					// buy sell function
					break;
				}
				case 0: {
					carflag = false;
					break;
				}
				}
			}
		}

		//For bikes
		case 2: {
			string vehicle_type = "B";
		}
		}
	}
}

int main() {
	vehicle.read_file();

	cout << "====== Welcome to HAT Dealership sponsored by Ibad Bhai ======\n";
	cout << "Create an account to continue: \nEnter 1 if you are an employee and 2 if you are a customer: ";
	int acctype; cin >> acctype;

	switch (acctype) {
	case 1: {
		Account* emp = Employee::test();
		break;
	}
	case 2: {
		Account* cust = Customer::signup();
		customerMenu(cust);
		break;
	}
	}


}