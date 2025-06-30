#include <iostream>
#include <memory>
using namespace std;
class MyClass{
    public:
    MyClass() {cout<<"Calling Constructor"<<endl;}
    ~MyClass() {cout<<"Calling Destructor"<<endl;}
    void memfunc() {cout<<"Calling Member function"<<endl;}
};
    shared_ptr<MyClass> createsharedPtr(){
        shared_ptr<MyClass>ptr = make_shared<MyClass>();
        return ptr;
    }

int main() {
    shared_ptr<MyClass> ptr1 = createsharedPtr();
    (*ptr1).memfunc();
    shared_ptr<MyClass> ptr2 = ptr1;
    (*ptr2).memfunc();
    // shared_ptr<int> ptr1 = make_shared<int>(25);
    // shared_ptr<int> ptr2 = ptr1;
    // cout<<"Value dereferenced by pointer = "<<*ptr2<<endl;
    ptr2.reset();
    cout<<"Shared instances = "<<ptr1.use_count()<<endl;
    //Dellaocated memory
    return 0;
}