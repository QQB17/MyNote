#include <iostream>

int main() {
	int var = 0;
	
	std::cout << "Please enter a number: ";
	std::cin >> var; // user input variable
	std::cout << var << std::endl; // output variable

	std::cerr << "Error occured." << std::endl; // display error message immediately without buffer
	std::clog << "Log call." << std::endl; // store in the buffer and display in window

	return 0;
}