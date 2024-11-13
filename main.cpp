#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Ingredient {
private:
    string name;
    int quantity;

public:
    // Default Constructor
    Ingredient() : name("Unknown"), quantity(0) {
        cout << "Default constructor called for Ingredient." << endl;
    }

    // Parameterized Constructor
    Ingredient(string n, int q) : name(n), quantity(q) {
        cout << "Parameterized constructor called for Ingredient: " << name << endl;
    }

    // Destructor
    ~Ingredient() {
        cout << "Destructor called for Ingredient: " << name << endl;
    }

    string getName() const {
        return name;
    }

    int getQuantity() const {
        return quantity;
    }

    void setQuantity(int q) {
        quantity = q;
    }
};

class Recipe {
private:
    string recipeName;
    vector<Ingredient> ingredients;

public:
    // Default Constructor
    Recipe() : recipeName("Unnamed Recipe") {
        cout << "Default constructor called for Recipe." << endl;
    }

    // Parameterized Constructor
    Recipe(string name) : recipeName(name) {
        cout << "Parameterized constructor called for Recipe: " << recipeName << endl;
    }

    // Destructor
    ~Recipe() {
        cout << "Destructor called for Recipe: " << recipeName << endl;
    }

    void addIngredient(const Ingredient& ingredient) {
        ingredients.push_back(ingredient);
    }

    void displayRecipe() const {
        cout << "Recipe: " << recipeName << endl;
        for (const auto& ingredient : ingredients) {
            cout << "- " << ingredient.getName() << ": " << ingredient.getQuantity() << "g" << endl;
        }
    }
};

int main() {
    // Using default constructor for Ingredient
    Ingredient defaultIngredient;
    defaultIngredient.setQuantity(50);

    // Using parameterized constructor for Ingredient
    Ingredient sugar("Sugar", 200);
    Ingredient salt("Salt", 100);

    // Using default constructor for Recipe
    Recipe defaultRecipe;
    defaultRecipe.addIngredient(defaultIngredient);

    // Using parameterized constructor for Recipe
    Recipe cake("Cake");
    cake.addIngredient(sugar);
    cake.addIngredient(salt);

    // Display recipes
    defaultRecipe.displayRecipe();
    cake.displayRecipe();

    return 0;
}
