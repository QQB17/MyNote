#include <iostream>

struct basicRef {
	int x = 10;
	int& y = x;
	
	// reference y is only holding the x memory address
	void ref() { std::cout << "Reference of y: " << y << " " << &y << "\tx: " << x << " " << &x << std::endl; }

	// print reference value
	template <typename T>
	void print(T& a, T& b) {
		std::cout << "Value of One: " << a << " Value of Two: " << b << std::endl;
	}
	
	// Change the reference value
	void changeRefVal(int n) {
		this->y = n;
		std::cout << "After change reference value of y: " << y
			<< "\tx: " << x << std::endl;
	}

	// Swap value using reference
	void swap(int& a, int& b) {
		int c = a;
		a = b;
		b = c;
	}
	
};

struct rightLeftValue {
	void refValue(int& n) {
		std::cout << "lvalue overload, n = " << n << std::endl;
	}

	void refValue(int&& n) {
		std::cout << "rvalue overload, n = " << n << std::endl;
	}

};

int main() {
	int n = 1, m = 9;

	basicRef b;
	b.ref();
	b.changeRefVal(20);
	b.print(n, m);
	b.swap(n, m);
	std::cout << "Value was swap.\n";
	b.print(n, m);

	rightLeftValue v;
	v.refValue(n);
	v.refValue(8);

	return 0;
}