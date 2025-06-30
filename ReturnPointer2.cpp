#include <iostream>
#include <string>
using namespace std;

// Class representing a person
class Person {
public:
    string name;
    int age;
};

// Factory function to create a Person object
Person* createPerson(const string& name, int age) {
    Person* ptr = new Person(); // Dynamically allocate memory for a Person object
    ptr->name = name; // Initialize the name
    ptr->age = age; // Initialize the age
    return ptr; // Return the pointer to the Person object
}

int main() {
    Person* ptr = createPerson("Kapil", 45); // Create a Person object

    // Use the pointer to access the Person object
    cout << "Name: " << ptr->name << ", Age: " << ptr->age << endl;

    // Don't forget to deallocate the memory allocated for the Person object
    delete ptr;

    return 0;
}