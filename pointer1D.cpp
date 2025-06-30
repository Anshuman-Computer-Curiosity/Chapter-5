#include<iostream>
using namespace std;

int main(){
    int arr[]={10,20,30,40,50};
    int *ptrVar = arr;
    int arrSize = sizeof(arr)/sizeof(arr[0]);
    cout<<"Array elements are : \n";
    for(int i=0;i<arrSize;i++){
        cout<< *(ptrVar + i)<<" ";
    }
    return 0;
}