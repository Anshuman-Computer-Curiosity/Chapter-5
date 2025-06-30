#include <iostream>
#include <string>
using namespace std;
class BaseString{
    public: virtual string getString() const{
        return "In Base Class";

    }
};
class DerivedString : public BaseString{
    public: string getString() const override{
        return "In Derived Class";
    }
};

int main() {
    char userChoice;
    cout<<"Enter D for derived class and any other character for base class";
    cin>>userChoice;
    BaseString *ptr;
    if(userChoice == 'D'||userChoice == 'd'){
        ptr = new DerivedString();
    }
    else{
        ptr = new BaseString();
    }
    cout<<ptr->getString()<<endl;
    delete ptr;//deallocating memory 
    
    return 0;
}
