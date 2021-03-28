#include <ios>
#include <iosfwd>
#include <iostream>
#include <sstream>
#include <fstream>

// Warning: Make sure to set back to default setting after manipulator the output

class manipulator_ios {
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
		double pi = 3.14159;
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

class Basic_ios {
private:
	std::stringstream ss;
	std::ofstream file;
	// ss.clear() -- set new value for stream
	//
public:

	void copy_format() {
		std::ofstream file("test.txt");
		std::cout.fill('#');
		std::cout.width(5);
		file.copyfmt(std::cout);
		std::cout << 40 << std::endl;
		file << 40; // ###40
		file.close();
	}

	void exception() {
		std::ifstream file;
		try {
			file.open("test.txt");
			file.exceptions(std::ifstream::failbit);
			std::string str;
			file >> str;
			std::cout << "Get file without execption: " << str << std::endl;
		}
		catch (std::ifstream::failure e) {
			std::cerr << "Exception opening/reading file: " << e.what() << '\n';
		}
		file.close();
	}


	void print_state(const std::ios& ss) {
		
		std::cout << "\tgood(): " << ss.good()
			<< "\teof(): " << ss.eof()
			<< "\tfail(): " << ss.fail()
			<< "\tbad(): " << ss.bad() << std::endl;
	}

	void check_stream_state() {
		ss.clear(ss.goodbit);
		std::cout << "Good bit: ";
		print_state(ss);
		ss.clear(ss.eofbit);
		std::cout << "Error bit: ";
		print_state(ss);
		ss.clear(ss.failbit);
		std::cout << "Failed bit: ";
		print_state(ss);
		ss.clear(ss.badbit); 
		std::cout << "Bad bid: "; 
		print_state(ss); 
	}


};

int main() {
	Basic_ios basic;
	basic.copy_format();
	basic.exception();
	basic.check_stream_state();
	return 0;
}