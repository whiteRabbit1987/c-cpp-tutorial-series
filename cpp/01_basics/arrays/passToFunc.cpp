#include <iostream>

double getTotal(double array[], int size);

int main(){
    double prices[] = {2.50, 45.50, 90.25, 15.75};
    int size = sizeof(prices)/sizeof(prices[0]);
    double total = getTotal(prices, size);
    std::cout << "$" << total;
    return 0;
}
double getTotal(double array[], int size){
    double sum;
    for(int i = 0; i < size; i++){
        sum += array[i];
    }
    return sum;
}