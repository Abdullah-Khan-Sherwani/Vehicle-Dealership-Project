//#pragma once
#ifndef VEHICLE_H
#define VEHICLE_H

#include<iostream>
#include<ostream>
#include<fstream>
#include<vector>
#include<string> // Add this line to include the <string> header
#include"customers-employees.h"
using namespace std;

class Inventory {
protected:
    int quantity;
    double price;

public:
    Inventory(int quantity, double price) : quantity(quantity), price(price) {}
    Inventory() {}

    //virtual void buy(int quantity) = 0;
    //virtual void sell(int quantity) = 0;
    //virtual void display() = 0;
};

class Tools : public Inventory {
protected:
    string toolName;

public:
    Tools(string toolName, int quantity, double price) : Inventory(quantity, price), toolName(toolName) {}

    //void buy(int amount) override;
    //void sell(int amount) override;
    //void display() override;
};

class vehicles : public Inventory {
public:
    int cars_quantity, bikes_quantity;
    vector<string> cars_list;
    vector<string> bikes_list;
    vehicles() : cars_quantity(0), bikes_quantity(0) {}

    void DeleteEmptyLines();
    void read_file();
    void add_vehicle(string type, string make, string model, string variant, int year, string number_plate, string engine, string mileage, int price);
    int search_vehicle(string number_plate, string type);
    void display_vehicle(string number_plate, string type);
    void display_by_make(string make, string type);
    void display_by_model(string model, string type);
    void display_by_year(int year, string type);
    void display_within_price_range(int min, int max, string type);
    void remove_vehicle(string number_plate, string type);
    void display_all_cars();
    void display_all_bikes();
    void display_all_vehicles();
    void display_total_number_of_cars();
    void display_total_number_of_bikes();
    void display_total_number_of_vehicles();
    int return_vehicle_price(string number_plate, string type);
    string return_vehicle_details(string number_plate, string type);
    void edit_vehicle_details(string plate, string type);
};

#endif // VEHICLE_H