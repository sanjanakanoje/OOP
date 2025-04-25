#include<iostream>
#include<string>

using namespace std;

class Vehicle {
public:
    string ID;
    string Make;
    string Model;
    string Year;
    string RentalRate;

    Vehicle(string id, string make, string model, string year, string rate)
        : ID(id), Make(make), Model(model), Year(year), RentalRate(rate) {}

    virtual void displayDetails() {
        cout << "ID: " << ID << endl;
        cout << "Make: " << Make << endl;
        cout << "Model: " << Model << endl;
        cout << "Year: " << Year << endl;
        cout << "Rental Rate: " << RentalRate << endl;
    }
};

class Car : public Vehicle {
public:
    int NumberOfDoors;

    Car(string id, string make, string model, string year, string rate, int doors)
        : Vehicle(id, make, model, year, rate), NumberOfDoors(doors) {}

    void displayDetails() override {
        Vehicle::displayDetails();
        cout << "Number of Doors: " << NumberOfDoors << endl;
    }
};

class RentalSystem {
public:
    Vehicle* vehicle;

    void addVehicle(Vehicle* v) {
        vehicle = v;
    }

    void displayAvailableVehicles() {
        vehicle->displayDetails();
    }
};

int main() {
    RentalSystem rentalSystem;

    Car car("CARSuz2925", "Suzuki", "abc", "2018", "60/day", 4);
    rentalSystem.addVehicle(&car);
    rentalSystem.displayAvailableVehicles();

    return 0;
}








