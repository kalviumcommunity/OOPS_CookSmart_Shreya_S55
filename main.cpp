#include <iostream>
#include <string>

using namespace std;

// Class 1: Ingredient
class Ingredient {
public:
    // Constructor
    Ingredient(string name, double quantity) : name(name), quantity(quantity) {}

    // Member function to display ingredient details
    void displayIngredient() {
        cout << "Ingredient: " << name << ", Quantity: " << quantity << " units" << endl;
    }

private:
    string name;
    double quantity;
};

// Class 2: Recipe
class Recipe {
public:
    // Constructor
    Recipe(string name) : name(name) {}

    // Member function to display recipe name
    void displayRecipe() {
        cout << "Recipe: " << name << endl;
    }

private:
    string name;
};

int main() {
    // Create objects
    Ingredient ingredient1("Sugar", 200);
    Recipe recipe1("Cake");

    // Call member functions
    ingredient1.displayIngredient();
    recipe1.displayRecipe();

    return 0;
}
