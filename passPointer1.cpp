#include<iostream>
using namespace std;
void printArray(int *arrptr, int size){
    for(int i=0; i<size; i++){
        cout<<arrptr[i]<<" ";
    }

    cout<<endl;
}
void modifyArray(int *arrptr, int size){
    for(int i=0; i<size; i++){
        *(arrptr+i)*=2;//arrptr[i]*=2;
    }
}


int main() {
    int arr[] = {10,20,30,40,50};
    int arrSize = sizeof(arr)/sizeof(arr[0]);
    printArray(arr,arrSize);
    modifyArray(arr,arrSize);
    printArray(arr,arrSize);
    
    return 0;
}