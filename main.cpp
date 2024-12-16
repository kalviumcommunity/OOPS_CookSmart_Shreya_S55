#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Abstract class (Base Class)
class KitchenAppliance {
protected:
    string brand;

public:
    // Constructor
    KitchenAppliance(string b) : brand(b) {}

    // Pure Virtual Function (abstract function)
    virtual void displayInfo() const = 0;

    // Virtual Destructor
    virtual ~KitchenAppliance() {
        cout << "KitchenAppliance destructor called for brand: " << brand << endl;
    }
};

// Derived Class 1: SmartDevice (inherits from KitchenAppliance)
class SmartDevice : public KitchenAppliance {
protected:
    string connectivityType;

public:
    // Constructor
    SmartDevice(string b, string c) : KitchenAppliance(b), connectivityType(c) {}

    // Overriding the pure virtual function
    void displayInfo() const override {
        cout << "Smart Device Info:" << endl;
        cout << "Brand: " << brand << endl;
        cout << "Connectivity: " << connectivityType << endl;
    }

    // Destructor
    ~SmartDevice() {
        cout << "SmartDevice destructor called for brand: " << brand << endl;
    }
};

// Derived Class 2: SmartOven (inherits from SmartDevice)
class SmartOven : public SmartDevice {
private:
    int maxTemperature;

public:
    // Constructor
    SmartOven(string b, string c, int temp) : SmartDevice(b, c), maxTemperature(temp) {}

    // Overriding the pure virtual function
    void displayInfo() const override {
        cout << "Smart Oven Info:" << endl;
        cout << "Brand: " << brand << endl;
        cout << "Connectivity: " << connectivityType << endl;
        cout << "Max Temperature: " << maxTemperature << "°C" << endl;
    }

    // Destructor
    ~SmartOven() {
        cout << "SmartOven destructor called for brand: " << brand << endl;
    }
};

int main() {
    // Create a vector of pointers to KitchenAppliance objects
    vector<KitchenAppliance*> appliances;

    // Create and add objects to the vector (using polymorphism)
    appliances.push_back(new SmartDevice("Philips", "Wi-Fi"));
    appliances.push_back(new SmartOven("LG", "Bluetooth", 250));

    // Call the displayInfo() function for each appliance
    cout << "---- Displaying Appliance Information ----" << endl;
    for (KitchenAppliance* appliance : appliances) {
        appliance->displayInfo();
        cout << "------------------------------------------" << endl;
    }

    // Clean up memory (delete pointers)
    for (KitchenAppliance* appliance : appliances) {
        delete appliance;
    }

    return 0;
}
