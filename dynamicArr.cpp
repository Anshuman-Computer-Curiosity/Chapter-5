//dynamic allocation of 1D array
#include<iostream>
using namespace std;

int main() {
    int size;
    cout<<"Enter number of elements in the array = ";
    cin>>size;
    //dynamically allocate memory to array
     int *arr =   new int[size];

     for(int i=0;i<size;i++)//populating array
        // arr[i] = (i+1)*10;//cin>>arr[i]
        *(arr+i) = (i+1)*10;//cin>>arr[i]

     for(int i=0;i<size;i++)//displaying array contents
        cout<<arr[i]<<" ";

    delete[] arr; //deallocating dynamically allocated memory
                 //to avoid memory leak, we use "delete" keyword followed by a pointer name.
    return 0;
}