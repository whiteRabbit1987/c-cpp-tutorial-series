#include <iostream>

struct Car{
    std::string model;
    int year;
    std::string color;
};

void printCar(Car car);
void paintCar(Car &car, std::string color);

int main(){

    Car car1;
    Car car2;

    car1.model = "Camaro";
    car1.year = 2013;
    car1.color = "Black";

    car2.model = "Focus";
    car2.year = 2018;
    car2.color = "Silver";

    printCar(car1);
    printCar(car2);

    paintCar(car1, "Red");
    printCar(car1);

    return 0;
}
void printCar(Car car){
    std::cout << car.model << ":\t - ";
    std::cout << car.year << "\t - ";
    std::cout << car.color << '\n';
}
void paintCar(Car &car, std::string color){
    car.color = color;
}