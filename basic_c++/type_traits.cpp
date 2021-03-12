#include <type_traits>
#include <iostream>

// "trivially" is not include dtor, ctor, copy and assign value.
// "Nothrow" will return true if no except

// "noexcept" is something like "throw" expression

class Foo {
	int v1;
	double v2;
public:
	Foo(int n) : v1(n), v2() {}
	Foo(int n, double f) noexcept : v1(n), v2(f) {}
};

class Ex {
public:
	int n;
	Ex() = default; // default constructible
	Ex(int x) : n(x) {}
};

int main() {
	std::cout << "Foo is ... \n" << std::boolalpha

		// Check if a type has constructor for specific argument
		<< "Construtible from int? "
		<< std::is_constructible<Foo, int>::value << std::endl
		<< "Trivially constructible from const Foo&? "
		<< std::is_trivially_constructible<Foo, const Foo&>::value << std::endl
		<< "Trivially constructible from int? "
		<< std::is_trivially_constructible<Foo, int>::value << std::endl
		<< "Nothrow-constructible from int and double? "
		<< std::is_nothrow_constructible<Foo, int, double>::value << std::endl

		// Check whether have default constructor
		<< "Default constructible? "
		<< std::is_default_constructible<Ex>::value << std::endl
		<< "Trivially default constructible? "
		<< std::is_trivially_default_constructible<Ex>::value << std::endl
		<< "Nothrow-default constructible? "
		<< std::is_nothrow_default_constructible<Ex>::value << std::endl;


	return 0;
}