
#include<iostream>
using namespace std;
int main(){
    int number = 25;
    int *ptrVar = &number; // pointer variable pointing to the address of number
    cout<<"Address of number = "<<&number<<endl;
    cout<<"Value of number = "<<*ptrVar <<endl;
    cout<<"Address of pointer variable  ptrVar = "<<&ptrVar<<endl;

    int **ptrptr = &ptrVar;//Pointer to a Pointer of type int
    cout<<"Address of ptrVar = "<<*ptrptr<<endl;
    cout<<"Value of number = "<<**ptrptr<<endl;
    return 0;
}