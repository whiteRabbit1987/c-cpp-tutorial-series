#include <stdio.h>
#include <windows.h> // Windows
// Linux/Mac #include <unistd.h>  

int main() {

    // for loops    =   Repeat some code a limited # of times
    //                  for(Initialization; Condition; Update)


    for(int i = 10; i >= 0; i--){
        Sleep(1000); // Windows
        // sleep(100) Linux
        printf("%i\n", i);
    }

    printf("HAPPY NEW YEAR!");

    return 0;
}
