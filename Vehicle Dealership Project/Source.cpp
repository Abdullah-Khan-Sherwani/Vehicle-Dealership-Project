#include "vehicle.h"
#include "customers-employees.h"
#include "functions.h"
using namespace std;

vehicles vehicle; // global variable since static not implemented in vehicle class
double saleswallet = 0; // global variable for money earned in sales can be reset
map<string, vector<string>> CompanyLog;   /*Will store information of all sales with customer mail as key. Will be used by employees only*/

int main() {
    vehicle.read_file();

    cout << "====== Welcome to HAT Dealership sponsored by Ibad Bhai ======\n";

    while (true) {
        cout << "Create an account to continue: \nEnter 1 if you are an employee and 2 if you are a customer, enter 0 to exit: \n";
        int acctype; cin >> acctype;

        if (acctype == 0) {
            break;
        }

        while (!isWithinRange(acctype, 1, 2)) {
            cout << "Invalid choice. Retry\n";
            cin >> acctype;
        }

        Account* acc = nullptr;

        cout << "Enter 1 to signup or 2 to login: ";
        int action; cin >> action;

        while (!isWithinRange(action, 1, 2)) {
            cout << "Invalid choice. Retry\n";
            cin >> action;
        }


        if (acctype == 1) {
            if (action == 1) {
                acc = Employee::signup();
            }
            else if (action == 2) {
                acc = Employee::login();
            }
        }
        else if (acctype == 2) {
            if (action == 1) {
                acc = Customer::signup();
            }
            else if (action == 2) {
                acc = Customer::login();
            }
        }

        if (acc) {
            if (acctype == 2) {
                customerMenu(acc);
            }
            else {
                cout << "Employee logged in successfully.\n";
                // add employee menu bois
                employeeMenu(acc);
            }
            //delete acc;  // memory clearance scenes //DONT DO THIS, THIS IS VERY VERY BAD
        }
        else {
            cout << "Failed to login or signup.\n";
        }
        system("pause");
        cout << "\nEnter any key to continue";
        system("cls");
    }

    return 0;
}