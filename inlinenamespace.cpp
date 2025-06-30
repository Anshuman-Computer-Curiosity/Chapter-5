#include <iostream>
using namespace std;
// namespace Mynamespace{
//     int x = 10;
//     void display(){
//         cout<<"Initial version" << endl;
//     }
// }
namespace Mynamespace{
    inline namespace v2{
    void display(){
        cout<<"Updated version" << endl;
    }
    }
    inline namespace v1{
    void display(){
        cout<<"Initial version" << endl;
    }
    }
}

int main() {
    // cout<< " x = " <<Mynamespace::x << endl;
    Mynamespace::v1::display();
    
    return 0;
}