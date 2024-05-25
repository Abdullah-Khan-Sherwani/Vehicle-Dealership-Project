#ifndef CUSTOMERS_EMPLOYEES_H
#define CUSTOMERS_EMPLOYEES_H

#include<iostream>
#include<cstdlib>
#include<string>
#include<vector>
#include<map>

class Account {
protected:
    enum AccountType { CUSTOMER, EMPLOYEE };
    AccountType type;

    Account(std::string mail, std::string password, std::string name);

public:
    std::string mail, password, name;
    std::vector<std::string> logbook;

public:
    virtual void signupInstance() = 0; //pure virtual function for overriding in derived classes
    std::string get_mail();
};

// Forward declaration of checkMail function
bool checkMail(std::vector<Account*> accounts, std::string mail);

class Employee : public Account {
private:
    std::string employeeID;
    static std::vector<Account*> employees;

public:
    Employee(std::string mail, std::string password, std::string name, std::string employeeID);

    void signupInstance() override;
    static Employee* test();
    static Employee* signup();
    static Employee* login();
    friend bool checkMail(std::vector<Account*> accounts, std::string mail);
};

class Customer : public Account {
protected:
    static std::map<std::string, std::vector<std::string>> logbook;
    static std::vector<Account*> customers;

public:
    Customer(std::string mail, std::string password, std::string name);

    void signupInstance() override;
    static Customer* signup();
    static Customer* login();
    friend bool checkMail(std::vector<Account*> accounts, std::string mail);
    static void display();
};

#endif // CUSTOMERS_EMPLOYEES_H