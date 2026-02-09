#include <iostream>

int main(){
    using std::cout;
    using std::cin;

    //if statement  =   do something if a condition is true.
    //                  if not, then don't do it.

    int age;

    cout << "How old are you: ";
    cin >> age;

    if(age < 18){
        cout << "You must be 18+ to enter!";
    } else if (age > 65){
        cout << "You are too old to enter!";
    } else {
        cout << "Welcome!";
    }

    return 0;
}