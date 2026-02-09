// enums    =   a user-defined data type that consists 
//              of paired named-integer constants.
//              GREAT if you have a set of potential options


#include <iostream>

enum Day {  sunday, 
            monday, 
            tuesday, 
            wednesday, 
            thursday, 
            friday = 100, 
            saturday
        };

int main(){

    Day today = saturday;

    switch(today){
        case sunday: std::cout << "It is Susnday!\n";
                       break;
        case 1: std::cout << "It is Monday!\n";
                       break;
        case tuesday: std::cout << "It is Tuesday!\n";
                       break;
        case 3: std::cout << "It is Wednesday!\n";
                       break;
        case thursday: std::cout << "It is Thursday!\n";
                       break;
        case 100: std::cout << "It is Friday!\n";
                       break;
        case 101: std::cout << "It is Saturday!\n";
                       break;
    }

    return 0;
}