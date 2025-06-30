#include <iostream>
#include <cstring>
using namespace std;

struct Student {
    int rollNo;
    char name[50];
    double marks;
    void displayInfo() const {
        cout << "Roll number: " << rollNo << ", Name: " << name << ", marks: "<< marks <<endl;    
    } 
};

int main() {
    int n;
    cout<<"Enter the number of student : ";
    cin>>n;
    Student *stu = new Student[n]; //Allocation

    for(int i=0; i<n ; ++i){
        cout<<"\n Enter details of student "<<i+1<<": ";
        cout<<" \nRoll number : ";
        cin>>stu[i].rollNo;
        cin.ignore();
        cout<<"Name : ";
        cin.getline((stu+i)->name, 50);
        cout<<"Marks : ";
        cin>>(stu+i)->marks;
    }
    cout<<"Student Details :\n";
    for(int i=0; i<n ; ++i){
        (stu+i)->displayInfo();
    }

    delete[] stu; //Deallocation
    return 0;
}