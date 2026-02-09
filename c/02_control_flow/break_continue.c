#include <stdio.h>

int main(){

    // break    =   Break out of a loop (STOP)
    // continue =   Skip current cycle of a loop (SKIP)

    for(int i = 0; i < 20; i++){
        if(i == 7){
            continue;  // skips the rest of the for loop and starts at the next iteration
        } else if (i == 17){
            break; // ends the loop all together
        }
        printf("%i\n", i);
    }

    return 0;
}