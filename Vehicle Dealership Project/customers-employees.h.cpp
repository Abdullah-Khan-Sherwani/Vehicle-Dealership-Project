#include<iostream>
#include<cstdlib>
#include<string>
#include<vector>
#include<iomanip>
#include "Accounts-T.h.cpp"
#include<map>
using namespace std;

class Employee : public Account {
private:
    string employeeID;
    static vector<Account*> employees;

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
        if (checkMail(employees, mail)) {
            cout << "Account already exists\nEnter any key to continue to login";
            string temp; cin >> temp;
            return login();
        }

        cout << "Password: "; cin >> password;

        string check;
        cout << "Re-enter Password: "; cin >> check;
        while (password != check) {
            cout << "Passwords do not match. Please try again.\n";
            cout << "Password: "; cin >> password;
            cout << "Re-enter Password: "; cin >> check;
        }

        Employee* emp = new Employee(mail, password, name, employeeID);
        employees.push_back(emp);
        cout << "Employee signed up successfully.\n";
        return emp;
    }

    static Employee* login() {
		string employeeID, password;
		system("cls");
		cout << "-----Login-----\n";
		//cout << "Login\n";
		cout << "Employee ID: ";
		cin >> employeeID;
		cout << "Password: ";
		cin >> password;

		for (Account* account : employees) {
            Employee* emp = dynamic_cast<Employee*>(account);
            if (emp && emp->employeeID == employeeID && emp->password == password) {
                cout << "\nLogin successful!\n";
                return emp;
            }
            else if (emp && emp->employeeID == employeeID && emp->password != password) {
                cout << "\nIncorrect Details!\n";
                cout << "Forgot password? Enter 1 to change password or 0 to try again\n";
                int choice = 0;

                do {
                    cin >> choice;
                } while (choice != 1 || choice != 0);

                switch (choice)
                {
                case 1: {
                    while (true) {
                        cout << "Enter new password: ";
                        string newpass;
                        cin >> newpass;
                        cout << "Enter new password again: ";
                        string newpass2;
                        cin >> newpass2;

                        if (newpass != newpass2) {
                            cout << "Passwords do not match, try again:\n";
                        }
                        else {
                            emp->password = newpass;
                            return login();
                            break;
                        }
                    }
                }
                case 0: {
                    return login(); 
                }
                default:
                    cout << "Incorrect choice\n";
                    break;
                }
            }
            else {
                return nullptr;
            }
	}
    }

    friend bool checkMail(vector<Account*> accounts, string mail);
};

class Customer : public Account {
protected:
    static map<string, vector<string>> logbook;
    static vector<Account*> customers;

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
        if (checkMail(customers, mail)) {
            cout << "Account already exists\nEnter any key to continue to login";
            string temp; cin >> temp;
            return login();
        }

        cout << "Password: "; cin >> password;

        string check;
        cout << "Re-enter Password: "; cin >> check;
        while (password != check) {
            cout << "Passwords do not match. Please try again.\n";
            cout << "Password: "; cin >> password;
            cout << "Re-enter Password: "; cin >> check;
        }

        Customer* cust = new Customer(mail, password, name);
        customers.push_back(cust);
        cout << "Customer signed up successfully.\n";
        return cust;
    }

      static Customer* login() {
		string mail, password;
		system("cls");
		cout << "-----Login-----\n";
		//cout << "Login\n";
		cout << "Email: ";
		cin >> mail;
		cout << "Password: ";
		cin >> password;

		for (Account* account : customers) {
            Customer* cust = dynamic_cast<Customer*>(account);
			if (cust && cust->mail == mail && cust->password == password) {
                cout << "\nLogin successful!\n";
                return cust;
		    }
            else if (cust && cust->mail == mail){
                cout << "\nIncorrect Details!\n";
                cout << "Forgot password? Enter 1 to change password or 0 to try again\n";
                
                int choice;
                switch (choice)
                {
                case 1: {
                    while (true) {
                        cout << "Enter new password: ";
                        string newpass;
                        cin >> newpass;
                        cout << "Enter new password again: ";
                        string newpass2;
                        cin >> newpass2;

                        if (newpass != newpass2) {
                            cout << "Passwords do not match, try again:\n";
                        }
                        else {
                            cust->password = newpass;
                            return login();
                            break;
                        }
                    }
                }
                case 0: {
                    return login();
                }
                default:
                    break;
                }
            }
            else {
                return nullptr;
            }
	    }
      }

      friend bool checkMail(vector<Account*> accounts, string mail);
};

bool checkMail(vector<Account*> accounts, string mail) {
    for (Account* account : accounts) {
        if (account->mail == mail) {
            return true;
        }
    }

    return false;
}