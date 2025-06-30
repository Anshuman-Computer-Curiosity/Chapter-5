#include <iostream>
using namespace std;
int x = 20; //global variable
void display(){
        
        cout<<"In anonymous namespace  " << endl;
    }
namespace {
    int x = 15;
    void display(){
        x = x + ::x;
        cout<<"In anonymous namespace , x = " <<x << endl;
    }
}

int main() {
    cout <<"x = " << ::x << endl;

    ::display();
    
    return 0;
}