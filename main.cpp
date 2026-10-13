
#include <iostream>
#include <string>
using namespace std;


class Vehicle {
private:
    int vehicleID;
    string manufacturer, model;
    int year;
    static int totalVehicles;

public:
    Vehicle() {
        vehicleID = 0;
        manufacturer = "";
        model = "";
        year = 0;
        totalVehicles++;
    }

    Vehicle(int id, string manu, string mod, int yr) {
        vehicleID = id;
        manufacturer = manu;
        model = mod;
        year = yr;
        totalVehicles++;
    }

    ~Vehicle() {
        totalVehicles--;
    }

    int getVehicleID() { return vehicleID; }

    void setVehicleID(int id) {
        vehicleID = id;
    }

    void setManufacturer(string manu) {
        manufacturer = manu;
    }

    void setModel(string mod) {
        model = mod;
    }

    void setYear(int yr) {
        year = yr;
    }

    static int getTotalVehicles() {
        return totalVehicles;
    }

    void display() {
        cout << "\n Vehicle ID   : " << vehicleID;
        cout << "\n Manufacturer : " << manufacturer;
        cout << "\n Model        : " << model;
        cout << "\n Year         : " << year << endl;
    }
};

int Vehicle::totalVehicles = 0;



class Car : public Vehicle {
private:
    string fuelType;

public:
    Car() : Vehicle() {
        fuelType = "";
    }

    void setFuelType(string fuel) {
        fuelType = fuel;
    }

    string getFuelType() {
        return fuelType;
    }

    void display() {
        Vehicle::display();
        cout << "Fuel Type    : " << fuelType << endl;
    }
};



class ElectricCar : public Car {
private:
    double batteryCapacity;

public:
    ElectricCar() : Car() {
        batteryCapacity = 0;
    }

    void setBatteryCapacity(double battery) {
        batteryCapacity = battery;
    }

    void display() {
        Car::display();
        cout << "Battery Capacity: "
            << batteryCapacity << " kWh\n";
    }
};



class Aircraft : public Vehicle {
private:
    double flightRange;

public:
    Aircraft() : Vehicle() {
        flightRange = 0;
    }

    void setFlightRange(double range) {
        flightRange = range;
    }

    void display() {
        Vehicle::display();
        cout << "Flight Range : " << flightRange << " km\n";
    }
};



class FlyingCar : public Car {
private:
    double flyingRange;

public:
    FlyingCar() : Car() {
        flyingRange = 0;
    }

    void setFlyingRange(double range) {
        flyingRange = range;
    }

    void display() {
        Car::display();
        cout << "Flight Range : " << flyingRange << " km\n";
    }
};



class SportsCar : public ElectricCar {
private:
    double topSpeed;

public:
    SportsCar() : ElectricCar() {
        topSpeed = 0;
    }

    void setTopSpeed(double speed) {
        topSpeed = speed;
    }

    void display() {
        ElectricCar::display();
        cout << "Top Speed    : " << topSpeed << " km/h\n";
    }
};



class Sedan : public Car {
public:
    Sedan() : Car() {}
};



class SUV : public Car {
public:
    SUV() : Car() {}
};



class VehicleRegistry {
private:
    static int MAX;
    Vehicle vehicles[100];
    string types[100];
    string fuels[100];
    double batteries[100];
    double ranges[100];
    double speeds[100];
    int count;

public:
    VehicleRegistry() {
        count = 0;
    }

    void addVehicle() {
        if (count >= MAX) {
            cout << "Registry is full!\n";
        }
        else {
            int type, id, year;
            string manu, model, fuel = "", typeName;
            double battery = 0, range = 0, speed = 0;

            cout << "\n1. Car\n2. Electric Car\n3. Aircraft\n";
            cout << "4. Flying Car\n5. Sports Car\n";
            cout << "6. Sedan\n7. SUV\n";
            cout << "Enter vehicle type: ";
            cin >> type;

            if (type < 1 || type > 7) {
                cout << "Invalid vehicle type!\n";
            }
            else {
                cout << "Enter Vehicle ID: ";
                cin >> id;

                if (searchById(id)) {
                    cout << "Vehicle ID already exists!\n";
                }
                else {
                    cout << "Enter Manufacturer: ";
                    getline(cin >> ws, manu);

                    cout << "Enter Model: ";
                    getline(cin, model);

                    cout << "Enter Year: ";
                    cin >> year;

                    if (type == 1) {
                        typeName = "Car";
                    }
                    else if (type == 2) {
                        typeName = "Electric Car";
                    }
                    else if (type == 3) {
                        typeName = "Aircraft";
                    }
                    else if (type == 4) {
                        typeName = "Flying Car";
                    }
                    else if (type == 5) {
                        typeName = "Sports Car";
                    }
                    else if (type == 6) {
                        typeName = "Sedan";
                    }
                    else {
                        typeName = "SUV";
                    }

                    if (type != 3) {
                        cout << "Enter Fuel Type: ";
                        cin >> fuel;
                    }

                    if (type == 2 || type == 5) {
                        cout << "Enter Battery Capacity: ";
                        cin >> battery;
                    }

                    if (type == 3 || type == 4) {
                        cout << "Enter Flight Range: ";
                        cin >> range;
                    }

                    if (type == 5) {
                        cout << "Enter Top Speed: ";
                        cin >> speed;
                    }

                    vehicles[count].setVehicleID(id);
                    vehicles[count].setManufacturer(manu);
                    vehicles[count].setModel(model);
                    vehicles[count].setYear(year);

                    types[count] = typeName;
                    fuels[count] = fuel;
                    batteries[count] = battery;
                    ranges[count] = range;
                    speeds[count] = speed;

                    count++;
                    cout << "Vehicle added successfully!\n";
                }
            }
        }
    }

    int searchById(int id) {
        int i = 0;

        while (i < count) {
            if (vehicles[i].getVehicleID() == id) {
                return i + 1;
            }
            i++;
        }

        return 0;
    }

    void display() {
        if (count == 0) {
            cout << "No vehicles registered!\n";
        }
        else {
            int i = 0;

            while (i < count) {
                cout << "\n========================\n";
                cout << "Vehicle Type : " << types[i] << endl;
                vehicles[i].display();

                if (types[i] != "Aircraft") {
                    cout << "Fuel Type    : " << fuels[i] << endl;
                }

                if (types[i] == "Electric Car" ||
                    types[i] == "Sports Car") {
                    cout << "Battery      : "
                         << batteries[i] << " kWh\n";
                }

                if (types[i] == "Aircraft" ||
                    types[i] == "Flying Car") {
                    cout << "Flight Range : "
                         << ranges[i] << " km\n";
                }

                if (types[i] == "Sports Car") {
                    cout << "Top Speed    : "
                         << speeds[i] << " km/h\n";
                }

                i++;
            }
        }
    }

    void searchVehicle() {
        int id;
        cout << "Enter Vehicle ID: ";
        cin >> id;

        if (searchById(id) == 0) {
            cout << "Vehicle not found!\n";
        }
        else {
            int i = 0;

            while (i < count) {
                if (vehicles[i].getVehicleID() == id) {
                    cout << "\nVehicle Type : " << types[i] << endl;
                    vehicles[i].display();

                    if (types[i] != "Aircraft") {
                        cout << "Fuel Type    : " << fuels[i] << endl;
                    }

                    if (types[i] == "Electric Car" ||
                        types[i] == "Sports Car") {
                        cout << "Battery      : "
                             << batteries[i] << " kWh\n";
                    }

                    if (types[i] == "Aircraft" ||
                        types[i] == "Flying Car") {
                        cout << "Flight Range : "
                             << ranges[i] << " km\n";
                    }

                    if (types[i] == "Sports Car") {
                        cout << "Top Speed    : "
                             << speeds[i] << " km/h\n";
                    }
                }

                i++;
            }
        }
    }
};

int VehicleRegistry::MAX = 100;
int main() {
    VehicleRegistry registry;
    int choice;

    do {
        cout << "\n===== VEHICLE REGISTRY SYSTEM =====\n";
        cout << "1. Add Vehicle\n";
        cout << "2. View All Vehicles\n";
        cout << "3. Search Vehicle by ID\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            registry.addVehicle();
        }
        else if (choice == 2) {
            registry.display();
        }
        else if (choice == 3) {
            registry.searchVehicle();
        }
        else if (choice == 4) {
            cout << "Thank you for using Vehicle Registry System!\n";
        }
        else {
            cout << "Invalid choice!\n";
        }

    } while (choice != 4);

    return 0;
}
