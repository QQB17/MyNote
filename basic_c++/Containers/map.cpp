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

	// Print map with simple type
	template<typename Key, typename Mapped>
	void m_print(const std::map<Key, Mapped>& m_map) {
		int x = 0, n = m_map.size();
		std::cout << "Map size: " << n << std::endl;
		for (auto it : m_map)
			std::cout << "[" << x++ << "]\t" <<  it.first << ' ' << it.second << '\n';
	}
	
	// Print vector in map
	// TODO: try to mix combine together --22/04/2021
	template<typename Key,typename T>
	void m_print(const std::map<Key,std::vector<T>>& m_map) {
		int x = 0, n = m_map.size();
		std::cout << "Map size with vector: " << n << std::endl;
		for (auto it : m_map) {
			std::cout << "[" << x++ << "]\t" << it.first << ' ';
			for (auto v : it.second) {
				std::cout << v << ' ';
			}
			std::cout << std::endl;
		}
	}

	// iterator
	template<typename Key, typename Mapped>
	void m_iterator(const std::map<Key, Mapped>& m_map) {
		std::cout << "Iterator map: \n";
		for (auto it = m_map.begin(); it != m_map.end(); it++) {
			std::cout << it->first << ' ' << it->second << '\n';
		}
	}

	// reverse iterator
	template<typename Key, typename Mapped>
	void m_reverse_iterator(const std::map<Key, Mapped>& m_map) {
		std::cout << "Reverse iterator map: \n";
		for (auto it = m_map.rbegin(); it != m_map.rend(); it++) {
			std::cout << it->first << ' ' << it->second << '\n';
		}
	}

	// Count key value appeare times
	template<typename Key, typename Mapped>
	void m_count(const std::map<Key, Mapped>& m_map, const Key& key_value) {
		std::cout << "Key: " <<  key_value << " appeared " << m_map.count(key_value) << " times in map\n";
		// you can select the range and find the appear key value
	}
	
	// return true if empty
	template<typename Key, typename Mapped>
	bool m_empty(const std::map<Key, Mapped>& m_map) {
		if (m_map.empty()) {
			std::cout << "Map is empty\n";
			return true;
		}
		else {
			std::cout << "Map is not empty\n";
			return false;
		}
	}

	// return match/next element with the range
	template<typename Key, typename Mapped>
	void m_equal_range(const std::map<Key, Mapped>& m_map, const Key& key_value) {
		auto ret = m_map.equal_range(key_value);

		std::cout << "Return the match/next element: "
			<< ret.first->first << " => " << ret.first->second << '\n';
		std::cout << "Return next element: "
			<< ret.second->first << " => " << ret.second->second << '\n';
	}


	// find element by key value and return iterator element
	template<typename Key, typename Mapped>
	void m_find(const std::map<Key, Mapped>& m_map, const Key& key_value) {
		auto it = m_map.find(key_value);
		if (it != m_map.end()) {
			std::cout << "Key is found: " << it->first << std::endl;
		}
		else {
			it--;
			std::cout << "Key not found return last key: " << it->first << std::endl;
		}
		
		// print content
		//std::cout << key_value << m_map.find(key_value)->second << '\n';
	}

	// comparison of key value
	template<typename Key, typename Mapped>
	void m_key_comp(const std::map<Key, Mapped>& m_map, const Key& key_value) {
		auto comp = m_map.key_comp();
		std::cout << "Compare map key value: \n";
		for (auto it : m_map) {
			if (comp(it.first, key_value)) {
				std::cout << it.first << " is less than " << key_value << '\n';
			}

			if (comp(key_value, it.first)) {
				std::cout << it.first << " is greater than " << key_value << '\n';
			}
		}
	}

	// Comparison of mapped value
	template<typename Key, typename Mapped>
	void m_mapped_comp(const std::map<Key, Mapped>& m_map, const Mapped& mapped_value) {
		auto comp = m_map.key_comp();
		std::cout << "Compare map mapped value: \n";
		for (auto it : m_map) {
			if (comp(it.second, mapped_value)) {
				std::cout << it.second << " is less than " << mapped_value << '\n';
			}

			if (comp(mapped_value, it.second)) {
				std::cout << it.second << " is greater than " << mapped_value << '\n';
			}
		}
	}

	// return lower bound
	template<typename Key, typename Mapped>
	void m_lower_bound(const std::map<Key, Mapped>& m_map, const Key& key_value) {
		auto itlow = m_map.lower_bound(key_value);
		std::cout << "Pointing lower bound element: "
			<< itlow->first << " => " << itlow->second << std::endl;
	}

	// return upper bound
	template<typename Key, typename Mapped>
	void m_upper_bound(const std::map<Key, Mapped>& m_map, const Key& key_value) {
		auto itup = m_map.upper_bound(key_value);
		// Pointing to the next element
		std::cout << "Pointing upper bound element: "
			<< itup->first << " => " << itup->second << std::endl;
	}



	// ### UPDATE ###

	// return a mapped value of the element is match with key
	template<typename Key, typename Mapped>
	void m_at(std::map<Key, Mapped>& m_map, const Key& key_value, const Mapped& mapped_value) {
		for (auto it : m_map) {
			if (it.first == key_value) {
				m_map.at(key_value) = mapped_value;
				std::cout << key_value << " is changed.\n";
				return;
			}
		}
		std::cout << key_value << " is out of range\n";
	}

	// construct and insert element
	template<typename Key, typename Mapped>
	void m_emplace(std::map<Key, Mapped>& m_map, const Key& key_value, const Mapped& mapped_value) {
		m_map.emplace(key_value, mapped_value);
	}

	// construct and insert element with hint the position
	template<typename Key, typename Mapped>
	void m_emplac_hint(std::map<Key, Mapped>& m_map,const Key& key_value, const Mapped& mapped_value) {
		m_map.emplace_hint(m_map.begin(),key_value, mapped_value);
	}
	
	// insert or copy element to map
	template<typename Key, typename Mapped>
	void m_insert(std::map<Key, Mapped>& m_map,const Key& key_value, const Mapped& mapped_value) {
		std::pair<Key, Mapped> pair_value{ key_value,mapped_value };
		// insert single elemet by pair
		m_map.insert(pair_value);
		
		// insert with hint position
		m_map.insert(m_map.begin(), pair_value);

		// insert other map with range
		std::map<Key, Mapped> other_map{ { -1,55 }, { -2,66 } };
		m_map.insert(other_map.begin(), other_map.end());
	}

	// access element using operator[]
	template<typename Key, typename Mapped>
	void m_operator_square_bracker(std::map<Key, Mapped>& m_map, const Key& key_value) {
		std::cout << "Access map with map[] : " << key_value << " => " << m_map[key_value] << std::endl;
	}

	// swap map
	template<typename Key, typename Mapped>
	void m_swap(std::map<Key, Mapped>& m_map1, std::map<Key, Mapped>& m_map2) {
		m_map1.swap(m_map2);
	}
	

	// ### DELETE ###

	// remove all element
	template<typename Key, typename Mapped>
	void m_clear(std::map<Key, Mapped>& m_map) {
		m_map.clear();
	}

	// remove element by key value or selected range
	template<typename Key, typename Mapped>
	void m_erase(std::map<Key, Mapped>& m_map, const Key& key_value) {
		m_map.erase(key_value);
		//m_map.erase(m_map.begin(),m_map.end());
	}
};


int main() {

	MapMemberFunction m;
	m.m_print(map_2);
	m.m_emplace(map_2, 4, 50);
	m.m_emplac_hint(map_2, 87, 747);
	m.m_at(map_2,3,200);
	m.m_iterator(map_2);
	m.m_count(map_2, 3);
	m.m_equal_range(map_2, 3);
	m.m_erase(map_2, 3);
	m.m_insert(map_2, 5, 11);
	m.m_find(map_2, 10);
	m.m_key_comp(map_2, 50);
	m.m_mapped_comp(map_2, 100);
	m.m_lower_bound(map_2, 5);
	m.m_upper_bound(map_2, 1);
	m.m_operator_square_bracker(map_2, 5);
	m.m_reverse_iterator(map_2);

	//m.m_print(map_5);

	return 0;
}

// References::
// 1. https://www.cplusplus.com/reference/map/map/