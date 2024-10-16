#include <iostream>
#include <string>
using namespace std;

class Ingredient {
private:
    string name;
    int quantity;
    static int totalIngredients; // Static variable to track total ingredients

public:
    Ingredient(string n, int q) : name(n), quantity(q) {
        totalIngredients++; // Increment total ingredients whenever a new ingredient is added
    }

    string getName() const {
        return name;
    }

    int getQuantity() const {
        return quantity;
    }

    static int getTotalIngredients() {
        return totalIngredients; // Static member function to access static variable
    }

    ~Ingredient() {
        totalIngredients--; // Decrement total ingredients when an ingredient is destroyed
    }
};

// Initialize static variable
int Ingredient::totalIngredients = 0;

int main() {
    // Dynamically allocate ingredients using new and delete
    Ingredient* ingredient1 = new Ingredient("Sugar", 200);
    Ingredient* ingredient2 = new Ingredient("Salt", 100);

    cout << "Ingredient 1: " << ingredient1->getName() << ", Quantity: " << ingredient1->getQuantity() << endl;
    cout << "Ingredient 2: " << ingredient2->getName() << ", Quantity: " << ingredient2->getQuantity() << endl;

    // Display total number of ingredients using static member function
    cout << "Total Ingredients: " << Ingredient::getTotalIngredients() << endl;

    // Clean up dynamically allocated memory
    delete ingredient1;
    delete ingredient2;

    // Check the total ingredients after deletion
    cout << "Total Ingredients after deletion: " << Ingredient::getTotalIngredients() << endl;

    return 0;
}
