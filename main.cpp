#include <iostream>
#include <vector>
#include <string>

using namespace std;

// 🟢 Base Class (Abstract) for Notification
class Notification {
public:
    virtual void sendNotification(const string& message) = 0; // Pure virtual function
};

// 🟢 Derived Class 1: EmailNotification (Extends the base class)
class EmailNotification : public Notification {
public:
    void sendNotification(const string& message) override {
        cout << "📧 Email Notification Sent: " << message << endl;
    }
};

// 🟢 Derived Class 2: SMSNotification (Extends the base class)
class SMSNotification : public Notification {
public:
    void sendNotification(const string& message) override {
        cout << "📱 SMS Notification Sent: " << message << endl;
    }
};

// 🟢 Derived Class 3: PushNotification (Extends the base class)
class PushNotification : public Notification {
public:
    void sendNotification(const string& message) override {
        cout << "📲 Push Notification Sent: " << message << endl;
    }
};

// 🟢 RecipeManager (Handles everything related to recipes)
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
};

int main() {
    // Create instances of different types of notifications
    EmailNotification emailNotifier;
    SMSNotification smsNotifier;
    PushNotification pushNotifier;

    // 📧 Send an email notification
    emailNotifier.sendNotification("New recipe added: Pasta");

    // 📱 Send an SMS notification
    smsNotifier.sendNotification("Low stock on Tomatoes!");

    // 📲 Send a push notification
    pushNotifier.sendNotification("Recipe of the day: Smoothie");

    // 📘 Manage Recipes
    RecipeManager recipeManager;
    recipeManager.addRecipe("Pasta", {"Noodles", "Tomato Sauce", "Cheese"});
    recipeManager.listRecipes();

    return 0;
}
