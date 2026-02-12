#include <stdio.h>
#include <math.h>

int main(){

    double radius = 0.0;
    double area = 0.0;
    double surfaceArea = 0.0;
    double vol = 0.0;
    double const PI = 3.14159;

    printf("Enter the radius: ");
    scanf("%lf", &radius);

    area = PI * pow(radius, 2);
    surfaceArea = 4 * PI * pow(radius, 2);
    vol = (4.0/3.0) * PI * pow(radius, 3);

    printf("Area: %.2lf", area);
    printf("\nSurface Area: %.2lf", surfaceArea);
    printf("\nVolume: %.2lf", vol);

    return 0;
}