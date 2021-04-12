#include <iostream>
#include <array>

class Arrays {
private:
	// initialize array
	int arr1[5] = { 1,2,3,4,5 };
	int arr2[2][3] = { {1,2,3}, {4,5,6}};
	std::array<int, 4> arr3{42,25,77,101};

	// Size of array
	int arr_size = sizeof(arr1) / sizeof(*arr1);

public:
	void print_init_array() {
		std::cout << "Arr1 :";
		for (int i = 0;i < arr_size; i++)
			std::cout << arr1[i] << ' ';
		std::cout << std::endl;

		std::cout << "2D Array: \n";
		for (int i = 0;i < 2;i++) {
			std::cout << "Row [" << i + 1 << "] : ";
			for (int j = 0; j < 3;j++)
				std::cout << arr2[i][j] << " ";
			std::cout << '\n';
		}
	}

	void byte_and_address() {
		std::cout << "Byte of arr1: " << *arr1 << "\t\tAddress arr1: " << arr1 << '\n';

		std::cout << "Byte of 2D arr2: " << **arr2 << "\tAddress arr2: " << arr2 << '\n';
	}

	void array_member_function() {
		// for loop array
		std::cout << "Arr3 : ";
		for (auto it = arr3.begin(); it != arr3.end();it++) {
			std::cout << *it << ' ';
		}
		std::cout << std::endl; 

		std::cout << "Reverse Arr3: ";
		for (auto rit = arr3.rbegin(); rit != arr3.rend(); rit++) {
			std::cout << *rit << ' ';
		}
		std::cout << std::endl;

		// Return element with position
		std::cout << "Arr3[3]: " << arr3.at(3) << '\n';

		// Return first and last element
		std::cout << "Arr3 front: " << arr3.front() << '\n';
		std::cout << "Arr3 back: " << arr3.back() << '\n';

		std::cout << "Arr3 is empty? " << std::boolalpha << arr3.empty() << std::noboolalpha << '\n';

		arr3.fill(2);
		std::cout << "Fill arr3 with 2: ";
		for (int a : arr3) std::cout << a << ' ';
	}

	void assign_value() {
		int x = 10;
		for (int i = 0;i < arr_size;i++) 
			arr1[i] = x++;
	}
};

int main() {
	Arrays a;
	a.byte_and_address();
}