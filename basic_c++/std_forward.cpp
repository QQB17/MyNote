#include <utility>
#include <iostream>

struct ref {
	// rvalue
	// for r-value reference parameter with non-template use "std::move"
	// for r-value reference parameter with template use "std::forward"
	// so, we need to create two function for each type
	void A(int&& n) {
		std::cout << "rvalue overload, n=" << n << std::endl;
	}

	// lvalue
	// for l-value reference parameter no need to use "std::move" or "std::forward" to copy parameter, 
	// just copy the object 
	void A(int& n) {
		std::cout << "lvalue overload, n=" << n << std::endl;
	}

};

template <typename T>
void rValueWithTemplate(T&& x) {
	T rValue = std::forward<T>(x);
	std::cout << "rvalue with template: " << rValue << std::endl;
}


// TODO -- Catch all parameter -- 14/03/2021
// Only can get last args value.
template <typename... Args> 
void rValueWithTemplate(Args&&... args) {
	auto rValue = (std::forward<Args>(args), ...);
	std::cout << "rvalue with template: " << rValue << std::endl;
}

void rValueWithoutTemplate(int&& x) {
	int rValue = std::move(x);
	std::cout << "rvalue without template: " << rValue << std::endl;
}

int main() {
	int a = 1;
	ref r;
	r.A(5);
	r.A(a);
	rValueWithoutTemplate(8);
	rValueWithTemplate(9);
	rValueWithTemplate(9,3,4,5);
}