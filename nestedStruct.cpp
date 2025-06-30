#include<iostream>
#include<string>
using namespace std;
struct Date {
    int dd {};
    int mm {};
    int yy {};
    void displayDate() const{
        cout<<dd<<"-" <<mm << "-"<<yy<<endl;
    }    
    //constructor
    Date (int d, int m, int y): dd(d), mm(m), yy(y) {}
};


struct Student {
    int rollNo;
    string name;
    Date dob;

    void displayInfo() const{
        cout<<"Roll number : "<<rollNo 
            <<" Name :" <<name 
            << ", date of birth : ";
        dob.displayDate();
        cout<<endl;
    }    
    Student(int r, string n, Date dt):rollNo(r),name (n),dob(dt){ }
};

int main() {
    // Student s1 = {2201, "Varun", {15,03,2021}};
    Student s1 (2201, "Varun", Date(15,03,2021));
    s1.displayInfo();
    s1.rollNo = 3205;
    s1.dob.dd = 25;
    s1.displayInfo();
    return 0;
}