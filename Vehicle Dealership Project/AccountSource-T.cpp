/*#include<iostream>
#include<cstdlib>
#include<string>
#include<vector>
#include<iomanip>
#include "Accounts-T.h.cpp"
#include "customers-employees.h.cpp"
using namespace std;

int main() {
    vector<Account*> accounts;

    // Simulate signing up a new Employee
    Employee* newEmployee = Employee::signup();
    if (newEmployee != nullptr) {
        accounts.push_back(newEmployee);
        cout << "New employee created with name: " << newEmployee->name << endl;
    }

    // Simulate signing up a new Customer
    Customer* newCustomer = Customer::signup();
    if (newCustomer != nullptr) {
        accounts.push_back(newCustomer);
        cout << "New customer created with name: " << newCustomer->name << endl;
    }

    // Simulate logging in as an Employee
    Account* loggedEmployee = Employee::login(accounts);
    if (loggedEmployee != nullptr) {
        cout << "Employee logged in: " << loggedEmployee->name << endl;
    } else {
        cout << "Employee login failed." << endl;
    }

    // Simulate logging in as a Customer
    Account* loggedCustomer = Customer::login(accounts);
    if (loggedCustomer != nullptr) {
        cout << "Customer logged in: " << loggedCustomer->name << endl;
    } else {
        cout << "Customer login failed." << endl;
    }

    // Clean up dynamically allocated memory (if not using smart pointers)
    for (Account* acc : accounts) {
        delete acc;
    }
    accounts.clear();

    return 0;
}*/
