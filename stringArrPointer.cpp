#include <iostream>
#include<string.h>
using namespace std;
int main() {
    int n = 5;
    string  *arr = new string[n];//allocate string array
    //Populating string array
    for(size_t i =0;i<n; i++){
        arr[i] = "String " + to_string(i+1);
    }
    //Printing string array elements
    for(size_t i =0;i<n; i++){
        cout<<arr[i]<<endl;
    }
    //deallocate dynamic memory
    delete[] arr;
    return 0;
}