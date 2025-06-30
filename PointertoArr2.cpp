//Program to explain how to access 2D array using pointer to array
#include <iostream>
using namespace std;
int main() {
    int arr[2][3] = { {10, 20, 30},
                     {40, 50, 60}};

    int (*arrptr)[3] = arr; //Pointer to an array
    for(int i=0; i<2; i++){
        for(int j=0; j<3; j++){
          cout<<arrptr[i][j]<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}