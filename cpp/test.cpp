#include <iostream>

class Print{
	private:
	int val;
	public:
		Print(int val){ this->val = val; }
	void print(){ std::cout << val << std::endl; }
};

int main() {
	Print print(55);
	print.print();
	return 0;
}