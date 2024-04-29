#include<iostream>
#include<ostream>
#include<fstream>
#include<vector>
#include<string>
using namespace std;
string c_path = "Car_names_list.txt";
string b_path = "Bikes_names_list.txt";

class inventory{

};

class tool : public inventory{

};

class vehicles : public inventory{
    public:

    string loaded_path;
    int quantity;
    vector<string> list;
    vehicles() : quantity(0) {}

    //Function to delete empty lines in .txt file
    void DeleteEmptyLines(string location){
        ifstream in(location);
        string line, text;
        while(getline(in, line)){
            if(!(line.empty() || line.find_first_not_of(' ') == string::npos)){
                text += line + "\n";
            }
        }
        in.close();
        ofstream out(location);
        out << text;
        out.close();
    }

    //Reading from .txt file
    void read_file(string path){
        loaded_path = path;
        DeleteEmptyLines(path);

        ifstream in(path);
        string line;
        while(getline(in, line)){
            if(!line.empty()) {
                ++quantity;
            }
        }
        in.close();

        list.resize(quantity);
        in.open(path);
        for(int i = 0; i < quantity; i++){
            if(getline(in, list[i])){
            } else{
                break;
            }
        }
        in.close();
    }

    //Function to add vehicle to .txt file and to list vector
    void add_vehicle(string make, string model, string variant, int year, string number_plate, string engine, string mileage, int price){
        ofstream out;
        out.open(loaded_path, ios::app);
        quantity += 1;
        string new_car = make + " " + model + " " + variant + " " + to_string(year) + " " + number_plate + " " + engine + " " + mileage + " " + to_string(price);
        list.push_back(new_car);
        out<< new_car;   
    }

    //Function for searching a vehicle by plate in list vector
    int search_vehicle(string number_plate){
        bool found = false;

        for(int i = 0; i < quantity; i++){
            string details = list[i];
            int column = 0;
            string plate = "";
            int k = 0;

            for(int j = 0; j < details.length(); j++){
                string index_char = details.substr(j, 1);
                if(index_char == " "){
                    column += 1;
                }
                if(column == 4 && k != 0){
                    plate += index_char;
                } else if(column == 4){
                    k += 1;
                }
            }
            if(plate == number_plate){
                found = true;
                return i;
                break;
            }
        }
        if(!found){
            return -1;
        }
        return -1;
    }

    //Function to display car in terminal by plate
    void display_vehicle(string number_plate){
        int index = search_vehicle(number_plate);
        if(index != -1){
            cout<<"\n-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-";
            cout<< "\nMake|Model|Variant|Year|Number-Plate|Engine|Mileage|Price\n\n";
            cout<< list[index] << endl << "------------------------------------------------------------\n";
        }
    }

    //Function to display vehicle in terminal by make
    void display_by_make(string make){
        bool found = false;
        cout<<"\n-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-";
        cout<<"\nMake|Model|Variant|Year|Number-Plate|Engine|Mileage|Price\n\n";

        for(int i = 0; i < quantity; i++){
            string details = list[i];
            int column = 0;
            string company = "";

            for(int j = 0; j < details.length(); j++){
                string index_char = details.substr(j, 1);
                if(index_char != " " && column == 0){
                    company += index_char;
                }
                if(index_char == " "){
                    column += 1;
                    j = details.length();
                }
            }
            if(make == company){
                found = true;
                cout<< list[i] << endl << "------------------------------------------------------------\n";
            }
        }
        if(!found){
            cout<<"\nThere is no car by that make in our inventory\n";
        }
    }

    //Function to display vehicle in terminal by model
    void display_by_model(string model){
        bool found = false;
        cout<<"\n-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-";
        cout<<"\nMake|Model|Variant|Year|Number-Plate|Engine|Mileage|Price\n\n";

        for(int i = 0; i < quantity; i++){
            string details = list[i];
            int column = 0;
            string name = "";

            for(int j = 0; j < details.length(); j++){
                string index_char = details.substr(j, 1);
                if(index_char != " " && column == 1){
                    name += index_char;
                }
                if(index_char == " "){
                    column += 1;
                }
            }
            
            if(name == model){
                found = true;
                cout<< list[i] << endl << "------------------------------------------------------------\n";
            }
        }
        if(!found){
            cout<<"\nThere is no car with that model name in our inventory\n";
        }
    }

    //Function to display vehicle in terminal by year
    void display_by_year(int year){
        bool found = false;
        cout<<"\n-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-";
        cout<<"\nMake|Model|Variant|Year|Number-Plate|Engine|Mileage|Price\n\n";

        for(int i = 0; i < quantity; i++){
            string details = list[i];
            int column = 0;
            string y = "";

            for(int j = 0; j < details.length(); j++){
                string index_char = details.substr(j, 1);
                if(index_char != " " && column == 3){
                    y += index_char;
                }
                if(index_char == " "){
                    column += 1;
                }
            }
            
            if(y != "" && stoi(y) == year){
                found = true;
                cout<< list[i] << endl << "------------------------------------------------------------\n";
            }
        }
        if(!found){
            cout<<"\nThere is no car with that model name in our inventory\n";
        }
    }

    //Function to display vehicle in terminal within a certain price range
    void display_within_price_range(int min, int max){
        bool found = false;
        cout<<"\n-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-";
        cout<<"\nMake|Model|Variant|Year|Number-Plate|Engine|Mileage|Price\n\n";

        for(int i = 0; i < quantity; i++){
            string details = list[i];
            int column = 0;
            string value = "";

            for(int j = 0; j < details.length(); j++){
                string index_char = details.substr(j, 1);
                if(index_char != " " && column == 7){
                    value += index_char;
                }
                if(index_char == " "){
                    column += 1;
                }
            }
            
            if(value != "" && stoi(value) <= max && stoi(value) >= min){
                found = true;
                cout<< list[i] << endl << "------------------------------------------------------------\n";
            }
        }
        if(!found){
            cout<<"\nThere is no car within that price range in our inventory\n";
        }
    }

    //Function to remove a vehicle from list vector and the .txt file
    void remove_vehicle(string number_plate){
        int index = search_vehicle(number_plate);

        string line;
        ifstream fin;
    
        fin.open(c_path);
        ofstream temp;
        temp.open("temp.txt");

        while(getline(fin, line)){
            if (line != list[index]){
                temp << line << endl;
            }
        }

        temp.close();
        fin.close();

        const char * p = c_path.c_str();
        remove(p);
        rename("temp.txt", p);

        if(index != -1){
            list.erase(list.begin() + index);
            quantity -= 1;
        } else{
            cout<<"There is no car by that number plate\n";
        }
    }

    //Function to display all vehicles (bike and cars seperate) in inventory
    void display_all_vehicles(){
        cout<<"\n-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-";
        cout<< "\nMake|Model|Variant|Year|Number-Plate|Engine|Mileage|Price\n\n";
        for(int i = 0; i < quantity; i++){
            cout<<list[i] << endl << "------------------------------------------------------------\n";
        }
    }

    //Function to display the total number of vehicles (bikes and cars seperate) in inventory
    void display_total_number_of_vehicles(){
        cout<<"The total number of cars in our inventory are " << quantity << endl;
    }

    //Function for editing a vehicle's details in list vector and .txt file
    void edit_car_details(string plate){
        int index = search_vehicle(plate);

        if(index != -1){
            string edited = "", temp;
            cout<<"Before edit: " << list[index] << endl;
            cout<<"Enter make: ";
            cin>> temp;
            edited += temp;
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
            list[index] = edited;

            ofstream file(c_path);
            for(int i = 0; i < quantity; i++){
                file<< list[i] + "\n";
            }
        } else{
            cout<<"There is no vehicle by that plate in our inventory\n";
        }
    }
};

class cars : public vehicles{
    ifstream file;
    int number_of_cars;
    vector<string> car_list;

    public:
    cars() : file(c_path), number_of_cars(0) {}

    //Function for reading file and setting values from parent class function
    void read(){
        read_file(c_path);
        car_list = list;
        number_of_cars = quantity;
    }
};

class bikes : public vehicles{
    ifstream file;
    int number_of_bikes;
    vector<string> bikes_list;

    public:
    bikes() : file(b_path), number_of_bikes(0) {}

    //Function for reading file and setting values from parent class function
    void read(){
        read_file(b_path);
        bikes_list = list;
        number_of_bikes = quantity;
    }
};

/*
int main(){
    //testing
    cars a;
    bikes b;

    a.read();
    b.read();

    //a.display_vehicle("BYX-365");

    //a.remove_car("BYX-365");

    //a.display_all_cars();

    //a.display_by_make("Honda");

    //a.display_within_price_range(4500000, 8000000);

    //a.display_car("X-88-X");

    //a.display_by_model("Alto");

    //a.display_by_year(2021);

    //a.add_vehicle("Lamborghini", "Aventador", "SVJ", 2022, "X-88-X", "6500cc", "5km/l", 400000000);

    //a.remove_car("X-88-X");

    //a.display_by_model("H6");

    //a.display_total_number_of_cars();

    //a.edit_car_details("BYX-365");

    //a.display_within_price_range(100000, 1200000);

    //a.display_all_cars();

    //a.display_car("AWL-241");

    //b.display_vehicle("HAT-4269");

    //b.add_vehicle("Honda", "CG-125", "SE", 2024, "IAT-1948", "125cc", "50km/l", 100000);
}
*/
