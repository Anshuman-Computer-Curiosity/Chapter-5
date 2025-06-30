#include <iostream>
#include <string>
using namespace std;

struct Date {
    int dd;   
    int mm;   
    int yy;   
    void displayDate() const {
        cout << dd << "-" << mm << "-" << yy;
    }
    // Date(int d, int m, int y) : dd(d), mm(m), yy(y) {}
};

struct Student {
    int rollNo; 
    string name; 
	Date dob;

    void displayInfo() const {
        cout << "Roll number: " << rollNo << ", Name: " << name << ", DOB: ";
        dob.displayDate(); // Call displayDate() for Date object
        cout << endl;
    }  
    // Student(int i, string a, Date dt) : rollNo(i), name(a), dob(dt) {}

};

int main() {
    Student *ptr = new (nothrow) Student; //Allocation
    if(ptr == nullptr){
        cerr <<"Memory allocation failed" <<endl;
        return 1;
    }
    ptr->rollNo = 2201;
    ptr->name = "Varun";
    cout<<"Enter dob in dd-mm-yy :";
    cin>> ptr->dob.dd ;
    cin>> ptr->dob.mm ;
    cin>> ptr->dob.yy ;

    ptr->displayInfo();
    delete ptr; // deallocation

    return 0;
}