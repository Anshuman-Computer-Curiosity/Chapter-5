#include <iostream>
#include <string>
using namespace std;
// Define an enumeration for vehicle types
enum VehicleType {
    CAR,
    TRUCK,
    MOTORCYCLE
};

// Define a class to represent a Vehicle
class Vehicle {
private:
    string brand;
    string model;
    int year;
    VehicleType type;

public:
    // Constructor to initialize a Vehicle object
    Vehicle(const string& brand, const string& model, int year, VehicleType type)
        : brand(brand), model(model), year(year), type(type) {}

    // Method to display information about the vehicle
    void displayInfo() const {
        cout << "Vehicle: " << brand << " " << model << " (" << year << ")" << endl;
        cout << "Type: ";
        switch (type) {
            case CAR:
                cout << "Car";
                break;
            case TRUCK:
                cout << "Truck";
                break;
            case MOTORCYCLE:
                cout << "Motorcycle";
                break;
            default:
                cout << "Unknown";
        }
        cout << endl;
    }
};

int main() {
    // Create instances of Vehicle using the Vehicle class
    Vehicle car("Toyota", "Camry", 2020, CAR);
    Vehicle truck("Ford", "F-150", 2018, TRUCK);
    Vehicle motorcycle("Honda", "CBR600RR", 2022, MOTORCYCLE);

    // Display information about each vehicle
    cout << "Vehicle Information:" << endl;
    car.displayInfo();
    truck.displayInfo();
    motorcycle.displayInfo();

    return 0;
}