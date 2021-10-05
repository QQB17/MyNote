/*
	Character handling function
*/

#include <iostream>
#include <ctype.h>

template<typename T>
class CTYPE {

public:
	// isalnum
	// check whether str is either a decimal digits or an uppercase or lowercase letter
	void isAlphanumeric(T str) {
		for (int i = 0;i < strlen(str);i++) {
			if (isalnum(str[i])) {
				std::cout << str[i] << " is alphanumeric.\n";
			}
			else {
				std::cout << str[i] << " is not alphanumeric.\n";
			}
		}
	}

	// isalpha
	// check whether str is an alphabetic letter
	void isAlphabetic(T str) {
		for (int i = 0;i < strlen(str);i++) {
			if (isalpha(str[i])) {
				std::cout << str[i] << " is alphabetic.\n";
			}
			else {
				std::cout << str[i] << " is not alphabetic.\n";
			}
		}
	}

	// isblank
	// check wther str is a blank character, can use to seperate the a line text
	void isBlank(T str) {
		for (int i = 0; i < strlen(str);i++) {
			if (isblank(str[i])) {
				std::cout << '\n';
				continue;
			}
			std::cout << str[i];
		}
		std::cout << '\n';
	}

	// iscntrl
	// check whether is control character
	// Referecens: https://en.wikipedia.org/wiki/Control_character
	void isControlCharacter(T str) {
		for (int i = 0; i < strlen(str);i++) {
			if (!iscntrl(str[i])) {
				std::cout << str[i];
			}
			else {
				std::cout << str[i] << " \"control character\" ";
			}
		}
		std::cout << '\n';
	}

	// isdigit
	// check whether is 0 - 9
	void isDigit(T str) {
		for (int i = 0; i < strlen(str);i++) {
			if (isdigit(str[i])) {
				std::cout << str[i] << " is digit.\n";
			}
			else {
				std::cout << str[i] << " is not a digit.\n";
			}
		}
	}

	// isgraph
	// check whether is character able to graphical
	// except the special character
	void isGraphicalRepresentation(T str) {
		if (validTypeName(str)) {
			if (isgraph(str)) {
				std::cout << str << " is graphical.\n";
			}
			else {
				std::cout << str << " is not graphical.\n";
			}
			return;
		}

	/*	for (int i = 0; i < strlen(str);i++) {
			if (isgraph(str[i])) {
				std::cout << str[i] << " is graphical.\n";
			}
			else {
				std::cout << str[i] << " is not graphical.\n";
			}
		}*/
	}

	void isLowerCase(T str) {
		for (int i = 0; i < strlen(str);i++) {
			if (islower(str[i])) {
				std::cout << str[i] << " is lowercase.\n";
			}
		}
	}

	void isUpperCase(T str) {
		for (int i = 0; i < strlen(str);i++) {
			if (isupper(str[i])) {
				std::cout << str[i] << " is uppercase.\n";
			}
		}
	}

	// isprint
	// check wheter able to printable
	void isPrintable(T str) {
		for (int i = 0; i < strlen(str);i++) {
			if (isprint(str[i])) {
				std::cout << str[i] << " is printable.\n";
			}
			else {
				std::cout << str[i] << " is printable.\n";
			}
		}
	}

	// ispunct
	// check whether have punctuation character
	void isPunctuation(T str) {
		for (int i = 0; i < strlen(str);i++) {
			if (ispunct(str[i])) {
				std::cout << str[i] << " is punctuation.\n";
			}
		}
	}

	// isspace
	// check whether have space character, ' ', '\t', '\n', '\v' , '\f', '\r'
	void isSpace(T str) {
		int count = 0;
		for (int i = 0; i < strlen(str);i++) {
			if (isspace(str[i])) {
				count++;
			}
		}
		std::cout << str << '\n';
		std::cout << "This text having " << count << " space.\n";
	}

	// check whether is hexadecimal digits
	void isXdigit(T str) {
		long int num = 0;
		if (isxdigit(str[0])) {
			num = strtol(str, NULL, 16);
			printf("The hexadecimal number %1x is %1d.\n", num, num);
		}
	}

};

int main() {
	CTYPE<const char*> ct;
	const char* str = "Hello123%^3 ", * str2 = "12\abc", * str3 = "*&^%$#~\\`";
	const char* str4 = "\t\n\v\f\r";
	//ct.isAlphanumeric(str);
	//ct.isAlphabetic("C++123sd");
	//ct.isBlank("Hello world");
	//ct.isControlCharacter(str2);
	//ct.isDigit(str2);
	//ct.isGraphicalRepresentation(str3);
	//ct.isLowerCase(str2);
	//ct.isPrintable(str2);
	//ct.getTypeName(str);
	//ct.validTypeName(str);
	//ct.isPunctuation(str3);
	//ct.isSpace(str);
	//ct.isUpperCase(str);
	ct.isXdigit("fff");
	return 0;
}