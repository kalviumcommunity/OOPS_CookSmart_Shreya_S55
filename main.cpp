#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Ingredient {
private:
    string name;
    int quantity;
    static int totalIngredients; // Static variable to track total ingredients

public:
    // Constructor
    Ingredient(string n, int q) : name(n), quantity(q) {
        totalIngredients++;
    }

    // Accessor for name
    string getName() const {
        return name;
    }

    // Mutator for name
    void setName(const string& n) {
        name = n;
    }

    // Accessor for quantity
    int getQuantity() const {
        return quantity;
    }

    // Mutator for quantity
    void setQuantity(int q) {
        quantity = q;
    }

    // Static member function to access static variable
    static int getTotalIngredients() {
        return totalIngredients;
    }

    // Destructor
    ~Ingredient() {
        totalIngredients--;
    }
};

// Initialize static variable
int Ingredient::totalIngredients = 0;

class Recipe {
private:
    string recipeName;
    vector<Ingredient> ingredients;

public:
    // Constructor
    Recipe(string name) : recipeName(name) {}

    // Accessor for recipe name
    string getRecipeName() const {
        return recipeName;
    }

    // Mutator for recipe name
    void setRecipeName(const string& name) {
        recipeName = name;
    }

    // Method to add ingredient
    void addIngredient(const Ingredient& ingredient) {
        ingredients.push_back(ingredient);
    }

    // Method to display recipe ingredients
    void displayIngredients() const {
        cout << "Recipe: " << recipeName << endl;
        for (const auto& ingredient : ingredients) {
            cout << "- " << ingredient.getName() << ": " << ingredient.getQuantity() << " grams" << endl;
        }
    }
};

int main() {
    // Create ingredients dynamically
    Ingredient* sugar = new Ingredient("Sugar", 200);
    Ingredient* salt = new Ingredient("Salt", 100);

    // Create recipe and add ingredients
    Recipe recipe("Cake");
    recipe.addIngredient(*sugar);
    recipe.addIngredient(*salt);

    // Display recipe details
    recipe.displayIngredients();

    // Display total number of ingredients
    cout << "Total Ingredients: " << Ingredient::getTotalIngredients() << endl;

    // Clean up dynamically allocated memory
    delete sugar;
    delete salt;

    // Check the total ingredients after deletion
    cout << "Total Ingredients after deletion: " << Ingredient::getTotalIngredients() << endl;

    return 0;
}
