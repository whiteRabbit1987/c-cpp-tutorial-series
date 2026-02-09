//  format specifiers =   Special tokens that begin with a % symbol,
//                        followed by a character that specifies the data type
//                        and optional modifiers (width, precision, flags).
//                        They control how data is displayed or interpreted.
  
#include <stdio.h>

int main(){

    int age = 25;
    float price = 19.99;
    double pi = 3.1415926535;
    char currency = '$';
    char name[] = "David";

    printf("%d\n", age);
    printf("%.2f\n", price);
    printf("%.2lf\n", pi);
    printf("%c\n", currency);
    printf("%s\n", name);

    int num = 25;
    float price = 19.99;
    float price2 = 1.50;
    float price3 = -100.00;


    // width
    printf("%03d\n", num);
    printf("%04d\n", num);
    printf("%05d\n\n", num);

    // pos - neg
    printf("%+d\n", num);
    printf("%+d\n", num);
    printf("%+d\n\n", num);

    // precision
    printf("%+7.2f\n", price);
    printf("%+7.2f\n", price2);
    printf("%+7.2f\n", price3);
    
    return 0;
}