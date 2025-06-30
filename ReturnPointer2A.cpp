// Creating factory function show how to return pointer from function
#include <iostream>
#include <string>
using namespace std;
class Person{
    private : 
            string name;
            int age;
    public :
            Person(const string& name,int age):name(name), age(age){}

            void display() const{//constant member function
                cout<<"Name = "<<name<<" Age = "<<age<<endl;
            }        
};
//Factory function
Person * createPerson(const string& name,int age){
    return new Person(name,age); // return new object
}

int main() {
    Person *ptr = createPerson("Kapil", 45);
    if(ptr!=nullptr){
        ptr->display();
        delete ptr;
    }
    else{
        cout<<"Failed to allocate memory"<<endl;
    }
    return 0;
}