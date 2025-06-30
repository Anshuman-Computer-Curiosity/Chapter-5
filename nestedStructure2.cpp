#include <iostream>
#include <cstring>
using namespace std;
struct Date {
    int dd, mm, yy;

    // Constructor for Date structure
    Date(int day = 1, int month = 1, int year = 2000)
        : dd(day), mm(month), yy(year) {}
};

struct Student {
    int rollNo;
    char name[50];
    Date DOB; // Nested structure

    // Constructor for Student structure
    Student(int r, const char* n, Date dateOfBirth)
        : rollNo(r), DOB(dateOfBirth) { // Use member initializer list
        strncpy(name, n, sizeof(name)); // Copy name safely
        name[sizeof(name) - 1] = '\0';  // Null-terminate the string
    }

    // Function to display student details
    void display() const {
        cout << "Roll No: " << rollNo << endl;
        cout << "Name: " << name << endl;
        cout << "DOB: " << DOB.dd << "-" << DOB.mm << "-" << DOB.yy << endl;
    }
};

int main() {
    // Initialize a Student object using constructors
    Student student(101, "Varun", Date(25, 12, 2023));

    // Display student details
    student.display();

    return 0;
}