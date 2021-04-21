#include <iostream>
#include <map>
#include <vector>

// Map are associative containers that store elememts formed by a combination of a key value and mapped value
// key values are use to sort and uniquely identify the elements
// mapped values are associate with key values, it can store different type
// map allow to direct access iteration ob subsets
// direct access key using operator[]

// Container
// You can map the pair with different type, at last it will follow with the map type
std::pair<int, int> pair_1(1,10);
std::pair<int, char> pair_2(11, 'h');
std::pair<char, int> pair_3('a', 99);
std::vector<double> vec_1{ 8.9,0.001,99.23,54,-1 };

// Construct map -- C++ 11
std::map<int, int> map_1; // default
std::map<int, int> map_2{ {2,10},{3,20} }; // initialize list
std::map<int, int> map_3({ pair_3}); // copy different type of pair 
std::map<char, int> map_4({ pair_3 }); // copy same type of pair
std::map<int, std::vector<double>> map_5{ { 1,vec_1} }; // copy vector

class MapMemberFunction {
public:

	// ### CREATE ###

	// ### READ   ###

	// try to seperate print container or print simple type
	
	template<typename Key,typename Mapped>
	void m_print(std::map<Key, Mapped> m_map) {
		for (auto it : m_map) {
			std::cout << it.first << ' ';
			for (auto v : it.second) {
				std::cout << v << ' ';
			}
			std::cout << std::endl;
		}
	}


	// ### UPDATE ###

	// ### DELETE ###
};


int main() {

	MapMemberFunction m;
	m.m_print(map_3);
	m.m_print(map_5);

}