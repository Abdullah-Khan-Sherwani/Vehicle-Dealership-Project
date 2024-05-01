#ifndef VEHICLE_FILE_H_CPP
#define VEHICLE_FILE_H_CPP

#include<iostream>
#include<ostream>
#include<fstream>
#include<vector>
#include<string>
//#include"customers-employees.h.cpp"
#include"inventory.h.cpp"
using namespace std;

string path = "C:\\Users\\abdul\\OneDrive\\Documents\\Semester 2\\OOP\\Vehicle Dealership Project\\Vehicle Dealership Project\\Vehicles_names_list.txt";

/*Only one vehicle object will be made in main since our static implementation had issues*/

class inventory{

};

class tool : public inventory{

};

class vehicles : public inventory{
    public:

    int cars_quantity, bikes_quantity;
    vector<string> cars_list;
    vector<string> bikes_list;
    vehicles() : cars_quantity(0), bikes_quantity(0) {}

    //virtual void noInstance() = 0;

    //Function to delete empty lines in .txt file
    void DeleteEmptyLines(){
        ifstream in(path);
        string line, text;
        while(getline(in, line)){
            if(!(line.empty() || line.find_first_not_of(' ') == string::npos)){
                text += line + "\n";
            }
        }
        in.close();
        ofstream out(path);
        out << text;
        out.close();
    }

    //Reading from .txt file
    void read_file(){
        DeleteEmptyLines();

        ifstream in(path);
        string line;
        while(getline(in, line)){
            if(!line.empty()) {
                if(line.substr(0, 1) == "C"){
                    ++cars_quantity;
                } else if(line.substr(0, 1) == "B"){
                    ++bikes_quantity;
                }
            }
        }
        in.close();
        in.open(path);

        for(int i = 0; i < cars_quantity + bikes_quantity; i++) {
            string line;
            if (getline(in, line)){
                char firstCharacter = line[0];
                if (firstCharacter == 'C') {
                    cars_list.push_back(line);
                } else if (firstCharacter == 'B') {
                    bikes_list.push_back(line);
                }
            } else {
                break;
            }
        }

        in.close();
    }

    //Function to add vehicle to .txt file and to list vector
    void add_vehicle(string type, string make, string model, string variant, int year, string number_plate, string engine, string mileage, int price){
        if(search_vehicle(number_plate, type) == -1){
            ofstream out;
            out.open(path, ios::app);
            if(type == "C"){
                cars_quantity += 1;
            } else if(type == "B"){
                bikes_quantity += 1;
            }
            string new_vehicle = type + " " + make + " " + model + " " + variant + " " + to_string(year) + " " + number_plate + " " + engine + " " + mileage + " " + to_string(price);
            
            if(type == "C"){
                cars_list.push_back(new_vehicle);;
            } else if(type == "B"){
                bikes_list.push_back(new_vehicle);
            }
            out<< new_vehicle;
            cout<<"Vehicle added\n";
        } else{
            cout<<"Vehicle by that number_plate already exists";
        }
    }

    //Function for searching a vehicle by plate in list vector
    int search_vehicle(string number_plate, string type){
        bool found = false;
        int temp_quantity = 0;
        
        if(type == "C"){
            temp_quantity = cars_quantity;
        } else if(type == "B"){
            temp_quantity = bikes_quantity;
        }
        
        string details;
        for(int i = 0; i < temp_quantity; i++){
            if(type == "C"){
                details = cars_list[i];
            } else if(type == "B"){
                details = bikes_list[i];
            }
            int column = 0;
            string plate = "";
            int k = 0;

            for(int j = 0; j < details.length(); j++){
                string index_char = details.substr(j, 1);
                if(index_char == " "){
                    column += 1;
                }
                if(column == 5 && k != 0){
                    plate += index_char;
                } else if(column == 5){
                    k += 1;
                }
            }
            if(plate == number_plate){
                found = true;
                return i;
                break;
            }
        }
        return -1;
    }

    //Function to display car in terminal by plate
    void display_vehicle(string number_plate, string type){
        int index = search_vehicle(number_plate, type);
        if(index != -1){
            cout<<"\n-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-";
            cout<< "\nType|Make|Model|Variant|Year|Number-Plate|Engine|Mileage|Price\n\n";
            if(type == "C"){
                cout<< cars_list[index] << endl << "------------------------------------------------------------\n";
            } else if(type == "B"){
                cout<< bikes_list[index] << endl << "------------------------------------------------------------\n";
            }
        } else{
            cout<<"\nThere is no vehicle by that number plate in our inventory\n";
        }
    }

    //Function to display vehicle in terminal by make
    void display_by_make(string make, string type){
        bool found = false;
        cout<<"\n-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-";
        cout<<"\nType|Make|Model|Variant|Year|Number-Plate|Engine|Mileage|Price\n\n";
        int temp_quantity = 0;
        
        if(type == "C"){
            temp_quantity = cars_quantity;
        } else if(type == "B"){
            temp_quantity = bikes_quantity;
        }
        string details;

        for(int i = 0; i < temp_quantity; i++){
            if(type == "C"){
                details = cars_list[i];
            } else if(type == "B"){
                details = bikes_list[i];
            }
            
            int column = 0;
            string company = "";

            for(int j = 0; j < details.length(); j++){
                string index_char = details.substr(j, 1);
                if(index_char != " " && column == 1){
                    company += index_char;
                }
                if(index_char == " "){
                    column += 1;
                }
            }
            if(make == company){
                found = true;
                if(type == "C"){
                    cout<< cars_list[i] << endl << "------------------------------------------------------------\n";
                } else if(type == "B"){
                    cout<< bikes_list[i] << endl << "------------------------------------------------------------\n";
                }
            }
        }
        if(!found){
            cout<<"\nThere is no vehicle by that make in our inventory\n";
        }
    }

    //Function to display vehicle in terminal by model
    void display_by_model(string model, string type){
        bool found = false;
        cout<<"\n-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-";
        cout<<"\nType|Make|Model|Variant|Year|Number-Plate|Engine|Mileage|Price\n\n";
        
        int temp_quantity = 0;
        
        if(type == "C"){
            temp_quantity = cars_quantity;
        } else if(type == "B"){
            temp_quantity = bikes_quantity;
        }
        
        for(int i = 0; i < temp_quantity; i++){
            string details;
            
            if(type == "C"){
                details = cars_list[i];
            } else if(type == "B"){
                details = bikes_list[i];
            }
            int column = 0;
            string name = "";

            for(int j = 0; j < details.length(); j++){
                string index_char = details.substr(j, 1);
                if(index_char != " " && column == 2){
                    name += index_char;
                }
                if(index_char == " "){
                    column += 1;
                }
            }
            
            if(name == model){
                found = true;
                
                if(type == "C"){
                    cout<< cars_list[i] << endl << "------------------------------------------------------------\n";
                } else if(type == "B"){
                    cout<< bikes_list[i] << endl << "------------------------------------------------------------\n";
                }
            }
        }
        if(!found){
            cout<<"\nThere is no vehicle with that model name in our inventory\n";
        }
    }

    //Function to display vehicle in terminal by year
    void display_by_year(int year, string type){
        bool found = false;
        cout<<"\n-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-";
        cout<<"\nType|Make|Model|Variant|Year|Number-Plate|Engine|Mileage|Price\n\n";
        
        int temp_quantity = 0;
        
        if(type == "C"){
            temp_quantity = cars_quantity;
        } else if(type == "B"){
            temp_quantity = bikes_quantity;
        }

        for(int i = 0; i < temp_quantity; i++){
            string details;
            if(type == "C"){
                details = cars_list[i];
            } else if(type == "B"){
                details = bikes_list[i];
            }
            int column = 0;
            string y = "";

            for(int j = 0; j < details.length(); j++){
                string index_char = details.substr(j, 1);
                if(index_char != " " && column == 4){
                    y += index_char;
                }
                if(index_char == " "){
                    column += 1;
                }
            }
            
            if(y != "" && stoi(y) == year){
                found = true;
                if(type == "C"){
                    cout<< cars_list[i] << endl << "------------------------------------------------------------\n";
                } else if(type == "B"){
                    cout<< bikes_list[i] << endl << "------------------------------------------------------------\n";
                }
            }
        }
        if(!found){
            cout<<"\nThere is no vehicle with that model name in our inventory\n";
        }
    }

    //Function to display vehicle in terminal within a certain price range
    void display_within_price_range(int min, int max, string type){
        bool found = false;
        cout<<"\n-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-";
        cout<<"\nType|Make|Model|Variant|Year|Number-Plate|Engine|Mileage|Price\n\n";
        
        int temp_quantity = 0;
        
        if(type == "C"){
            temp_quantity = cars_quantity;
        } else if(type == "B"){
            temp_quantity = bikes_quantity;
        }
        
        for(int i = 0; i < temp_quantity; i++){
            string details;
            if(type == "C"){
                details = cars_list[i];
            } else if(type == "B"){
                details = bikes_list[i];
            }
            
            int column = 0;
            string value = "";

            for(int j = 0; j < details.length(); j++){
                string index_char = details.substr(j, 1);
                if(index_char != " " && column == 8){
                    value += index_char;
                }
                if(index_char == " "){
                    column += 1;
                }
            }
            
            if(value != "" && stoi(value) <= max && stoi(value) >= min){
                found = true;
                if(type == "C"){
                    cout<< cars_list[i] << endl << "------------------------------------------------------------\n";
                } else if(type == "B"){
                    cout<< bikes_list[i] << endl << "------------------------------------------------------------\n";
                }
            }
        }
        if(!found){
            cout<<"\nThere is no vehicle within that price range in our inventory\n";
        }
    }

    //Function to remove a vehicle from list vector and the .txt file
    void remove_vehicle(string number_plate, string type){
        int index = search_vehicle(number_plate, type);

        string line;
        ifstream fin;
    
        fin.open(path);
        ofstream temp;
        temp.open("temp.txt");
        
        if(type == "C"){
            while(getline(fin, line)){
                if (line != cars_list[index]){
                    temp << line << endl;
                }
            }
        } else if(type == "B"){
            while(getline(fin, line)){
                if (line != bikes_list[index]){
                    temp << line << endl;
                }
            }
        }

        temp.close();
        fin.close();

        const char * p = path.c_str();
        remove(p);
        rename("temp.txt", p);

        if(type == "C"){
            if(index != -1){
                cars_list.erase(cars_list.begin() + index);
                cars_quantity -= 1;
                cout<<"Vehicle removed\n";
            } else{
                cout<<"There is no vehicle by that number plate\n";
            }
        } else if(type == "B"){
            if(index != -1){
                bikes_list.erase(bikes_list.begin() + index);
                bikes_quantity -= 1;
                cout<<"Vehicle removed\n";
            } else{
                cout<<"There is no vehicle by that number plate\n";
            }
        }
    }
    
    //Function to display all cars in inventory
    void display_all_cars(){
        cout<<"\n-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-";
        cout<< "\nType|Make|Model|Variant|Year|Number-Plate|Engine|Mileage|Price\n\n";
        for(int i = 0; i < cars_quantity; i++){
            cout<<cars_list[i] << endl << "------------------------------------------------------------\n";
        }
    }
    
    //Function to display all bikes in inventory
    void display_all_bikes(){
        cout<<"\n-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-";
        cout<< "\nType|Make|Model|Variant|Year|Number-Plate|Engine|Mileage|Price\n\n";
        for(int i = 0; i < bikes_quantity; i++){
            cout<<bikes_list[i] << endl << "------------------------------------------------------------\n";
        }
    }

    //Function to display all vehicles in inventory
    void display_all_vehicles(){
        display_all_cars();
        display_all_bikes();
    }

    //Function to display the total number of cars in inventory
    void display_total_number_of_cars(){
        cout<<"The total number of cars in our inventory are " << cars_quantity << endl;
    }
    
    //Function to display the total number of bikes in inventory
    void display_total_number_of_bikes(){
        cout<<"The total number of bikes in our inventory are " << bikes_quantity << endl;
    }
    
    //Function to display the total number of vehicles in inventory
    void display_total_number_of_vehicles(){
        cout<<"The total number of vehicles in our inventory are " << cars_quantity + bikes_quantity << endl;
    }
    
    //Function that returns a vehicle's price
    int return_vehicle_price(string number_plate, string type){
        string details;
        
        if(type == "C"){
            details = cars_list[search_vehicle(number_plate, type)];
        } else if(type == "B"){
            details = bikes_list[search_vehicle(number_plate, type)];
        }
        
        int column = 0;
        string value = "";
        
        for(int i = 0; i < details.length(); i++){
            string index_char = details.substr(i, 1);
            if(index_char != " " && column == 8){
                value += index_char;
            }
            if(index_char == " "){
                column += 1;
            }
        }
        return stoi(value);
    }
    
    //Function that returns vehicle details string
    string return_vehicle_details(string number_plate, string type){
        int index = search_vehicle(number_plate, type);
        
        if(type == "C"){
            if(index != -1){
                return cars_list[index];
            } else{
                return "Car not found";
            }
        } else if(type == "B"){
            if(index != -1){
                return bikes_list[index];
            } else{
                return "Bike not found";
            }
        }
        return "Not found";
    }

    //Function for editing a vehicle's details in list vector and .txt file
    void edit_vehicle_details(string plate, string type){
        int index = search_vehicle(plate, type);

        if(index != -1){
            string edited = "", temp;
            if(type == "C"){
                cout<<"Before edit: " << cars_list[index] << endl;
            } else if(type == "B"){
                cout<<"Before edit: " << bikes_list[index] << endl;
            }
            
            cout<<"Enter type (C for car, B for bike): ";
            cin>> temp;
            edited += temp;
            cout<<"Enter make: ";
            cin>> temp;
            edited = edited + " " + temp;
            cout<<"Enter model: ";
            cin>> temp;
            edited = edited + " " + temp;
            cout<<"Enter variant: ";
            cin>> temp;
            edited = edited + " " + temp;
            cout<<"Enter year: ";
            cin>> temp;
            edited = edited + " " + temp;
            cout<<"Enter Number plate: ";
            cin>> temp;
            edited = edited + " " + temp;
            cout<<"Enter engine: ";
            cin>> temp;
            edited = edited + " " + temp;
            cout<<"Enter mileage: ";
            cin>> temp;
            edited = edited + " " + temp;
            cout<<"Enter price: ";
            cin>> temp;
            edited = edited + " " + temp;
            
            if(type == "C"){
                cars_list[index] = edited;
            } else if(type == "B"){
                bikes_list[index] = edited;
            }

            ofstream file(path);
            for(int i = 0; i < cars_quantity; i++){
                file<< cars_list[i] + "\n";
            }
            for(int i = 0; i < bikes_quantity; i++){
                file<< bikes_list[i] + "\n";
            }
            
            cout<<"New details saved\n";
        } else{
            cout<<"There is no vehicle by that plate in our inventory\n";
        }
    }
};

/*
//testing
int main(){
    
    vehicles a;
    
    a.read_file();
    
    //a.display_vehicle("BYX-365", "C");

    //a.remove_vehicle("X-88-X", "C");

    //a.display_all_cars();

    //a.display_by_make("Honda", "C");

    //a.display_within_price_range(4500000, 8000000, "C");

    //a.display_car("X-88-X");

    //a.display_by_model("Alto", "C");

    //a.display_by_year(2021, "C");

    //a.add_vehicle("C", "Lamborghini", "Aventador", "SVJ", 2022, "X-88-X", "6500cc", "5km/l", 400000000);

    //a.remove_vehicle("X-88-X", "C");

    //a.display_by_model("H6", "C");

    //a.display_total_number_of_cars();
    
    //a.display_total_number_of_bikes();
    
    //a.display_total_number_of_vehicles();

    //a.edit_vehicle_details("BYX-365", "C");

    //a.display_within_price_range(100000, 1200000, "C");

    //a.display_all_cars();

    //a.display_car("AWL-241");

    //a.display_vehicle("HAT-4269", "B");

    //a.add_vehicle("Honda", "CG-125", "SE", 2024, "IAT-1948", "125cc", "50km/l", 100000);

    //a.display_total_number_of_vehicles();

    //a.display_vehicle("IAT-1947");

    //a.display_within_price_range(500000, 2000000);

    //a.display_by_make("Harley-Davidson");
    
    //cout<<a.return_vehicle_price("BYX-365", "C");
    
    //a.add_vehicle("C", "as", "as", "as", 34567, "BYX-365", "3435", "sd", 123);
}
*/

#endif // !VEHICLE_FILE_H_CPP