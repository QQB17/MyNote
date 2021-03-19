#include <iostream>
#include <functional>

// std::ref  -- reference
// std::cref -- constant reference

template <typename T>
void change(T t) {
	std::cout << ++t << std::endl;
}


void simpleRef() {
	int x = 5;
	int& y = x;

	// Pass by value will not affect x
	change(y);
	std::cout << x << y << std::endl;

	// Pass by reference will affect x
	change<int&>(x);
	std::cout << x << y << std::endl;

	// Pass by refence using std::ref
	change(std::ref(x));
	std::cout << x << y << std::endl;
}

void f(int& n1, int& n2, const int& n3) {
	std::cout << "Inside function : " << n1++ << " " << n2++ << " " << n3 << std::endl;
}

void boundFunc() {
	int n1 = 1, n2 = 2, n3 = 3;
	std::function<void()> bound_f = std::bind(f, n1, std::ref(n2), std::cref(n3));
	n1 = 10, n2 = 11, n3 = 12;
	std::cout << "Before function: " << n1 << " " << n2 << " " << n3 << std::endl;
	bound_f();
	std::cout << "After function: " << n1 << " " << n2 << " " << n3 << std::endl;

}

int main() {
	boundFunc();

	return 0;
}