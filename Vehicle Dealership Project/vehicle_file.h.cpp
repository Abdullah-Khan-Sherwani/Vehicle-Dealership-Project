#include<iostream>
#include<ostream>
#include<fstream>
#include<vector>
#include<string>
using namespace std;
string path = "Car_names_list.txt";

class inventory{

};

class tool : public inventory{

};

class vehicles : public inventory{

};

class cars : public vehicles{
    ifstream file;
    int number_of_cars;
    vector<string> car_list;

    public:
    cars() : file(path), number_of_cars(0) {}

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

        number_of_cars = 0;
        ifstream in(path);
        string line;
        while(getline(in, line)){
            if(!line.empty()) {
                ++number_of_cars;
            }
        }
        in.close();

        car_list.resize(number_of_cars);
        in.open(path);
        for(int i = 0; i < number_of_cars; i++){
            if(getline(in, car_list[i])){
            } else{
                break;
            }
        }
        in.close();
    }

    //Function to add car to .txt file and to car_list vector
    void add_car(string make, string model, string variant, int year, string number_plate, string engine, string mileage, int price){
        ofstream out;
        out.open(path, ios::app);
        number_of_cars += 1;
        string new_car = make + " " + model + " " + variant + " " + to_string(year) + " " + number_plate + " " + engine + " " + mileage + " " + to_string(price);
        car_list.push_back(new_car);
        out<< new_car;
    }

    //Function for searching a car by plate in car_list vector
    int search_car(string number_plate){
        bool found = false;

        for(int i = 0; i < number_of_cars; i++){
            string details = car_list[i];
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
    void display_car(string number_plate){
        int index = search_car(number_plate);
        if(index != -1){
            cout<<"\n-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-";
            cout<< "\nMake|Model|Variant|Year|Number-Plate|Engine|Mileage|Price\n\n";
            cout<< car_list[index] << endl;
        }
    }

    //Function to display car in terminal by make
    void display_by_make(string make){
        bool found = false;
        cout<<"\n-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-";
        cout<<"\nMake|Model|Variant|Year|Number-Plate|Engine|Mileage|Price\n\n";

        for(int i = 0; i < number_of_cars; i++){
            string details = car_list[i];
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
                cout<< car_list[i] << endl;
            }
        }
        if(!found){
            cout<<"\nThere is no car by that make in our inventory\n";
        }
    }

    //Function to display car in terminal by model
    void display_by_model(string model){
        bool found = false;
        cout<<"\n-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-";
        cout<<"\nMake|Model|Variant|Year|Number-Plate|Engine|Mileage|Price\n\n";

        for(int i = 0; i < number_of_cars; i++){
            string details = car_list[i];
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
                cout<< car_list[i] << endl;
            }
        }
        if(!found){
            cout<<"\nThere is no car with that model name in our inventory";
        }
    }

    //Function to display car in terminal by year
    void display_by_year(int year){
        bool found = false;
        cout<<"\n-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-";
        cout<<"\nMake|Model|Variant|Year|Number-Plate|Engine|Mileage|Price\n\n";

        for(int i = 0; i < number_of_cars; i++){
            string details = car_list[i];
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
                cout<< car_list[i] << endl;
            }
        }
        if(!found){
            cout<<"\nThere is no car with that model name in our inventory";
        }
    }

    //Function to display car in terminal within a certain price range
    void display_within_price_range(int min, int max){
        bool found = false;
        cout<<"\n-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-";
        cout<<"\nMake|Model|Variant|Year|Number-Plate|Engine|Mileage|Price\n\n";

        for(int i = 0; i < number_of_cars; i++){
            string details = car_list[i];
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
                cout<< car_list[i] << endl;
            }
        }
        if(!found){
            cout<<"\nThere is no car within that price range in our inventory";
        }
    }

    //Function to remove a car from car_list vector and the .txt file
    void remove_car(string number_plate){
        int index = search_car(number_plate);

        string line;
        ifstream fin;
    
        fin.open(path);
        ofstream temp;
        temp.open("temp.txt");

        while(getline(fin, line)){
            if (line != car_list[index]){
                temp << line << endl;
            }    
        }

        temp.close();
        fin.close();

        const char * p = path.c_str();
        remove(p);
        rename("temp.txt", p);

        if(index != -1){
            car_list.erase(car_list.begin() + index);
            number_of_cars -= 1;
        } else{
            cout<<"There is no car by that number plate\n";
        }
    }

    //Function to display all cars in inventory
    void display_all_cars(){
        cout<<"\n-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-";
        cout<< "\nMake|Model|Variant|Year|Number-Plate|Engine|Mileage|Price\n\n";
        for(int i = 0; i < number_of_cars; i++){
            cout<<car_list[i] << endl << endl;
        }
    }

    //Function to display the total number of cars in inventory
    void display_total_number_of_cars(){
        cout<<"The total number of cars in our inventory are " << number_of_cars << endl;
    }

    //Function for editing a car details in car_list vector and .txt file
    void edit_car_details(string plate){
        int index = search_car(plate);
        string edited = "", temp;
        cout<<"Before edit: " << car_list[index] << endl;
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
        car_list[index] = edited;

        ofstream file("Car_names_list.txt");
        for(int i = 0; i < number_of_cars; i++){
            file<< car_list[i] + "\n";
        }
    }
};

class bikes : public vehicles{

};

int main(){
    //testing
    cars a;
    a.read_file();

    //a.display_car("BYX-365");

    //a.remove_car("BYX-365");

    //a.display_all_cars();

    //a.display_by_make("Honda");

    //a.display_within_price_range(4500000, 8000000);

    //a.display_car("X-88-X");

    //a.display_by_model("Alto");

    //a.display_by_year(2021);

    //a.add_car("Lamborghini", "Aventador", "SVJ", 2022, "X-88-X", "6500cc", "5km/l", 400000000);

    //a.remove_car("X-88-X");

    //a.display_by_model("H6");

    //a.display_total_number_of_cars();

    a.edit_car_details("BYX-365");
}
