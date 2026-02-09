#include <iostream>

// enum class =   a strongly-typed enumeration introduced in C++11
//                unlike traditional enums, enum class prevents 
//                implicit conversions to integers, providing type safety
//                GREAT when you want to avoid accidental misuse of enum values
//                requires scope resolution to access enum values

enum class WEEKDAYS { MON=1, TUE, WED, THU, FRI, SAT, SUN };
enum MONTHS { JAN=1, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC };

int main(){

    WEEKDAYS day = WEEKDAYS::WED;   
    std::cout << "The value of WED is: " << static_cast<int>(day) << std::endl;

    MONTHS month = APR;
    std::cout << "The value of APR is: " << month << std::endl;

    return 0;
}
