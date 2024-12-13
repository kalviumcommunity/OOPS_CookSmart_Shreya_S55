#include <iostream>
#include <vector>
using namespace std;

// Base Class (Parent) 
class Appliance {
protected:
    string brand;
    int power; // in watts

public:
    // Parameterized Constructor
    Appliance(string b, int p) : brand(b), power(p) {
        cout << "Appliance constructor called for " << brand << endl;
    }

    void displayApplianceInfo() const {
        cout << "Brand: " << brand << ", Power: " << power << "W" << endl;
    }

    // Destructor
    ~Appliance() {
        cout << "Appliance destructor called for " << brand << endl;
    }
};

// Derived Class (Single Inheritance)
class SmartDevice : public Appliance {
protected:
    bool wifiEnabled;

public:
    // Parameterized Constructor
    SmartDevice(string b, int p, bool wifi) : Appliance(b, p), wifiEnabled(wifi) {
        cout << "SmartDevice constructor called for " << brand << endl;
    }

    void displaySmartDeviceInfo() const {
        displayApplianceInfo();
        cout << "Wi-Fi Enabled: " << (wifiEnabled ? "Yes" : "No") << endl;
    }

    // Destructor
    ~SmartDevice() {
        cout << "SmartDevice destructor called for " << brand << endl;
    }
};

// Derived Class (Multi-Level Inheritance)
class SmartOven : public SmartDevice {
private:
    int temperatureRange; // in Celsius

public:
    // Parameterized Constructor
    SmartOven(string b, int p, bool wifi, int tempRange) 
        : SmartDevice(b, p, wifi), temperatureRange(tempRange) {
        cout << "SmartOven constructor called for " << brand << endl;
    }

    void displayOvenInfo() const {
        displaySmartDeviceInfo();
        cout << "Temperature Range: " << temperatureRange << "°C" << endl;
    }

    // Destructor
    ~SmartOven() {
        cout << "SmartOven destructor called for " << brand << endl;
    }
};

// Main Function to demonstrate Inheritance
int main() {
    // Single Inheritance Example
    cout << "\n--- Single Inheritance ---\n";
    SmartDevice mixer("Philips", 500, true);
    mixer.displaySmartDeviceInfo();

    // Multi-Level Inheritance Example
    cout << "\n--- Multi-Level Inheritance ---\n";
    SmartOven oven("LG", 1200, true, 250);
    oven.displayOvenInfo();

    return 0;
}
