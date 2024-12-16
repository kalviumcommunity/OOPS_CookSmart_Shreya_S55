#include <iostream>
#include <vector>
#include <string>

using namespace std;

class RecipeManager {
private:
    struct Recipe {
        string name;
        vector<string> ingredients;
    };
    
    vector<Recipe> recipes;

public:
    // Adds a new recipe to the list
    void addRecipe(const string& name, const vector<string>& ingredients) {
        Recipe newRecipe = {name, ingredients};
        recipes.push_back(newRecipe);
        cout << "Recipe added: " << name << endl;
    }

    // Lists all the recipes
    void listRecipes() const {
        cout << "List of Recipes:" << endl;
        for (const auto& recipe : recipes) {
            cout << "Recipe: " << recipe.name << endl;
            cout << "Ingredients: ";
            for (const auto& ingredient : recipe.ingredients) {
                cout << ingredient << " ";
            }
            cout << endl;
        }
    }

    // Deletes a recipe from the list
    void deleteRecipe(const string& name) {
        for (auto it = recipes.begin(); it != recipes.end(); ++it) {
            if (it->name == name) {
                recipes.erase(it);
                cout << "Recipe deleted: " << name << endl;
                return;
            }
        }
        cout << "Recipe not found: " << name << endl;
    }
};

// 🟢 Class 2: NotificationService (Handles notifications, separate from Recipe logic)
class NotificationService {
public:
    void sendNotification(const string& message) {
        cout << "🔔 Notification: " << message << endl;
    }
};

int main() {
    // Creating instances of the classes
    RecipeManager recipeManager;
    NotificationService notificationService;

    // 📘 Managing recipes
    recipeManager.addRecipe("Pasta", {"Noodles", "Tomato Sauce", "Cheese"});
    recipeManager.addRecipe("Smoothie", {"Banana", "Milk", "Honey"});

    recipeManager.listRecipes();

    recipeManager.deleteRecipe("Smoothie");

    // 🔔 Sending a notification
    notificationService.sendNotification("Reminder: Buy more tomatoes!");

    return 0;
}
