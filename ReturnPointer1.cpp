//Function returning pointer - dynamically allocate memory
#include<iostream>
using namespace std;
int * createMemory(int size){
    int *arrptr = new int[size];//dynamically allocating memory
    for (int i=0; i<size; ++i)
        arrptr[i] = (i+1)*10;
    return arrptr;    
}

int main() {
    int size = 5;
    int *ptr = createMemory(size);
    for(int i=0; i<size; ++i)
        cout<<ptr[i] <<" ";
    cout<<endl;
    delete[] ptr;  //deallocate memory  
    return 0;
}
