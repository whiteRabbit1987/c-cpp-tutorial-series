#include <stdio.h>
#include <math.h>

int main(){
    
    // int x = -9;
    // x = sqrt(x);
    // x = pow(x, 2);
    // x = abs(x);
    // printf("%d\n", x);

    float y = 3.94;
    // y = round(y);
    // y = ceil(y);
    // y = floor(y);
    // y = log(y);
    // y = sin(y);
    // y = cos(y);
    // y = tan(y);

    for(int i = 0; i < 20; i++){
        int power = pow(i, 2);
        float root = sqrt(i);

        printf("%d squared is %d.", i, power);
        printf("\nThe square root of %d is %.2f\n\n", i, root);
    }
    
    return 0;
}
























