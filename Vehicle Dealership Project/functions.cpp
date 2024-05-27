#include "customers-employees.h"
#include "vehicle.h"
#include "functions.h"
#include "globals.h"
using namespace std;
extern vehicles vehicle; // global variable since static not implemented in vehicle class
//saleswallet = 0; // global variable for money earned in sales can be reset
extern map<string, vector<string>> CompanyLog;   /*Will store information of all sales with customer mail as key. Will be used by employees only*/

// general function for switch case range check
bool isWithinRange(int number, int min, int max) {
    return (number >= min && number <= max);
}

double updateWallet(){
    saleswallet = 0;
    return saleswallet;
}

// Not Very Basic buy function, performs record update for sales and deletes sold cars from file
void buy_vehicle(string type, Account* acc) {
    int buy_choice;
    cout << "\nWould you like to buy a vehicle? (0: Yes, 1: No)\n";
    cin >> buy_choice;

    while (!isWithinRange(buy_choice, 0, 1)) {
        cout << "Incorrect choice, enter again:\n";
        cin >> buy_choice;
    }

    if (buy_choice == 0) {
        string plate;
        cout << "\nPlease enter the number plate of the vehicle you would like to purchase\n";
        cin >> plate;
        string detail = vehicle.return_vehicle_details(plate, type);

        updateWallet();
        saleswallet += vehicle.return_vehicle_price(plate, type);
        CompanyLog[acc->get_mail()].push_back(detail);
        vehicle.remove_vehicle(plate, type);
        cout << "\nThank you for your purchase\n\n";
    }
}

// for employees to add/buy vehicles for the dealership
void addV(string type) {
    string make, model, variant, number_plate, engine, mileage;
    int year, price;

    cout << "Enter make: ";
    cin >> make;
    // capital first letter of company name
    if (!make.empty()) {
        make[0] = toupper(make[0]);
    }

    cout << "Enter model: ";
    cin >> model;
    cout << "Enter variant: ";
    cin >> variant;
    cout << "Enter year: ";
    cin >> year;
    cout << "Enter number plate: ";
    cin >> number_plate;
    cout << "Enter engine: ";
    cin >> engine;
    cout << "Enter mileage: ";
    cin >> mileage;
    cout << "Enter price: ";
    cin >> price;

    vehicle.add_vehicle(type, make, model, variant, year, number_plate, engine, mileage, price);
}

// Function for employee menu
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
                cout << "1: Display all Cars\n2: Sort Cars by model\n3: Sort cars by make\n4: Sort cars by year\n5: Search Cars within price Range\n6: Edit Car details\n7: Remove Car \n8: Display total Cars\n9: Display total number of Vehicles\n10: Show sales\n11: Add new cars\n0: to exit\n";
                int displaychoice; cin >> displaychoice;

                while (!isWithinRange(displaychoice, 0, 11)) {
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
                case 10: {
                    cout << "\n";
                    if (CompanyLog.empty()) {
                        cout << "No sales yet" << endl;

                        break;
                    }
                    for (auto& user : CompanyLog) {
                        cout << "User: " << user.first << endl;
                        for (auto& elem : user.second) {
                            cout << elem << "\n";
                        }
                        cout << endl;
                    }
                }
                case 11: {
                    addV(vehicle_type);
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
                cout << "1: Display all Bikes\n2: Sort Bikes by model\n3: Sort bikes by make\n4: Sort bikes by year\n5: Search Bikes within price Range\n6: Edit Bike details\n7: Remove Bike \n8: Display total Bikes\n9: Display total number of Vehicles\n10: Total Sales\n11: Add a Bike\n0: to exit\n";
                int displaychoice; cin >> displaychoice;

                while (!isWithinRange(displaychoice, 0, 11)) {
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
                case 10: {
                    cout << "\n";
                    if (CompanyLog.empty()) {
                        cout << "No sales yet" << endl;

                        break;
                    }
                    for (auto& user : CompanyLog) {
                        cout << "User: " << user.first << endl;
                        for (auto& elem : user.second) {
                            cout << elem << "\n";
                        }
                        cout << endl;
                    }
                    cout << "Total money earned: " << saleswallet << endl;
                }
                case 11: {
                    addV(vehicle_type);
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
