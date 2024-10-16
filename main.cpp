#include <iostream>
#include <string>

using namespace std;

class Ingredient {
private:
    string name;
    double quantity;

    // Static variables to track total ingredients and total quantity
    static int totalIngredients;
    static double totalQuantity;

public:
    // Constructor
    Ingredient(string name, double quantity) {
        this->name = name;
        this->quantity = quantity;

        // Update static variables
        totalIngredients++;
        totalQuantity += quantity;
    }

    // Getter for name
    string getName() const {
        return this->name;
    }

    // Function to display ingredient details
    void displayIngredient() const {
        cout << "Ingredient: " << this->name << ", Quantity: " << this->quantity << " units" << endl;
    }

    // Static function to display total ingredients and quantity
    static void displayTotals() {
        cout << "Total Ingredients: " << totalIngredients << endl;
        cout << "Total Quantity: " << totalQuantity << " units" << endl;
    }

    // Destructor
    ~Ingredient() {
        // Update static variables when an ingredient is destroyed
        totalIngredients--;
        totalQuantity -= quantity;
        cout << "Ingredient " << this->name << " is being deleted." << endl;
    }
};

// Initialize static variables
int Ingredient::totalIngredients = 0;
double Ingredient::totalQuantity = 0;

int main() {
    // Dynamically allocate memory for Ingredient objects
    Ingredient* ingredient1 = new Ingredient("Sugar", 200);
    Ingredient* ingredient2 = new Ingredient("Flour", 500);
    
    // Display ingredient details
    ingredient1->displayIngredient();
    ingredient2->displayIngredient();

    // Display totals
    Ingredient::displayTotals();

    // Clean up memory
    delete ingredient1; // Deallocate memory for ingredient1
    delete ingredient2; // Deallocate memory for ingredient2

    // Display totals after deletion
    Ingredient::displayTotals();

    return 0;
}
