#include <stdio.h>

void printVariable(){
    char name[] = "Inside";
    printf("%s", name);
}

int main(){

    // variable scoope  =   Refers to where a variable is recognized and accessible.
    //                      Variables can share the same name if
    //                      they're in different scopes {}

    char name[] = "In main\n";
    printf("%s", name);
    printVariable();
    

    return 0;
}