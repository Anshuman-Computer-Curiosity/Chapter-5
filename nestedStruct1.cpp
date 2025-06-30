#include <iostream>
#include <string>
using namespace std;

struct Date {
    int dd{};   // Default value is 0
    int mm{};   // Default value is 0
    int yy{};   // Default value is 0
    void displayDate() const {
        cout << dd << "-" << mm << "-" << yy;
    }
    // Date(int d, int m, int y) : dd(d), mm(m), yy(y) {}
};

struct Student {
    int rollNo{}; // Default value is 0
    char name[50]{}; //default value is empty string
	Date dob{}; //default intialized date

    void displayInfo() const {
        cout << "Roll number: " << rollNo << ", Name: " << name << ", DOB: ";
        dob.displayDate(); // Call displayDate() for Date object
        cout << endl;
    }  
    // Student(int i, string a, Date dt) : rollNo(i), name(a), dob(dt) {}

};


int main() {
    // Default initialization
    Student student1;

    cout << "Default Values:" << endl;
    student1.displayInfo();

    // Explicit Initialization
    Student student2 = {2201, "Varun", {25, 12, 2000} };
    
    cout << "\nExplicitly Initialized Values:" << endl;
    student2.displayInfo();
    return 0;
}