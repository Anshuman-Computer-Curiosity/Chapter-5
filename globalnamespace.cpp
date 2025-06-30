#include <iostream>
using namespace std;
int x = 40; //Gloabal variable
void myFunction(){
    cout<<"In global namespace, function MyFunction()" <<endl;
}
namespace MyNamespaceA{
    int x = 25 + ::x;
    void myFunction(){
        cout<<"In MyNamespaceA namespace, function MyFunction()" <<endl;
        ::myFunction();
    }
}

int main() {
    cout<<"In main function, x = "<< x <<endl;
    cout<<"In main function, MyNamespaceA::x = "<< MyNamespaceA::x <<endl;
    MyNamespaceA::myFunction();
    // myFunction();
    return 0;
}
