#include <iostream>

template <typename T>
void printPointer(T ptr) {
	std::cout << "Type: " << typeid(T).name() << std::endl;
	std::cout << "Pointer: " << *ptr << "\tAddress: " << &ptr << "\tVariable: " << ptr << "\n\n";
}

void basicPointer() {
	int x = 5;
	int* y = &x; //Pointer to address
	printPointer(y);
}

void squareByPtr(int* numPtr) {
	*numPtr *= *numPtr;
}

void constPointer() {
	int x = 5, y = 3;

	const int* ptr1 = &x;
	int* const ptr2 = &y;
	const int* const ptr3 = &x;
	printPointer(ptr1);
	printPointer(ptr2);
	printPointer(ptr3);
}

void pointArithemtic() {
	int arr[]{ 6,7,8,9 };
	int* ptr = arr;
	ptr++;
	int* ptr2 = (arr + 2);
	std::cout << "Pointer++: " << *ptr << "\tPointer 2(arr+2): " << *ptr2 << std::endl;
}

void doublePointer() {
	int a = 3;
	int* b  = &a;
	int** c = &b;
	
	printPointer(&c);
	printPointer(c);
	printPointer(*c);
}

int main() {
	int y = 6;
	int* x = &y;

	constPointer();

	return 0;	
}