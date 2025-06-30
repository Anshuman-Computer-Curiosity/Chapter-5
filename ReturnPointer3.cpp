#include <iostream>
#include <vector>
using namespace std;
int * findElement(vector<int> &vec, int value){
    for(int &num:vec){
        if(num == value)
            return &num; 
    }   
        return nullptr;    
    
}
int main() {
    vector <int> numbers = {10,20,30,40,50};
    int num = 60;
    int *ptr = findElement(numbers, num);
    if(ptr!=nullptr)
        cout<<"Element found = "<<*ptr<<endl;
    else
        cout<<"Element not found"<<endl;    
    return 0;
}