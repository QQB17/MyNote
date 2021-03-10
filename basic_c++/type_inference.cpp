#include <iostream>
#include <typeinfo>
#include <vector>

// auto keyword can automatic declare the variable type
// decltype keword is an operator to extract the variable type

int func1() { return 10; }
char func2() { return 'h'; }

template <class A, class B>
auto findMin(A a, B b)-> decltype(a < b ? a : b) {
	return (a < b) ? a : b;
}


int main() {
	auto x = 10;
	auto c = 'h';
	auto d = 5.55;

	std::cout << typeid(x).name() << std::endl // int
		<< typeid(c).name() << std::endl // char
		<< typeid(d).name() << std::endl; // double

	std::vector<std::string> str{ "Hello","world","!" };

	// automatic set type to iterator the vector
	for (auto it = str.begin();it != str.end();it++) {
		std::cout << *it << " ";
	}

	decltype(func1()) a; // assign function type to a
	decltype(func2()) b; // assign function type to b

	std::cout << typeid(a).name() << std::endl
		<< typeid(b).name() << std::endl;

	int z = 5;
	decltype(z) j = z + 5;
	std::cout << typeid(j).name() << " " << j << " " << z << std::endl;

	std::cout << findMin(2.22, 3) << std::endl; // decltype will return double
	std::cout << findMin(6, 8.8) << std::endl; // decltype will return int

}