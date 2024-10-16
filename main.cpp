#include <iostream>
#include <string>

using namespace std;

// Ingredient class
class Ingredient {
private:
    string name;
    double quantity;

public:
    // Constructor
    Ingredient(string name, double quantity) {
        this->name = name;
        this->quantity = quantity;
    }

    // Getter for name
    string getName() const {
        return this->name;
    }

    // Display function
    void displayIngredient() const {
        cout << "Ingredient: " << this->name << ", Quantity: " << this->quantity << " units" << endl;
    }

    // Destructor
    ~Ingredient() {
        cout << "Ingredient " << this->name << " is being deleted." << endl;
    }
};

int main() {
    // Dynamically allocate memory for Ingredient objects
    Ingredient* ingredient1 = new Ingredient("Sugar", 200);
    Ingredient* ingredient2 = new Ingredient("Flour", 500);

    // Display ingredient details
    ingredient1->displayIngredient();
    ingredient2->displayIngredient();

    // Clean up memory
    delete ingredient1; // Deallocate memory for ingredient1
    delete ingredient2; // Deallocate memory for ingredient2

    return 0;
}
