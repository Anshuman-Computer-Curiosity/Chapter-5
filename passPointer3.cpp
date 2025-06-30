#include <iostream>
using namespace std;
void allocateMemory(int **ptr, int size){
    *ptr = new int[size];// allocate memory dynamically for array
    for(int i=0; i < size; i++)
        (*ptr)[i] = (i+1)*10; //populating array
}


int main() {
    int *ptr = nullptr;
    int size = 5;
    allocateMemory(&ptr,size);
    for(int i=0; i < size; i++)
      cout<<ptr[i]<<" ";
    cout<<endl;  
    delete[] ptr; // deallocate
    return 0;
}