#include <iostream>
#include <fstream>
#include <string>

void inputValueToFile() {
	std::string filename;
	std::cout << "Enter file name / create a new file: ";
	std::getline(std::cin, filename);
	std::ofstream file(filename, std::ios::app);

	if (file.is_open()) 
		std::cout << "Open Success.\n";
	else {
		std::cout << "Failed to open/create file.\n";
		exit(0);
	}

	std::string n;
	
	std::cout << "Start typing...\n";
	while (true) {
		n.clear();
		std::getline(std::cin, n);
		if (n == "exit") break; 
		file << n << std::endl;
	}
	std::cout << "File Closing...\n";
	file.close();
}

void outputValueFromFile() {
	std::string filename;
	std::cout << "Enter file name: ";

	std::getline(std::cin, filename);
	std::ifstream file(filename);

	if (file.is_open())
		std::cout << "Open Success.\n";
	else {
		std::cout << "Failed to open.\n";
		exit(0);
	}

	std::string n;
	std::cout << "Start reading file...\n";
	while (file) {
		std::getline(file, n);
		std::cout << n << std::endl;
	}
	std::cout << "Closing reading file...\n";

	file.close();
}

int main() {
	inputValueToFile();
	outputValueFromFile();
	
	return 0;
}