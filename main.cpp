#include <iostream>
#include <string>

using namespace std;

// Class: Ingredient
class Ingredient {
private:
    string name;
    double quantity;

public:
    // Constructor
    Ingredient(string name, double quantity) {
        // Using this pointer to resolve name conflict
        this->name = name;
        this->quantity = quantity;
    }

    // Getter function to return the name of the ingredient
    string getName() const {
        return this->name;
    }

    // Set the quantity using this pointer
    void setQuantity(double quantity) {
        this->quantity = quantity;
    }

    // Member function to display ingredient details
    void displayIngredient() const {
        cout << "Ingredient: " << this->name << ", Quantity: " << this->quantity << " units" << endl;
    }

    // Function to compare quantities using this pointer
    bool isGreaterThan(const Ingredient& other) const {
        return this->quantity > other.quantity;
    }
};

int main() {
    // Create two Ingredient objects
    Ingredient ingredient1("Sugar", 200);
    Ingredient ingredient2("Flour", 500);

    // Display their details
    ingredient1.displayIngredient();
    ingredient2.displayIngredient();

    // Compare quantities using the isGreaterThan method
    if (ingredient1.isGreaterThan(ingredient2)) {
        cout << ingredient1.getName() << " has more quantity than " << ingredient2.getName() << endl;
    } else {
        cout << ingredient2.getName() << " has more quantity than " << ingredient1.getName() << endl;
    }

    return 0;
}
