#include "vehicle.h"
#include "customers-employees.h"
#include "functions.h"
#include "globals.h"
using namespace std;

vehicles vehicle;

int main() {
    update_Wallet();
    vehicle.read_file();

    cout << "====== Welcome to HAT Dealership sponsored by Ibad Bhai ======\n";

    while (true) {
        cout << "Create an account to continue: \nEnter 1 if you are an employee and 2 if you are a customer, enter 0 to exit: \n";
        int acctype; cin >> acctype;
        acctype = isOk(acctype);

        if (acctype == 0) {
            break;
        }

        while (!isWithinRange(acctype, 1, 2)) {
            cout << "Invalid choice. Retry\n";
            cin >> acctype;
            acctype = isOk(acctype);
        }

        Account* acc = nullptr;

        cout << "Enter 1 to signup or 2 to login: ";
        int action; cin >> action;
        action = isOk(action);

        while (!isWithinRange(action, 1, 2)) {
            cout << "Invalid choice. Retry\n";
            cin >> action;
            action = isOk(action);
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

        if (acc != nullptr) {
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
