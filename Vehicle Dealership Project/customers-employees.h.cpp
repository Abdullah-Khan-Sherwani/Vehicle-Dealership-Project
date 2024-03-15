#include<iostream>
#include<cstdlib>
#include<string>
#include<vector>
#include<iomanip>
#include "Accounts-T.h.cpp"
using namespace std;

class Employee : public Account {
private:
    string employeeID;

public:
    Employee(string mail, string password, string name, string employeeID)
        : Account(mail, password, name), employeeID(employeeID) {
        this->type = EMPLOYEE;
    }

    void signupInstance() override {
    cout << "-----Employee Sign Up-----\n\n";

    cout << "Full Name: ";
    getline(cin, this->name);
    cout << "Email: ";
    cin >> this->mail;
    cout<<"Employee ID: ";
    cin>> employeeID;
    cout << "Password: ";
    cin >> this->password;

    string check;
    cout << "Re-enter Password: ";
    cin >> check;
    while (this->password != check) {
        cout << "Passwords do not match. Please try again.\n";
        cout << "Password: ";
        cin >> this->password;
        cout << "Re-enter Password: ";
        cin >> check;
    }

    // Here, you would normally add this object to a collection of accounts.
    cout << "Employee account created successfully.\n";
}


    static Employee* signup() {
        system("cls");
        cout << "-----Employee Sign Up-----\n\n";

        string name, mail, password, employeeID;
        cout << "Full Name: "; getline(cin, name);
        cout << "Employee ID: "; getline(cin, employeeID);
        cout << "Email: "; cin >> mail;
        cout << "Password: "; cin >> password;

        string check;
        cout << "Re-enter Password: "; cin >> check;
        while (password != check) {
            cout << "Passwords do not match. Please try again.\n";
            cout << "Password: "; cin >> password;
            cout << "Re-enter Password: "; cin >> check;
        }

        Employee* emp = new Employee(mail, password, name, employeeID);
        cout << "Employee signed up successfully.\n";
        return emp;
    }

    static Employee* login(vector<Account*>& accounts) {
		string employeeID, password;
		system("cls");
		cout << "-----Login-----\n";
		//cout << "Login\n";
		cout << "Employee ID: ";
		cin >> employeeID;
		cout << "Password: ";
		cin >> password;

		for (Account* account : accounts) {
            Employee* emp = dynamic_cast<Employee*>(account);
			if (emp && emp->employeeID == employeeID && emp->password == password) {
            cout << "\nLogin successful!\n";
            return emp;
		}
		cout << "\nIncorrect Details!\n";
		return nullptr;
	}
    }
};

class Customer : public Account {
public:
    Customer(string mail, string password, string name)
        : Account(mail, password, name) {
        this->type = CUSTOMER;
    }

    void signupInstance() override {
    cout << "-----Customer Sign Up-----\n\n";

    cout << "Full Name: ";
    getline(cin, this->name);
    cout << "Email: ";
    cin >> this->mail;
    cout << "Password: ";
    cin >> this->password;

    string check;
    cout << "Re-enter Password: ";
    cin >> check;
    while (this->password != check) {
        cout << "Passwords do not match. Please try again.\n";
        cout << "Password: ";
        cin >> this->password;
        cout << "Re-enter Password: ";
        cin >> check;
    }
    cout << "Customer account created successfully.\n";
}


    static Customer* signup() {
        system("cls");
        cout << "-----Customer Sign Up-----\n\n";

        string name, mail, password;
        cout << "Full Name: "; getline(cin, name);
        cout << "Email: "; cin >> mail;
        cout << "Password: "; cin >> password;

        string check;
        cout << "Re-enter Password: "; cin >> check;
        while (password != check) {
            cout << "Passwords do not match. Please try again.\n";
            cout << "Password: "; cin >> password;
            cout << "Re-enter Password: "; cin >> check;
        }

        Customer* cust = new Customer(mail, password, name);
        cout << "Customer signed up successfully.\n";
        return cust;
    }

      static Customer* login(vector<Account*>& accounts) {
		string mail, password;
		system("cls");
		cout << "-----Login-----\n";
		//cout << "Login\n";
		cout << "Email: ";
		cin >> mail;
		cout << "Password: ";
		cin >> password;

		for (Account* account : accounts) {
            Customer* cust = dynamic_cast<Customer*>(account);
			if (cust && cust->mail == mail && cust->password == password) {
            cout << "\nLogin successful!\n";
            return cust;
		}
		cout << "\nIncorrect Details!\n";
		return nullptr;
	}
}
};