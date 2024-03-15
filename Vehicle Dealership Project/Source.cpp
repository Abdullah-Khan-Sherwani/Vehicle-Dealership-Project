#include<iostream>
#include<cstdlib>
#include<string>
#include<vector>
#include<iomanip>
#include "Accounts14,3.h.cpp"
using namespace std;
double wallet = 100000;

int main() {
    vector<Account*> accounts;
    int choice;
    do {
        cout << "1. Sign up\n2. Login\n3. Exit\n\n";
        cin >> choice;
        switch (choice) {
        case 1:
            accounts.push_back(Account::signup());
            break;
        case 2: {
            Account* accptr = Account::login(accounts);
            if (accptr != nullptr) {
                cout << "Welcome, " << accptr->name << "!\n";
            }
            break;
        }
        case 3:
            cout << "Exiting program.\n";
            break;
        default:
            cout << "Invalid choice!\n";
            break;
        }
    } while (choice != 3);

    for (Account* acc : accounts) {
        delete acc;
    }

    return 0;

	/*cout << "Sign up: \n";
	employee.setmail();
	employee.setpass();

	cout << "\nLog in: \n";
	string mail, pass;
	cout << "Enter mail and password: \n";
	cin >> mail >> pass;
	while (mail != employee.mail && pass != employee.password) {
		cout << "Incorrect details!\n\n";
		cin >> mail >> pass;
	}
	cout << "Welcome";*/
}
