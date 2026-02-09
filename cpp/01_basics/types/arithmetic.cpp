#include <iostream>

int main(){

    // arithmetic operators =   return the result of a specific 
    //                          arithmetic operation (+ - * /)

    int students = 20;
    students = students + 1;
    students++;
    students+= 5;
    std::cout << "Current students: " << students << '\n';

    int teachers = 5;
    teachers = teachers -1;
    teachers--;
    teachers-= 2;
    std::cout << "Current teachers: " << teachers << '\n';

    int houseKeepers = 10;
    houseKeepers = houseKeepers * 2;
    houseKeepers /= 2;
    std::cout << "Current housekeepers: " << houseKeepers << '\n';

    int remainder = students % (houseKeepers + 1);
    std::cout << "Some modulo operation: " << remainder << '\n';

    int classRooms = 23;
    int evenOdd = classRooms % 2;
    if(evenOdd){
        std::cout << "ODD number of classrooms";
    } else {
        std::cout << "Even number of classrooms";
    }

    return 0;
}