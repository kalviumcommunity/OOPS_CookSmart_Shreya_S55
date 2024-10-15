#include <iostream>
#include <string>

using namespace std;

// Class: Ingredient
class Ingredient {
public:
    // Constructor
    Ingredient(string name = "", double quantity = 0) : name(name), quantity(quantity) {}

    // Member function to display ingredient details
    void displayIngredient() const {
        cout << "Ingredient: " << name << ", Quantity: " << quantity << " units" << endl;
    }

private:
    string name;
    double quantity;
};

int main() {
    // Create an array of Ingredient objects
    Ingredient ingredients[3] = {
        Ingredient("Sugar", 200),
        Ingredient("Flour", 500),
        Ingredient("Butter", 100)
    };

    // Display the details of each ingredient using a loop
    cout << "List of Ingredients:" << endl;
    for (int i = 0; i < 3; ++i) {
        ingredients[i].displayIngredient();
    }

    return 0;
}
