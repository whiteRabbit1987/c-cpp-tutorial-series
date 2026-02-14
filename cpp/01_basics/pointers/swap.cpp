#include <iostream>

void swap(int* a, int* b);

int main() {
	int a = 5, b = 10;
	swap(&a, &b);
	std::cout << "a = " << a << "\nb = " << b << std::endl;
	return 0;
}

void swap(int* a, int* b){
	int swp = *a;
	*a = *b;
	*b = swp;
}