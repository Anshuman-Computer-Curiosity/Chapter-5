//dynamically allocate memory for 2D array
#include <iostream>
using namespace std;
int main() {
    int rows = 3, cols = 3;//You can input from user, cin>>rows;cin>>cols;
    int *arr = new int[rows*cols];//Dynamically Allocate memory

    for(int i=0;i<rows;i++)
        for(int j=0;j<cols;j++)
            *(arr+(i*cols)+j) =  (i+1)*10 + j;

    cout<<"Elements of 2D array are :\n";
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            cout<<arr[(i*cols)+j] <<" ";
    }
    cout<<endl;
}
    delete[] arr;//deallocate memory that is dynamically allocated

    return 0;
}