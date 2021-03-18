#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>

// Syntax
// [ captures ] ( params ) mutable constexpr exception attribute -> ret { body }
// Short syntax
// [ captures ] ( params) -> ret { body }
// [ captures ] ( params) { body }
// [ captures ] { body }

class BasicLambda {
private:
	int c = 9;

public:
	
	void basic() {
		//define basic lambda
		auto basicLambda = [] {std::cout << "hello world!\n";};
		basicLambda();
	}

	void returnType() {
		// pointer return type "->"
		auto add = [](int a, int b) ->int {return a + b;};
		// without pointer return type, lambda will auto create
		auto mutiply = [](int a, int b) {return a * b;};
		std::cout << "Add with pointer return type: " << add(1, 2) << std::endl;
		std::cout << "Mutiply without pointer return type: " << mutiply(3, 7) << std::endl;
	}

	void captures() {
		std::cout << "Captures:\n";
		int x = 10, y = 20;

		// Capture external variable "x" by value, within this scope
		auto minus = [x](int a) -> int {return a - x;};
		std::cout << "Minus with capture external value: " << minus(15) << std::endl;

		// Capture external varialbe "x" by reference, within this scope
		auto divide = [&x](int a) {return a / x;};
		std::cout << "Divide with capture external reference: " << divide(20) << std::endl;

		// Capture all external variable by value
		auto sum = [=](int a) {return a + c + y;};
		std::cout << "Sum with capture all external value: " << sum(50) << std::endl;

		// Capture all external variable by reference
		auto rectangle = [&](int a) {return a * c * y;};
		std::cout << "Rectangle area with capture all external reference: " << rectangle(5) << std::endl;

		// Capture pointer object by reference
		auto referencePointerObject = [this]() {return this->basic();};
		referencePointerObject();
	}

	// Using STL std::sort
	void sortNumber() {
		std::vector<int> v{ 3,5,6,1,2 };

		std::sort(v.begin(), v.end());
		for (auto& vec : v)
			std::cout << vec << " ";
		std::cout << std::endl;
	}

	// Using STL std::generate
	void fibonacci(int n) {
		std::vector<int> v(n);
		int a = 0, b = 1;

		std::generate(v.begin(), v.end(), [&a, &b]() {int res = b; b = b + a; a = res; return res;});
		std::cout << "Fibonacci: ";
		for (auto& vec : v)
			std::cout << vec << " ";
		std::cout << "\tNumber: " << n <<  std::endl;
	}

	void genericLambda() {
		std::cout << "Generic Lambda:\n";
		int x = 4;
		// using capture scope [] to alter the variable
		auto y = [&r = x, x = x + 1]{ r += 2;return x * x; };
		// Alter "&r" inside the function and change the object "x" value after the function finish
		std::cout << "x: " << x << " " << "Square x: " << y() << std::endl;

		auto z = [str = "string"]{ return str; };
		std::cout << z() << std::endl;

		// unique_ptr is unable to copy value, we can use std::move the object to capture the value
		auto myPi = std::make_unique<double>(3.142);
		auto circle_area = [pi = std::move(myPi)](double r) { return *pi * r * r;};
		std::cout << circle_area(2.5) << std::endl;
	}

	void binder() {
		std::cout << "Binder: \n";
		// bind a object to a function with receive the parameter
		auto minus10 = std::bind(std::minus<int>{}, std::placeholders::_1, 10);
		std::cout << minus10(20) << std::endl;

		// Nested bind
		auto minus5divide2 = std::bind(std::divides<int> {},
			std::bind(std::minus<int>{}, std::placeholders::_1,5),2);
		std::cout << minus5divide2(55) << std::endl;

	}

};

// Function object 
class IntSequence {
public:
	IntSequence(int initVal) : value(initVal) {}

	int operator()() { return ++value; }

private:
	int value;
};

class CppLambda 
{
public:

	void operatorLambda() {
		// operator() (params)
		// since C++14
		// generic lambda, operator() is a template with one parameter
		auto vglambda = [](auto printer) {
			return [=](auto&&... ts) { // generic lambda, ts is parameter pack
				printer(std::forward<decltype(ts)>(ts)...);
				return [=] { printer(ts...);};
			};
		};

		// call vglambda and put parameter package by create a new lambda
		auto p = vglambda([](auto v1, auto v2, auto v3) { std::cout << v1 << v2 << v3 << std::endl; });
		// now, p is a function
		auto q = p('h',1,33.33);
		q();

	}

};

int main() {
	BasicLambda l;
	l.captures();
	l.fibonacci(10);
	l.sortNumber();
	l.genericLambda();
	l.binder();

	CppLambda c;
	c.operatorLambda();

	std::vector<int> v(10);
	std::generate(v.begin(), v.end(), IntSequence{ 0 });
	std::for_each(v.begin(), v.end(), [](int x) {std::cout << x << " ";});

}

// References :
// 1. https://www.jianshu.com/p/d686ad9de817
// 2. https://en.cppreference.com/w/cpp/language/lambda