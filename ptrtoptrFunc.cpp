//Pass pointers by reference to functions
#include <iostream>
using namespace std;
void allocateMem(int **ptr, int size){
    *ptr = new int[size]; 
    for(int i=0;i<size;i++)
        (*ptr)[i] = i*2;
}
void printArr(int *arr, int size) {
    for(int i=0;i<size;i++)
        cout<<arr[i]<<" ";
    cout<<endl;

}

int main() {
    int *arrptr = nullptr;
    allocateMem(&arrptr,5);  //passing the address of arrptr 
    printArr(arrptr,5);     //printing using the passed pointer
    delete [] arrptr;       //deleting dynamically allocated memory
    return 0;
}