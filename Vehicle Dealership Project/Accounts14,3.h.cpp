#include<iostream>
#include<cstdlib>
#include<string>
#include<vector>
#include<iomanip>
using namespace std;

class Account {
protected:
	Account(string mail, string password, string name) : mail(mail), password(password), name(name) {}

public:
	string mail, password, name;
	vector<string> logbook;

public:

	/*void setmail() {
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
	}*/

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
	}
};