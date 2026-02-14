#include <iostream>
#include <cstring>

void reverse(char* str);

int main() {

	char str[] = "Hello";
	std::cout << str << " reversed: ";
	reverse(str);
	std::cout << str << std::endl;

	return 0;
}

void reverse(char* str){
	char* start = str;
	char* end = str + strlen(str) - 1;

	for(; start < end;){
		char aux = *start;
		*start = *end;
		*end = aux;
		start++;
		end--;
	}
}