#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Ingredient {
private:
    string name;
    int quantity;

public:
    Ingredient(string n, int q) : name(n), quantity(q) {}

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
    vector<Ingredient> ingredients; // List of ingredients for this recipe

public:
    Recipe(string name) : recipeName(name) {}

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
    Ingredient sugar("Sugar", 200);
    Ingredient salt("Salt", 100);

    Recipe cake("Cake");
    cake.addIngredient(sugar);
    cake.addIngredient(salt);

    cake.displayRecipe();

    return 0;
}
