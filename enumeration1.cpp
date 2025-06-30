#include <iostream>
#include<string>
using namespace std;

enum Day{SUNDAY, MONDAY, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY, SATURDAY};

int main() {
    string dayNames [] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    for( int i =SUNDAY; i<=SATURDAY;i++)
        cout<<"Day "<<i<< " : "<<dayNames[i]<<endl;
    
    int MONDAY =  12;
    cout<<MONDAY<<endl;   
    return 0;
}