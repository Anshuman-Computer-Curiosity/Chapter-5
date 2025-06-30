// Array of Pointers statically
#include <iostream>
using namespace std;
int main() {
    int rows = 3, cols = 4;
    
    //Allocate memory for array of pointers statically
       int **arr = new int*[rows];

      //allocating memory for each row
      for (size_t i = 0; i < rows; i++){
            arr[i] = new int[cols];
      }

      //enter values for each row
      for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++)
            arr[i][j] = 10*(i+1)+j; //cin>>arr[i][j];
      }
      
      //print values in each row
      for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            cout<<arr[i][j]<<"  ";
        }
        cout<<endl;
      }
      
      //deallocting memory for each row
      for(int i=0; i<rows; i++)
        delete[] arr[i];
      
      //deallocting memory for each row
        delete[] arr;
     
     

    return 0;
}