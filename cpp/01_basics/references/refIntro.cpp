#include <iostream>

// reference	=	if we pass a variable reference as argument we access the variable itself	
//					'normal' arguments create a copy (pass by value), regardless what it is named	

void copyValue(int number){
	number += 10;
}

void refValue(int& number){
	number += 10;
}

int main() {

	int number = 5;
	printf("Number at start: %d\n", number);

	copyValue(number);
	printf("Number after copyValue: %d\n", number);

	refValue(number);
	printf("Number after refValue: %d\n", number);

	return 0;
}
