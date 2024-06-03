#include <iostream>
#include <cstdint>

/*
Write the following program: The user is asked to enter 2 floating point numbers (use doubles).
The user is then asked to enter one of the following mathematical symbols: +, -, *, or /. 
The program computes the answer on the two numbers the user entered and prints the results. 
If the user enters an invalid symbol, the program should print nothing.

Example of program:

Enter a double value: 6.2
Enter a double value: 5
Enter +, -, *, or /: *
6.2 * 5 is 31
*/
double readDouble() {
	double x{};

	std::cout << "Enter a floating number: ";
	std::cin >> x;

	return x;
}
int main() {
	double x{readDouble()}, y{readDouble()};
	char modifier{};

	std::cout << "Enter +, -, *, or /: ";
	std::cin >> modifier;
	
	switch(modifier){
		case '+':
			std::cout << x << ' ' << modifier << ' ' << y << " is " << x + y;
			break;
		case '-':
			std::cout << x << ' ' << modifier << ' ' << y << " is " << x - y;
			break;
		case '*':
			std::cout << x << ' ' << modifier << ' ' << y << " is " << x * y;
			break;
		case '/':
			if (y != 0) {
				std::cout << x << ' ' << modifier << ' ' << y << " is " << x / y;
			}
			else {
				std::cout << "Division by zero.";
			}
			break;
		default:
			std::cout << "Wrong modifier selected.";
	}


	return 0;
}