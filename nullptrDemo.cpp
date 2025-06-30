
//Ambiguity while function overloading with NULL pointer
#include <iostream>
using namespace std;
void func(double *ptr){
    cout<<"Function with double* parameter"<<endl;
}
void func(int* ptr){
    cout<<"Function with int* parameter"<<endl;
}

int main() {
    func(static_cast<double*>(nullptr));
    
    return 0;
}