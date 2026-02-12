#include <stdio.h>
#include <string.h>

void getname(char *name, size_t size);

int main(){
    char name[50];

    getname(name, sizeof(name));
    if(strlen(name) < 1){
        printf("YOU DID NOT ENTER A NAME!");
        getname(name, sizeof(name));
    } else {
        printf("Hello: %s", name);
    }
    return 0;
}

void getname(char *name, size_t size){
    printf("Enter your name: ");
    fgets(name, size, stdin);
    name[strlen(name) - 1] = '\0';
}