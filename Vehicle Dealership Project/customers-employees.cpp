#include<iostream>
#include<cstdlib>
#include<string>
#include<vector>
#include<iomanip>
#include<string>
#include "customers-employees.h"
#include "functions.h"
#include<map>
using namespace std;

//bool checkMail(vector<Account*> accounts, string mail);
bool checkMail(vector<Account*> accounts, string mail) {
    for (Account* account : accounts) {
        if (account->mail == mail) {
            return true;
        }
    }

    return false;
}

//function to check if password length is > 4
string passCheck(string password){
    while(password.length() <= 4){
        cout<<"\nPassword length must be greater than 4\n";
        cin>> password;
    }
    return password;
}

// Account class Constructor
Account::Account(string mail, string password, string name) : mail(mail), password(password), name(name) {}

// EMPLOYEE CLASS
vector<Account*> Employee::employees;

std::string Account::get_mail() {
    return this->mail;
}

Employee::Employee(string mail, string password, string name, string employeeID) : Account(mail, password, name), employeeID(employeeID) {
    this->type = EMPLOYEE;
}

void Employee::signupInstance() {
    cout << "-----Employee Sign Up-----\n\n";

    cout << "Full Name: ";
    getline(cin, this->name);
    cout << "Email: ";
    cin >> this->mail;
    cout << "Employee ID: ";
    cin >> employeeID;
    cout << "Password: ";
    cin >> this->password;
    password = passCheck(password);

    string check;
    cout << "Re-enter Password: ";
    cin >> check;
    while (this->password != check) {
        cout << "Passwords do not match. Please try again.\n";
        cout << "Password: ";
        cin >> this->password;
        password = passCheck(password);
        cout << "Re-enter Password: ";
        cin >> check;
    }

    cout << "Employee account created successfully.\n";
}

Employee* Employee::test() {
    Employee* emp = new Employee("1", "1", "1", "1");
    return emp;
}

Employee* Employee::signup() {
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
    password = passCheck(password);

    string check;
    cout << "Re-enter Password: "; cin >> check;
    while (password != check) {
        cout << "Passwords do not match. Please try again.\n";
        cout << "Password: "; cin >> password;
        password = passCheck(password);
        cout << "Re-enter Password: "; cin >> check;
    }

    Employee* emp = new Employee(mail, password, name, employeeID);
    employees.push_back(emp);
    cout << "Employee signed up successfully.\n";
    cout << "Current Employees:\n";
    // checking
    /*for (Account* account : Employee::employees) {
        Employee* emp = dynamic_cast<Employee*>(account);
        if (emp) {
            cout << "Name: " << emp->name
                << ", Email: " << emp->mail
                << ", Employee ID: " << emp->employeeID
                << ", Password: " << emp->password << "\n";
        }
    }
    cout << "Total Employees: " << Employee::employees.size() << "\n\n";*/
    return emp;
}

Employee* Employee::login() {
    string employeeID, password;
    system("cls");
    cout << "-----Login-----\n";
    // for checking 
    /*for (Account* account : Employee::employees) {
        Employee* emp = dynamic_cast<Employee*>(account);
        if (emp) {
            cout << "Name: " << emp->name
                << ", Email: " << emp->mail
                << ", Employee ID: " << emp->employeeID
                << ", Password: " << emp->password << "\n";
        }
    }*/
    //cout << "Login\n";
    cout << "Employee ID: ";
    cin >> employeeID;
    cout << "Password: ";
    cin >> password;
    password = passCheck(password);

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
                choice = isOk(choice);
            } while (choice != 1 && choice != 0);

            switch (choice)
            {
            case 1: {
                while (true) {
                    cout << "Enter new password: ";
                    string newpass;
                    cin >> newpass;
                    newpass = passCheck(newpass);
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
    }
    return nullptr;
}


// CUSTOMER CLASS
map<string, vector<string>> Customer::logbook;
vector<Account*> Customer::customers;

Customer::Customer(string mail, string password, string name) : Account(mail, password, name) {
    this->type = CUSTOMER;
}

void Customer::signupInstance() {
    cout << "-----Customer Sign Up-----\n\n";

    cout << "Full Name: ";
    getline(cin, this->name);
    cout << "Email: ";
    cin >> this->mail;
    cout << "Password: ";
    cin >> this->password;
    password = passCheck(password);

    string check;
    cout << "Re-enter Password: ";
    cin >> check;
    while (this->password != check) {
        cout << "Passwords do not match. Please try again.\n";
        cout << "Password: ";
        cin >> this->password;
        password = passCheck(password);
        cout << "Re-enter Password: ";
        cin >> check;
    }
    cout << "Customer account created successfully.\n";
}

Customer* Customer::signup() {
    system("cls");
    //cin.ignore();
    cout << "-----Customer Sign Up-----\n\n";

    string name, mail, password;
    //cout << "Press enter to continue";
    //cin.ignore();
    //cin.get();
    cout << "Full Name: "; getline(cin, name);
    cout << "Email: "; cin >> mail;
    if (checkMail(customers, mail)) {
        cout << "Account already exists\nEnter any key to continue to login";
        string temp; cin >> temp;
        return login();
    }

    cout << "Password: "; cin >> password;
    password = passCheck(password);

    string check;
    cout << "Re-enter Password: "; cin >> check;
    while (password != check) {
        cout << "Passwords do not match. Please try again.\n";
        cout << "Password: "; cin >> password;
        password = passCheck(password);
        cout << "Re-enter Password: "; cin >> check;
    }

    Customer* cust = new Customer(mail, password, name);
    customers.push_back(cust);
    cout << "Customer signed up successfully.\n";
    return cust;
}

Customer* Customer::login() {
    string mail, password;
    system("cls");
    cout << "-----Login-----\n";
    //cout << "Login\n";
    cout << "Email: ";
    cin >> mail;
    cout << "Password: ";
    cin >> password;
    password = passCheck(password);

    for (Account* account : customers) {
        Customer* cust = dynamic_cast<Customer*>(account);
        if (cust && cust->mail == mail && cust->password == password) {
            cout << "\nLogin successful!\n";
            return cust;
        }
        else if (cust && cust->mail == mail) {
            cout << "\nIncorrect Details!\n";
            cout << "Forgot password? Enter 1 to change password or 0 to try again\n";

            int choice;
            do {
                cin >> choice;
                choice = isOk(choice);
            } while (choice != 1 && choice != 0);

            switch (choice)
            {
            case 1: {
                while (true) {
                    cout << "Enter new password: ";
                    string newpass;
                    cin >> newpass;
                    newpass = passCheck(newpass);
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
    }
    return nullptr;
}

void Customer::display() {
    for (Account* acc : customers) {
        cout << acc->mail << endl;
    }
}

/*class Account {
protected:
    enum AccountType { CUSTOMER, EMPLOYEE };
    AccountType type;

    Account(string mail, string password, string name) : mail(mail), password(password), name(name) {}

public:
    string mail, password, name;
    vector<string> logbook;

public:

    virtual void signupInstance() = 0; //pure virtual function for overridiing in derived classes

    void setmail() {
        cout << "Enter Email: ";
        cin >> mail;
    }

    void setpass() {
        cout << "Enter password: ";
        cin >> password;
    }

    void setname() {
        cout << "Enter name: ";
        cin >> name;
    }

    static Account signup() {          // Accounts::signup()
        string mail, password, name;
        system("cls");
        cin.ignore();
        cout << "-----Sign Up-----\n\n";

        cout << "Full Name: "; getline(cin, name); //cin.ignore();
        cout << "Email:     "; cin >> mail;
        cout << "Password:  "; cin >> password;

        string check;
        cout << "\nRe-enter Password:"; cin >> check;

        while (password != check) {
            cout << "\nDifferent passwords!! Enter again:\n";
            cout << "Password:          "; cin >> password;
            //string check;
            cout << "Re-enter Password: "; cin >> check;
        }
        //system("cls");                                          *****new addition*****
        cout << "\nSuccessfully signed up";

        return Account(mail, password, name);
    }
    virtual void signupInstance()=0; //pure virtual function for overridiing in derived classes

    static Account* signup() {
        string mail, password, name;
        system("cls");
        cin.ignore();
        cout << "-----Sign Up-----\n\n";

        cout << "Full Name: "; getline(cin, name);
        cout << "Email:     "; cin >> mail;
        cout << "Password:  "; cin >> password;

        string check;
        cout << "\nRe-enter Password:"; cin >> check;

        while (password != check) {
            cout << "\nDifferent passwords!! Enter again:\n";
            cout << "Password:          "; cin >> password;
            cout << "Re-enter Password: "; cin >> check;
        }
        system("cls");
        cout << "\nSuccessfully signed up\n";

        return new Account(mail, password, name);
    }


    static Account* login(vector<Account*>& accounts) {
        string mail, password;
        system("cls");
        cout << "-----Login-----\n";
        //cout << "Login\n";
        cout << "Email:    ";
        cin >> mail;
        cout << "Password: ";
        cin >> password;

        for (Account* account : accounts) {
            if (account->mail == mail && account->password == password) {
                return account;
            }
        }
        cout << "\nIncorrect Details!\n";
        return nullptr;
    }*/
//};

/*class Employee : public Account {
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
        cout << "Employee ID: ";
        cin >> employeeID;
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

    static Employee* test() {
        Employee* emp = new Employee("1", "1", "1", "1");
        return emp;
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
                } while (choice != 1 && choice != 0);

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
        return nullptr;
    }

    friend bool checkMail(vector<Account*> accounts, string mail);
};
std::vector<Account*> Employee::employees;

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
            else if (cust && cust->mail == mail) {
                cout << "\nIncorrect Details!\n";
                cout << "Forgot password? Enter 1 to change password or 0 to try again\n";

                int choice;
                do {
                    cin >> choice;
                } while (choice != 1 && choice != 0);

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
        return nullptr;
    }
    friend bool checkMail(vector<Account*> accounts, string mail);
    static void display() {
        for (Account* acc : customers) {
            cout << acc->mail << endl;
        }
    }
};*/
//std::vector<Account*> Customer::customers;

/*int main() {
    vector<Account*> accounts;
    bool flag = true;
    while (flag) {
        system("cls");
        cout << "Choose an option:\n";
        cout << "1. Employee Sign Up\n";
        cout << "2. Customer Sign Up\n";
        cout << "3. Employee Login\n";
        cout << "4. Customer Login\n";
        cout << "5. Exit\n";

        int choice;
        cin >> choice;
        cin.ignore(); // Clear the input buffer

        switch (choice) {
        case 1: {
            Employee* emp = Employee::signup();
            if (emp) accounts.push_back(emp);
            break;
        }
        case 2: {
            Customer* cust = Customer::signup();
            if (cust) accounts.push_back(cust);
            break;
        }
        case 3: {
            Employee* emp = Employee::login();
            if (emp) {
                // Do something with logged in employee
            }
            break;
        }
        case 4: {
            Customer* cust = Customer::login();
            if (cust) {
                // Do something with logged in customer
            }
            break;
        }
        case 5: {
            cout << "Exiting program.\n";
            flag = false;
            break;
            //return 0;
        }
        default:
            cout << "Invalid choice. Please try again.\n";
            break;
        }

        cout << "Press Enter to continue...";
        cin.get(); // Wait for user to press Enter
    }
    cout << "\nCustomers:\n";
    Customer::display();
    return 0;
}*/
