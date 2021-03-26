#include <sstream>
#include <iostream>
#include <vector>

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
T findMax(T x, T y) { return (x > y) ? x : y; }

//class template
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
	for (int i = 0;i < size;i++) 
		std::cout << *(ptr + i) << " ";

	std::cout << std::endl;
}

// call different type argument 
template <typename T, typename U>
class moreArg {
	T x;
	U y;
public:
	moreArg() { std::cout << "Call differenct type argument: " << x << " " << y << std::endl; }
};

//variadic template, output with sstream
template <typename... Args>
std::vector<std::string> convert_to_string(const Args&... args) {

	// lambda recursion
	const auto to_string_impl = [](const auto& p) {
		std::stringstream ss;
		ss << p;
		return ss.str();
	};

	return { to_string_impl(args)... };
}


template <typename... Args>
void get_vector(const Args&... args) {
	const auto& v = { convert_to_string(args)... }; // something wrong here 
	for (const auto x : v) std::cout << &x << std::endl;
	for (const auto* x = v.begin(); x != v.begin();x++) {
		std::cout << &x << std::endl;
	}
	std::cout << &v;
	std::cout << "vector";
}

int main() {
	std::cout << findMax(10, 5) << std::endl; // int
	std::cout << findMax(3.33, 4.44) << std::endl; // double
	std::cout << findMax('w', 'a') << std::endl; // char

	int arr[] = { 1,2,3,4,5 };
	Arr<int> a(arr, 5);
	a.print();

	const auto vec = convert_to_string("hello", 1, 23.44);
	for (auto& o : vec) {
		std::cout << o << std::endl;
	}

	get_vector(3.142, 50, "ok");

	return 0;
}