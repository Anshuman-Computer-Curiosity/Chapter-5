#include <iostream>
using namespace std;
int main() {
    char *ptr = '\0';

    if(ptr == 0){
        cout<<"It is a NULL pointer"<<endl;
    }
    else{
        cout<<"It is not a NULL pointer"<<endl;
    }
    
    return 0;
}