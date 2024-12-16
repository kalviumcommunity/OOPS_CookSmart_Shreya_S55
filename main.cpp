#include <iostream>
#include <vector>
#include <string>

using namespace std;

// 🟢 Base Class for Ingredient
class Ingredient {
protected:
    string name;
    int quantity;

public:
    // Constructor for base class
    Ingredient(const string& name, int quantity) : name(name), quantity(quantity) {}

    // Virtual method to get ingredient details
    virtual void getDetails() const {
        cout << "🟢 Ingredient: " << name << ", Quantity: " << quantity << " units" << endl;
    }

    // Virtual destructor
    virtual ~Ingredient() {}
};

// 🟢 Derived Class 1: Perishable Ingredient
class PerishableIngredient : public Ingredient {
private:
    string expiryDate;

public:
    // Constructor for PerishableIngredient
    PerishableIngredient(const string& name, int quantity, const string& expiryDate) 
        : Ingredient(name, quantity), expiryDate(expiryDate) {}

    // Overriding the getDetails method
    void getDetails() const override {
        cout << "🥗 Perishable Ingredient: " << name 
             << ", Quantity: " << quantity 
             << " units, Expiry Date: " << expiryDate << endl;
    }
};

// 🟢 Derived Class 2: NonPerishable Ingredient
class NonPerishableIngredient : public Ingredient {
public:
    // Constructor for NonPerishableIngredient
    NonPerishableIngredient(const string& name, int quantity) 
        : Ingredient(name, quantity) {}

    // No need to override getDetails() since it follows the base class behavior
};

// 🟢 RecipeManager (Handles everything related to recipes)
class RecipeManager {
private:
    vector<Ingredient*> ingredients;

public:
    // Adds an ingredient (both Perishable and NonPerishable)
    void addIngredient(Ingredient* ingredient) {
        ingredients.push_back(ingredient);
        cout << "📦 Ingredient added to the list: " << endl;
        ingredient->getDetails();
    }

    // Lists all ingredients in the recipe
    void listIngredients() const {
        cout << "🍽️ List of Ingredients:" << endl;
        for (const auto& ingredient : ingredients) {
            ingredient->getDetails();
        }
    }

    // Destructor to clean up dynamically allocated memory
    ~RecipeManager() {
        for (auto ingredient : ingredients) {
            delete ingredient;
        }
    }
};

int main() {
    // Create objects of different ingredient types
    PerishableIngredient* tomato = new PerishableIngredient("Tomato", 5, "2024-12-20");
    NonPerishableIngredient* sugar = new NonPerishableIngredient("Sugar", 10);

    // 📘 Manage Recipes
    RecipeManager recipeManager;

    // Add ingredients to the recipe (Using Liskov Substitution Principle)
    recipeManager.addIngredient(tomato);
    recipeManager.addIngredient(sugar);

    // List all ingredients
    recipeManager.listIngredients();

    return 0;
}
