//Single pointer and 2D array
#include<iostream>
using namespace std;

int main(){
    int num_rows=3;
    int num_cols=3;
    int arr[][num_cols]={{10,20,30}, {40,50,60}, {70,80,90}};
    // int *ptrVar =  &arr[0][0];//assigning the address of first element to ptrVar
    int *ptrVar =  *arr;//dereferncing name of array
    cout<<"Elements in the  array are : \n";
    for(int i=0 ;i < num_rows ; i++ ){
        int *rowptr = ptrVar + i * num_cols;//pointing each row to next row
        for(int j=0 ;j <num_cols;j++){
            // cout<<ptrVar[i*num_cols + j]<<" ";
            // cout<<*(ptrVar+i*num_cols + j)<<" ";
            // cout<<*(rowptr+ j)<<" ";
            cout<<rowptr[j]<<" ";
            
        }
        cout<<endl;
    }
            
    return 0;
}