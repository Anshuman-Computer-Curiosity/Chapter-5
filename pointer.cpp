#include<iostream>
using namespace std;

int main(){
    double a = 10.5;
    double  *ptrVar = &a; //Pointer variable declaration and initialization
    // ptrVar = &a; //Pointing to the address of 'a'

    cout<< "Value of pointer = "<<*ptrVar<<endl;//Dereference pointer variable
    cout<< "Address of varaible a = "<<a<<endl;
    // a = 35.4;
    *ptrVar = 52.6;
    cout<< "Value of pointer = "<<*ptrVar<<endl;
    cout<< "Value of a = "<<a<<endl;
    return 0;
}