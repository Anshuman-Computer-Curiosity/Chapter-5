#include <iostream>

using namespace std;
int main() {
   const char *str = "Hello";

   cout<<"Value = "<<&str<<endl;
   //Access string using pointer notation
   while(*str!='\0'){
        cout<<*str;
        str++;
   }
   cout<<endl;

//    //Access string using pointer notation
//    for(int i = 0;str[i]!='\0';i++){
//         cout<<(void *)&str[i]<<endl;
//         // str++;
//    }
//     cout<<endl;
    return 0;
}
