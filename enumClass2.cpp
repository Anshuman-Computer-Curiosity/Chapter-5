#include <iostream>
using namespace std;

// Enumeration for ice cream flavors
enum class IceCream {
    MANGO,
    VANILLA,
    CHOCOLATE,
    STRAWBERRY
};

// Enumeration for fruits
enum class Fruits {
    APPLE,
    BANANA,
    MANGO,  
    ORANGE
};

// Function to display menu and handle user input
void displayMenu() {
    cout << "Choose a category:" << endl;
    cout << "1. Ice Cream" << endl;
    cout << "2. Fruits" << endl;
}

// Function to handle ice cream selection
void selectIceCream() {
    IceCream iceCreamChoice;
    int choice;

    cout << "Select an ice cream flavor:" << endl;
    cout << "1. Mango" << endl;
    cout << "2. Vanilla" << endl;
    cout << "3. Chocolate" << endl;
    cout << "4. Strawberry" << endl;
    cin >> choice;

    switch (choice) {
        case 1:
            iceCreamChoice = IceCream::MANGO;
            break;
        case 2:
            iceCreamChoice = IceCream::VANILLA;
            break;
        case 3:
            iceCreamChoice = IceCream::CHOCOLATE;
            break;
        case 4:
            iceCreamChoice = IceCream::STRAWBERRY;
            break;
        default:
            cout << "Invalid choice." << endl;
            return;
    }

    cout << "You chose: Ice Cream - " << static_cast<int>(iceCreamChoice) << endl;
}

// Function to handle fruit selection
void selectFruit() {
    Fruits fruitChoice;
    int choice;

    cout << "Select a fruit:" << endl;
    cout << "1. Apple" << endl;
    cout << "2. Banana" << endl;
    cout << "3. Mango" << endl;
    cout << "4. Orange" << endl;
    cin >> choice;

    switch (choice) {
        case 1:
            fruitChoice = Fruits::APPLE;
            break;
        case 2:
            fruitChoice = Fruits::BANANA;
            break;
        case 3:
            fruitChoice = Fruits::MANGO;
            break;
        case 4:
            fruitChoice = Fruits::ORANGE;
            break;
        default:
            cout << "Invalid choice." << endl;
            return;
    }

    cout << "You chose: Fruits - " << static_cast<int>(fruitChoice) << endl;
}

int main() {
    int categoryChoice;

    displayMenu();
    cin >> categoryChoice;

    switch (categoryChoice) {
        case 1:
            selectIceCream();
            break;
        case 2:
            selectFruit();
            break;
        default:
            cout << "Invalid category choice." << endl;
            break;
    }

    return 0;
}