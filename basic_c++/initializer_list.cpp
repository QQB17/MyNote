#include <iostream>
#include <typeinfo>
#include <string>
#include <sstream>
#include <initializer_list>
#include <vector>

class basic_init_list {
private:
	std::string str;
public:

	void construct_init_list() {
		std::initializer_list<int> mylist;
		mylist = { 11,12,13,14,15 };
		for (int x : mylist) { std::cout << x << " "; }
		std::cout << std::endl;
	}

	void init_list_begin_end() {
		std::initializer_list<char> ch;
		ch = { 'h','e','l','l','o' };
		for (const auto* c = ch.begin(); c != ch.end();c++) { std::cout << *c << " "; }
		std::cout << "\nSize: " << ch.size() << std::endl;
	}

	std::string pointer_init_list(std::initializer_list<int> args) {
		std::stringstream ss;
		std::initializer_list<int>::iterator it;
		for (it = args.begin(); it != args.end();it++) {
			ss << *it;
		}
		str = ss.str();
		return str;
	}
};

int main() {
	basic_init_list init;
	init.construct_init_list();
	init.init_list_begin_end();
	const auto vec = init.pointer_init_list({1, 2, 3, 4, 5 });
	for (auto& v : vec) std::cout << v << " ";

	return 0;
}	