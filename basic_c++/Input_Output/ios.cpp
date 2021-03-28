#include <iostream>
#include <sstream>
#include <fstream>

// Warning: Make sure to set back to default setting after manipulator the output

class basic_ios {
public:
	void set_boolalpha() {
		bool num = 1;
		std::cout << "Set boolalpha: " << std::boolalpha << num
			<< "\tWithout set boolalpha: " << std::noboolalpha << num << '\n';
	}

	void set_basefield() {
		int num = 128;
		std::cout << "Octal: " << std::oct << num
			<< "\tHexadecimal: " << std::hex << num
			<< "\t\tDecimal: " << std::dec << num << '\n';
	}

	void set_floatfield() {
		float pi = 3.14159;
		std::cout << "Hex Float: " << std::hexfloat << pi // break when float point is more than 5
			<< "\t\tDefault Float: " << std::defaultfloat << pi << '\n';
	} 

	void set_fixed_float_point() {
		double euler_const = 2.71828182845904523536;

		// default cout.precision is 5, change the precision
		std::cout.precision(8);
		std::cout << "Scientific float: " << std::scientific << euler_const
			<< "\tFixed float: " << std::fixed << euler_const
			<< "\t\tDefault float : " << std::defaultfloat  << euler_const << '\n';
	}

	void show_base() {
		int num = 255;
		std::cout << "Show hexadecimal base: " << std::hex << std::showbase << num
			<< "\tWithout show hexadecimal base: " << std::noshowbase << num << std::dec << '\n';
	}
		 
	void show_decimal_point() {
		double x = 10, y = 3.142;
		std::cout.precision(5);
		std::cout << "Show decimal point: " << std::showpoint << x << " "  << y
			<< "\tWithout show decimal point: " << std::noshowpoint << x << " " <<y << '\n';
	}

	void show_positive() {
		int x = -1, y = 2;
		std::cout << "Show positive: " << std::showpos << x << " " << y
			<< "\tWithout show positive: " << std::noshowpos << x << " " << y << '\n';
	}

	// get whitespace
	void not_skip_whitespace() {
		char a, b, c;
		std::istringstream iss("  123");
		iss >> std::noskipws >> a >> b >> c;
		std::cout << "Not skip whitespace: " << a << b << c << '\n';

		iss.seekg(0);
		iss >> std::skipws >> a >> b >> c;
		std::cout << "Skip whitespace: " << a << b << c << '\n';
	}

	// Ques: when to use unitbuf ??
	void unitbuf() {
		std::ofstream file("test.txt");
		file <<std::unitbuf<< "Test" << "file" << '\n';
		file << std::nounitbuf << "Why" << "use" << '\n';
		file.close();
	}

	void show_uppercase() {
		int num = 15;
		std::cout << "Show Uppercase: " << std::hex << std::uppercase << num
			<<"\tNo show uppercase: " << std::nouppercase << num << std::dec << '\n';
	}
};

int main() {
	basic_ios ios;
	ios.set_boolalpha();
	ios.set_basefield();
	ios.set_floatfield();
	ios.set_fixed_float_point();
	ios.show_base();
	ios.show_decimal_point();
	ios.show_positive();
	ios.not_skip_whitespace();
	ios.unitbuf();
	ios.show_uppercase();


	return 0;
}