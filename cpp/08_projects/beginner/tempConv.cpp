#include <iostream>

double toFahr(double celsius);
double toCel(double fahren);

int main(){
    double temp = 0.0;
    double converted = 0.0;
    char unit = '\0';

    std::cout << "Enter a unit of temp. to convert to (c/f): ";
    std::cin >> unit;
    std::cout << "Enter a temperature to convert: ";
    std::cin >> temp;

    if(unit == 'c'){
        converted = toCel(temp);
    } else {
        converted = toFahr(temp);
    }
    
    std::cout << temp << " converted to " << unit << " is: " << converted << '\n';
    return 0;
}

double toFahr(double celsius){
    // F = Celsius * (9/5) + 32
    double result = celsius * (9.0/5.0) + 32;
    return result;
}
double toCel(double fahren){
    // C = (fahrenheit-32)*(5.0/9.0)
    double result = (fahren-32)*(5.0/9.0);
    return result;
}


