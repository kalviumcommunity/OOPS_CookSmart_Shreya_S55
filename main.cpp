#include <iostream>
#include <vector>
using namespace std;

// Base Class (Parent) 
class Appliance {
protected:
    string brand;
    int power; // in watts

public:
    // Constructor Overloading (Example of Polymorphism)
    Appliance() : brand("Unknown"), power(0) {
        cout << "Default Appliance constructor called" << endl;
    }
    
    Appliance(string b, int p) : brand(b), power(p) {
        cout << "Parameterized Appliance constructor called for " << brand << endl;
    }

    void displayApplianceInfo() const {
        cout << "Brand: " << brand << ", Power: " << power << "W" << endl;
    }

    // Virtual Destructor (For proper polymorphic behavior in inheritance)
    virtual ~Appliance() {
        cout << "Appliance destructor called for " << brand << endl;
    }
};

// Derived Class (Single Inheritance)
class SmartDevice : public Appliance {
protected:
    bool wifiEnabled;

public:
    // Constructor Overloading (Example of Polymorphism)
    SmartDevice() : Appliance(), wifiEnabled(false) {
        cout << "Default SmartDevice constructor called" << endl;
    }
    
    SmartDevice(string b, int p, bool wifi) : Appliance(b, p), wifiEnabled(wifi) {
        cout << "SmartDevice constructor called for " << brand << endl;
    }

    void displaySmartDeviceInfo() const {
        displayApplianceInfo();
        cout << "Wi-Fi Enabled: " << (wifiEnabled ? "Yes" : "No") << endl;
    }

    // Virtual Destructor for proper polymorphic behavior
    virtual ~SmartDevice() {
        cout << "SmartDevice destructor called for " << brand << endl;
    }
};

// Derived Class (Multi-Level Inheritance)
class SmartOven : public SmartDevice {
private:
    int temperatureRange; // in Celsius

public:
    // Constructor Overloading (Example of Polymorphism)
    SmartOven() : SmartDevice(), temperatureRange(0) {
        cout << "Default SmartOven constructor called" << endl;
    }
    
    SmartOven(string b, int p, bool wifi, int tempRange) 
        : SmartDevice(b, p, wifi), temperatureRange(tempRange) {
        cout << "SmartOven constructor called for " << brand << endl;
    }

    // Function Overloading (Example of Polymorphism)
    void setTemperature(int temp) {
        temperatureRange = temp;
        cout << "Temperature set to " << temperatureRange << "°C" << endl;
    }

    void setTemperature(double temp) {
        temperatureRange = static_cast<int>(temp);
        cout << "Temperature set to " << temperatureRange << "°C (from double input)" << endl;
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

// Main Function to demonstrate Inheritance and Polymorphism
int main() {
    // Demonstrating Inheritance
    cout << "\n--- Single Inheritance ---\n";
    SmartDevice mixer("Philips", 500, true);
    mixer.displaySmartDeviceInfo();

    // Demonstrating Multi-Level Inheritance
    cout << "\n--- Multi-Level Inheritance ---\n";
    SmartOven oven("LG", 1200, true, 250);
    oven.displayOvenInfo();
    
    // Demonstrating Constructor Overloading
    cout << "\n--- Constructor Overloading ---\n";
    SmartOven defaultOven;
    defaultOven.displayOvenInfo();
    
    // Demonstrating Function Overloading
    cout << "\n--- Function Overloading ---\n";
    oven.setTemperature(180); // Calls setTemperature(int)
    oven.setTemperature(200.5); // Calls setTemperature(double)
    
    return 0;
}
