#include<iostream>
#include<ostream>
#include<fstream>
#include<vector>
#include<string>
using namespace std;

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
    cars() : file("Car_names_list.txt"), number_of_cars(0) {}

    //reading from .txt file
    void read_file(){
        number_of_cars = 52;
        car_list.resize(number_of_cars);

        for(int i = 0; i < number_of_cars; i++){
            if(getline(file, car_list[i])){
            } else{
                break;
            }
        }
    }

    void add_car(string make, string model, string variant, int year, string number_plate, string engine, string mileage, int price){
        number_of_cars += 1;
        string new_car = make + " " + model + " " + variant + " " + to_string(year) + " " + number_plate + " " + engine + " " + mileage + " " + to_string(price);
        car_list.push_back(new_car);
    }

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

    void display_car(string number_plate){
        int index = search_car(number_plate);
        if(index != -1){
            cout<<"\n-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-";
            cout<< "\nMake|Model|Variant|Year|Number-Plate|Engine|Mileage|Price\n\n";
            cout<< car_list[index] << endl;
        }
    }

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

    void remove_car(string number_plate){
        int index = search_car(number_plate);
        if(index != -1){
            car_list.erase(car_list.begin() + index);
            number_of_cars -= 1;
        }
    }

    void display_all_cars(){
        cout<<"\n-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-";
        cout<< "\nMake|Model|Variant|Year|Number-Plate|Engine|Mileage|Price\n\n";
        for(int i = 0; i < number_of_cars; i++){
            cout<<car_list[i] << endl << endl;
        }
    }
};

class bikes : public vehicles{

};

int main(){
    //testing
    cars a;
    a.read_file();

    a.add_car("Lamborghini", "Aventador", "SVJ", 2022, "X-88-X", "6500cc", "5km/l", 400000000);

    //a.display_car("BYX-365");
    //a.remove_car("BYX-365");

    //a.display_all_cars();

    //a.display_by_make("Honda");

    //a.display_within_price_range(4500000, 8000000);

    //a.display_car("X-88-X");

    //a.display_by_model("Alto");

    a.display_by_year(2021);
}
