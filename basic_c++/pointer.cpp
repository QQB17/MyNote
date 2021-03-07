#include <iostream>

void squareByPtr(int* numPtr) {
	*numPtr *= *numPtr;
}

void constPointer() {
	int x = 5, y = 3;

	const int* ptr1 = &x;
	int* const ptr2 = &y;
	const int* const ptr3 = &x;
	std::cout << *ptr1 << *ptr2 << *ptr3 << std::endl;
}

void pointArithemtic() {
	int arr[]{ 6,7,8,9 };
	int* ptr = arr;
	ptr++;
	int* ptr2 = (arr + 2);
	std::cout << "ptr++: " << *ptr << " ptr2(arr+2): " <<  *ptr2 << std::endl;
}

int main() {
	int y = 6;
	int* x = &y;

	std::cout << "x: " << x << " *x: " << *x << " &x: " << &x << std::endl;
	squareByPtr(x);
	std::cout << "x: " << x << " *x: " << *x << " &x: " << &x << std::endl;
	constPointer();
	pointArithemtic();

	return 0;	
}