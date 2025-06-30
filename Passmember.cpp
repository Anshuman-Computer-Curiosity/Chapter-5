#include <iostream>
#include <string>
using namespace std;

struct Employee {
    int empId;
    double salary;
};
void display(int e, double sal){ //Pass by Value
    cout<<"Employee Id :"<<e<<" salary : " <<sal <<endl;
}
void updateSalary(double &sal, double increment){ //Pass by reference
    sal += increment;
}
void assignNewId(int *eId, int newId){
    if(eId){
        *eId = newId; //modified using pointer 
    }
}

int main() {
    Employee emp = {101, 50000.0};
    display(emp.empId, emp.salary); //passing emp members by value
    updateSalary(emp.salary, 550.0); //passing emp salary by reference
    display(emp.empId, emp.salary);
    assignNewId(&emp.empId,105); //passing emp empId by address
    display(emp.empId, emp.salary);
    return 0;
}