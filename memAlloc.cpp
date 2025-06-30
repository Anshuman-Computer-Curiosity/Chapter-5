#include <iostream>
using namespace std;
int main() {
    int **ptrto2D;
    ptrto2D = new int*[3]; // create a 1-dimensional array of pointers - 3 rows
    for(int i=0;i<3;i++)
        ptrto2D[i] = new  int[5]; // each pointer points to an 5 column integer array

    ptrto2D[1][2]= 20;
    cout<<ptrto2D[1][2] <<endl;

    for(int i=0;i<3;i++){
        delete[] ptrto2D[i];
    }
    delete[] ptrto2D;    
    return 0;
}
