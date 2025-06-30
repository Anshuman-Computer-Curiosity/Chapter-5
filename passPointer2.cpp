#include<iostream>
using namespace std;
struct Person{
    string name;
    int age;
};
void display(const Person *ptr){
    cout<<"Name = "<<ptr->name<<" Age = "<<ptr->age<<endl;
}

int main() {
    Person amit = {"Amit",45};
    display(&amit);
    
    return 0;
}