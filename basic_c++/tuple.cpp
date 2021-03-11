#include <iostream>
#include <tuple>

// g++ tuple.cpp -o tuple -std=c++1z

template <typename T>
int sizeTuple(T tup) {
	return std::tuple_size<decltype(tup)>::value;
}


// only work for C++ 17 
template <typename T,std::size_t... I>
void printTuple(const T& tup, std::index_sequence<I...>) {
	(..., (std::cout << (I == 0 ? "" : " ") << std::get<I>(tup)));
	std::cout << std::endl;
}

template <typename... T>
void printTuple(const std::tuple<T...>& tup) {
	printTuple(tup, std::make_index_sequence<sizeof...(T)>());

}

template <typename T>
void makeTuple(T tup) {
	// Initialize value
	tup = std::make_tuple(5, 'h', 3.142);

	std::cout << "The initial value of tuples: "
		<< std::get<0>(tup) << " " << std::get<1>(tup) << " " << std::get<2>(tup) << std::endl;

	// Modify tuple index 0
	std::get<0>(tup) = 99;
	std::cout << "Tuple after modify: " << std::get<0>(tup) << std::endl;
}

// tuple for swap must be same type 
template <typename T>
void swapTuple(T tup1, T tup2) {
	std::cout << "Value of tuple 1: ";
	std::cout << std::get<0>(tup1) << " " << std::get<1>(tup1) << " " << std::get<2>(tup1) << std::endl;
	std::cout << "Value of tuple 2: ";
	std::cout << std::get<0>(tup2) << " " << std::get<1>(tup2) << " " << std::get<2>(tup2) << std::endl;

	tup1.swap(tup2);

	std::cout << "After swap Value of tuple 1: ";
	std::cout <<  std::get<0>(tup1) << " " << std::get<1>(tup1) << " " << std::get<2>(tup1) << std::endl;
	std::cout << "After swap Value of tuple 2: ";
	std::cout << std::get<0>(tup2) << " " << std::get<1>(tup2) << " " << std::get<2>(tup2) << std::endl;

}


// Getting tuple value into seperate variable
template <typename T>
void tieTuple(T tup) {
	int i;
	char c;
	double d;

	//tie all value from tuple
	std::tie(i, c, d) = tup;
	std::cout << "Tie from tuple: " << i << " " << c << " " << d << std::endl;
}

template <typename T>
auto concatenateTuple(T tup1, T tup2) {
	auto tup3 = std::tuple_cat(tup1, tup2);
	std::cout << "Concatenate two tuple: ";
	printTuple(tup3);
	
	return tup3;
}

int main() {
	std::tuple <int, char, double> tup1;
	std::tuple<int, char, double> tup2(9, 'w', 2.111);
	std::tuple<int, char, double> tup3(7, 'o', 3.142);

	std::cout << sizeTuple(tup2) << std::endl;
	printTuple(tup2);
	swapTuple(tup2, tup3);
	tieTuple(tup3);
	concatenateTuple(tup2, tup3);

	return 0;
}