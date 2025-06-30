//Using pointer to array to access 2D array created dynamically
#include <iostream>
using namespace std;

int main() {
    int rows;
    const int cols = 3 ;
    cout<<"Enter number of rows = ";
    cin>>rows;
    
    int (*arr)[cols] = new int[rows][cols]; //Pointer to array
    
    for(size_t i = 0; i<rows; i++)
        for(size_t j = 0; j<cols; j++)
        //    cin>>arr[i][j];
        arr[i][j] = (i+1)*10+j;

    for(size_t i = 0; i<rows; i++){
        int *rowptr = arr[i];
        for(size_t j = 0; j<cols; j++){
            // cout<<arr[i][j]<<" ";
            cout<<rowptr[j]<<" ";
     }
    cout<<endl;
    }

    delete[] arr;// to dellaocate memory

        

    

    return 0;
}