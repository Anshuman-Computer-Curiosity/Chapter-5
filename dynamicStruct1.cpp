#include <iostream>
#include <cstring>
using namespace std;
struct Student {
    int rollNo;
    char name[50];
    float marks;
};

int main() {
    // Use nothrow with new
    Student* ptr = new (nothrow) Student;

    if (ptr == nullptr) {
        cerr << "Memory allocation failed." << endl;
        return 1; // Exit program
    }

    // Initialize and use the structure
    ptr->rollNo = 2201;
    strncpy(ptr->name, "Varun", sizeof(ptr->name));
    ptr->marks = 94.8;

    cout << "Roll No: " << ptr->rollNo << endl;
    cout << "Name: " << ptr->name << endl;
    cout << "Percentage: " << ptr->marks << endl;

    // Free memory
    delete ptr;

    return 0;
}