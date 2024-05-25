#include "vehicle.h"
#include "customers-employees.h"
using namespace std;

vehicles vehicle; // global variable since static not implemented in vehicle class
map<string, vector<string>> CompanyLog;   /*Will store information of all sales with customer mail as key. Will be used by employees only*/

// general function for switch case range check
bool isWithinRange(int number, int min, int max) {
    return (number >= min && number <= max);
}

// Not Very Basic buy function | performs record update for sales and deletes sold cars from file
void buy_vehicle(string type, Account* acc){
    int buy_choice;
    cout<<"\nWould you like to buy a vehicle? (0: Yes, 1: No)\n";
    cin>> buy_choice;
    
    while(!isWithinRange(buy_choice, 0, 1)){
        cout << "Incorrect choice, enter again:\n";
        cin >> buy_choice;
    }
    
    if(buy_choice == 0){
        string plate;
        cout<< "\nPlease enter the number plate of the vehicle you would like to purchase\n";
        cin >> plate;
        string detail = vehicle.return_vehicle_details(plate, type);
        CompanyLog[acc->get_mail()].push_back(detail);
        vehicle.remove_vehicle(plate, type);
        cout<< "\nThank you for your purchase\n\n";
    }
}

void employeeMenu(Account* acc) {
    int choice = -1;
    while (choice != 0) {
        cout << "1: Car\n2: Bike\n0: Exit\n";
        int choice; cin >> choice;

        if (choice == 0) {
            return;
        }

        while (!isWithinRange(choice, 0, 2)) {
            cout << "Incorrect choice, enter again:\n";
            cin >> choice;
        }
        system("cls");
        switch (choice) {

            //For Cars
        case 1: {

            bool carflag = true;
            while (carflag) {
                string vehicle_type = "C";

                // Switch case for displaying cars
                cout << "1: Display all Cars\n2: Sort Cars by model\n3: Sort cars by make\n4: Sort cars by year\n5: Search Cars within price Range\n6: Edit Car details\n7: Remove Car \n8: Display total Cars\n9: Display total number of Vehicles\n0: to exit\n";
                int displaychoice; cin >> displaychoice;

                while (!isWithinRange(displaychoice, 0, 9)) {
                    cout << "Incorrect choice, enter again:\n";
                    cin >> displaychoice;
                }

                switch (displaychoice)
                {
                case 1: {
                    vehicle.display_all_cars();

                    break;
                }
                case 2: {
                    cout << "Enter Vehicle model (first letter in capital):\n";
                    string model; cin >> model;
                    vehicle.display_by_model(model, vehicle_type);

                    break;
                }
                case 3: {
                    cout << "Enter vehicle make (first letter in capital):\n";
                    string make; cin >> make;
                    vehicle.display_by_make(make, vehicle_type);

                    break;
                }
                case 4: {
                    cout << "Enter year to search vehicles from:\n";
                    int year; cin >> year;
                    vehicle.display_by_year(year, vehicle_type);

                    break;
                }
                case 5: {
                    cout << "Enter upper and lower price range to seacrh vehicles from:\n";
                    float upper, lower; cin >> upper >> lower;
                    vehicle.display_within_price_range(lower, upper, vehicle_type);

                    break;
                }
                case 6: {
                    string plate;
                    cout << "Enter vehicle number plate: \n";
                    cin >> plate;
                    vehicle.edit_vehicle_details(plate, vehicle_type);

                    break;
                }
                case 7: {
                    cout << "Enter vehicle number plate: \n";
                    string plate;
                    cin >> plate;

                    vehicle.remove_vehicle(plate, vehicle_type);

                    break;
                }
                case 8: {
                    vehicle.display_total_number_of_cars();

                    break;
                }
                case 9: {
                    vehicle.display_total_number_of_vehicles();

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
            bool bikeflag = true;
            while (bikeflag) {
                string vehicle_type = "B";
                system("cls");

                // Switch case for displaying cars
                cout << "1: Display all Bikes\n2: Sort Bikes by model\n3: Sort bikes by make\n4: Sort bikes by year\n5: Search Bikes within price Range\n6: Edit Bike details\n7: Remove Bike \n8: Display total Bikes\n9: Display total number of Vehicles\n0: to exit\n";
                int displaychoice; cin >> displaychoice;

                while (!isWithinRange(displaychoice, 0, 9)) {
                    cout << "Incorrect choice, enter again:\n";
                    cin >> displaychoice;
                }

                switch (displaychoice)
                {
                case 1: {
                    vehicle.display_all_bikes();

                    buy_vehicle(vehicle_type, acc);
                    break;
                }
                case 2: {
                    cout << "Enter Vehicle model (first letter in capital):\n";
                    string model; cin >> model;
                    vehicle.display_by_model(model, vehicle_type);

                    buy_vehicle(vehicle_type, acc);
                    break;
                }
                case 3: {
                    cout << "Enter vehicle make (first letter in capital):\n";
                    string make; cin >> make;
                    vehicle.display_by_make(make, vehicle_type);

                    buy_vehicle(vehicle_type, acc);
                    break;
                }
                case 4: {
                    cout << "Enter year to search vehicles from:\n";
                    int year; cin >> year;
                    vehicle.display_by_year(year, vehicle_type);

                    buy_vehicle(vehicle_type, acc);
                    break;
                }
                case 5: {
                    cout << "Enter upper and lower price range to seacrh vehicles from:\n";
                    float upper, lower; cin >> upper >> lower;
                    vehicle.display_within_price_range(lower, upper, vehicle_type);

                    buy_vehicle(vehicle_type, acc);
                    break;
                }
                case 6: {
                    string plate;
                    cout << "Enter vehicle number plate: \n";
                    cin >> plate;
                    vehicle.edit_vehicle_details(plate, vehicle_type);

                    break;
                }
                case 7: {
                    cout << "Enter vehicle number plate: \n";
                    string plate;
                    cin >> plate;

                    vehicle.remove_vehicle(plate, vehicle_type);

                    break;
                }
                case 8: {
                    vehicle.display_total_number_of_bikes();

                    break;
                }
                case 9: {
                    vehicle.display_total_number_of_vehicles();

                    break;
                }
                case 0: {
                    bikeflag = false;
                    break;
                }
                }
            }
        }
        }
    }
}

// Menu for Customers
void customerMenu(Account* acc) {
    int choice = -1;
    while (choice != 0) {
        cout << "1: Car\n2: Bike\n0: Exit\n";
        int choice; cin >> choice;
        
        if (choice == 0) {
            return;
        }

        while (!isWithinRange(choice, 0, 2)) {
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
                cout << "1: Display all Cars\n2: Sort Cars by model\n3: Sort cars by make\n4: Sort cars by year\n5: Search Cars within price Range\n0: to exit\n";
                int displaychoice; cin >> displaychoice;
                while (!isWithinRange(displaychoice, 0, 5)) {
                    cout << "Incorrect choice, enter again:\n";
                    cin >> displaychoice;
                }

                switch (displaychoice)
                {
                case 1: {
                    vehicle.display_all_cars();
                    
                    buy_vehicle(vehicle_type, acc);
                    break;
                }
                case 2: {
                    cout << "Enter Vehicle model (first letter in capital):\n";
                    string model; cin >> model;
                    vehicle.display_by_model(model, vehicle_type);
                    
                    buy_vehicle(vehicle_type, acc);
                    break;
                }
                case 3: {
                    cout << "Enter vehicle make (first letter in capital):\n";
                    string make; cin >> make;
                    vehicle.display_by_make(make, vehicle_type);
                    
                    buy_vehicle(vehicle_type, acc);
                    break;
                }
                case 4: {
                    cout << "Enter year to search vehicles from:\n";
                    int year; cin >> year;
                    vehicle.display_by_year(year, vehicle_type);
                    
                    buy_vehicle(vehicle_type, acc);
                    break;
                }
                case 5: {
                    cout << "Enter upper and lower price range to seacrh vehicles from:\n";
                    float upper, lower; cin >> upper >> lower;
                    vehicle.display_within_price_range(lower, upper, vehicle_type);
                    
                    buy_vehicle(vehicle_type, acc);
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
            bool bikeflag = true;
            while (bikeflag) {
                string vehicle_type = "B";
                system("cls");

                // Switch case for displaying cars
                cout << "1: Display all Bikes\n2: Sort Bikes by model\n3: Sort bikes by make\n4: Sort bikes by year\n5: Search Bikes within price Range\n0: to exit\n";
                int displaychoice; cin >> displaychoice;
                while (!isWithinRange(displaychoice, 0, 5)) {
                    cout << "Incorrect choice, enter again:\n";
                    cin >> displaychoice;
                }

                switch (displaychoice)
                {
                case 1: {
                    vehicle.display_all_bikes();
                    
                    buy_vehicle(vehicle_type, acc);
                    break;
                }
                case 2: {
                    cout << "Enter Vehicle model (first letter in capital):\n";
                    string model; cin >> model;
                    vehicle.display_by_model(model, vehicle_type);
                    
                    buy_vehicle(vehicle_type, acc);
                    break;
                }
                case 3: {
                    cout << "Enter vehicle make (first letter in capital):\n";
                    string make; cin >> make;
                    vehicle.display_by_make(make, vehicle_type);
                    
                    buy_vehicle(vehicle_type, acc);
                    break;
                }
                case 4: {
                    cout << "Enter year to search vehicles from:\n";
                    int year; cin >> year;
                    vehicle.display_by_year(year, vehicle_type);
                    
                    buy_vehicle(vehicle_type, acc);
                    break;
                }
                case 5: {
                    cout << "Enter upper and lower price range to seacrh vehicles from:\n";
                    float upper, lower; cin >> upper >> lower;
                    vehicle.display_within_price_range(lower, upper, vehicle_type);
                    
                    buy_vehicle(vehicle_type, acc);
                    break;
                }
                case 0: {
                    bikeflag = false;
                    break;
                }
                }
            }
        }
        }
    }
}

int main() {
    vehicle.read_file();

    cout << "====== Welcome to HAT Dealership sponsored by Ibad Bhai ======\n";

    while (true) {
        cout << "Create an account to continue: \nEnter 1 if you are an employee and 2 if you are a customer, enter -1 to exit: \n";
        int acctype; cin >> acctype;

        if (acctype == -1) {
            break;
        }

        while (!isWithinRange(acctype, -1, 2)) {
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
