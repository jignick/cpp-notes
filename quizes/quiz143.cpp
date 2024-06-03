/*
Create a struct called IntPair that holds two integers. 
Add a member function named print that prints the value of the two integers.

The following program function should compile:
*/

#include <iostream>

struct IntPair {
	int a{};
	int b{};

	void print() {
		std::cout << a << " " << b << std::endl;
	}
	bool isEqual(IntPair pair) {
		return ((a == pair.a) && (b == pair.b)) ? 1 : 0;
	}
};


int main()
{
	IntPair p1{ 1, 2 };
	IntPair p2{ 3, 4 };

	std::cout << "p1: ";
	p1.print();

	std::cout << "p2: ";
	p2.print();

	std::cout << "p1 and p1 " << (p1.isEqual(p1) ? "are equal\n" : "are not equal\n");
	std::cout << "p1 and p2 " << (p1.isEqual(p2) ? "are equal\n" : "are not equal\n");

	return 0;
}