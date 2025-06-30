#include <iostream>
#include <string>
using namespace std;

struct Employee {
    int empId;
    double salary;
};

// Function to display Employee details (pass individual members by value)
void display(int empId, double salary) {
    cout << "Employee ID: " << empId << ", Salary: " << salary << endl;
}

// Function to update salary (pass by reference)
void updateSalary(double& salary, double increment) {
    salary += increment; // Modify the original salary
}

// Function to assign new Employee ID (pass by pointer)
void assignNewId(int* empId, int newId) {
    if (empId) {
        *empId = newId; // Modify the ID through the pointer
    }
}

int main() {
    // Create an Employee structure
    Employee emp = {101, 50000.0};
    
    cout << "Original Employee Details:\n";
    display(emp.empId, emp.salary); // Pass by value to display details
    
    // Update salary using pass by reference
    updateSalary(emp.salary, 5000.0);
    cout << "\nAfter Salary Update:\n";
    display(emp.empId, emp.salary); // Updated details
    
    // Assign a new ID using pass by pointer
    assignNewId(&emp.empId, 102);
    cout << "\nAfter Updating Employee ID:\n";
    display(emp.empId, emp.salary); // Display updated details
    
    return 0;
}