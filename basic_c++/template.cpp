#include <iostream>

// template is to pass data type as a parameter
// No need to write the same code with different type

// No much different between <typename T> and <class T>
// More prefer writing <typename T>

/* template <class T>
	- must be used when specifying a "template <template>"
	- when explicitly instantiating a template

	// exmaple 
	template <template <typename> class T> class C {}; // valid
	template <tempalte <typename> typename T> class C{}; // invalid

*/
template<typename T>
T findMax(T x, T y) {
	return (x > y) ? x : y;
}


//calss template
template<typename T>
class Arr {
private:
	T* ptr;
	int size;
public:
	Arr(T arr[], int s);
	void print();
};

template<typename T>
Arr<T>::Arr(T arr[], int s) {
	ptr = new T[s];
	size = s;
	for (int i = 0;i < size;i++) {
		ptr[i] = arr[i];
	}
}

template <typename T>
void Arr<T>::print() {
	for (int i = 0;i < size;i++) {
		std::cout << *(ptr + i) << " ";
	}
	std::cout << std::endl;
}


// call differenct type argument 
template <typename T, typename U>
class moreArg {
	T x;
	U y;
public:
	moreArg() { 
		std::cout << x  << " " << y << std::endl;
		std::cout << "Constructor called." << std::endl; 
	}
};

int main() {
	std::cout << findMax(10, 5) << std::endl; // int
	std::cout << findMax(3.33, 4.44) << std::endl; // double
	std::cout << findMax('w', 'a') << std::endl; // char

	int arr[] = { 1,2,3,4,5 };
	Arr<int> a(arr, 5);
	a.print();

	moreArg<int, double> c;
	moreArg<char, float> d;

	return 0;
}