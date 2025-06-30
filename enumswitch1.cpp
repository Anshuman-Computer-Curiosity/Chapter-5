#include <iostream>
#include <string>
using namespace std;
enum Direction {UP, DOWN, LEFT, RIGHT};
string move(Direction dir){
    switch(dir){
    case Direction::UP : return " UP ";
    case Direction::DOWN : return " DOWN ";
    case Direction::LEFT : return " LEFT ";
    case Direction::RIGHT : return " RIGHT ";
    default : return " Unknown ";
    }
}

int main() {
    cout<< "Move " << move(Direction::UP) <<endl;
    cout<< "Move " << move(static_cast<Direction> (1.9)) <<endl;
    cout<< "Move " << move(int(3.9)) <<endl;    
    return 0;
}