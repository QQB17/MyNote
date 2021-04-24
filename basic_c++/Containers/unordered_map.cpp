#include <iostream>
#include <unordered_map>

// Unordered map are to store key value and mapped value with associative
// key value is generally unique and can direct access the mapped value using operator[]

// Construct unordered_map -- C++ 11
std::unordered_map<int, int> unmap_1; // default
std::unordered_map<int, int> unmap_2{ {1,11}, {3,33},{5,55},{2,22} }; // initialize list
std::unordered_map<int, int> unmap_3(unmap_2); // copy
std::unordered_map<int, int> unmap_4(std::move(unmap_3)); // move
std::unordered_map<int, int> unmap_5(unmap_4.begin(), unmap_4.end()); // iterator range
std::unordered_map<std::string, std::string> unmap_6{ {"hello","world"}, {"HELLO","WORLD"} };


class UnorderedMapMemberFunction {
public:

	// ### CREATE ###


	// ### READ   ###

	template <typename Key, typename Mapped>
	void unmap_print(const std::unordered_map<Key, Mapped>& m_unmap) {
		int x = 0, m_size = m_unmap.size();
		std::cout << "Unordered map: " << m_size << std::endl;
		for (auto& it : m_unmap) {
			std::cout << "[" << x++ << "]\t" << it.first << " => " << it.second << '\n';
		}
	}

	// iterator 
	template <typename Key, typename Mapped>
	void unmap_iterator(const std::unordered_map<Key, Mapped>& m_unmap) {
		int x = 0, m_size = m_unmap.size(), size_bucket = m_unmap.bucket_count();
		std::cout << "Iterator unordered map: " << m_size << std::endl;
		for (auto it = m_unmap.begin(); it != m_unmap.end();it++) {
			std::cout << "[" << x++ << "]\t" << it->first << " => " << it->second << '\n';
		}

		for (int i = 0;i < size_bucket;i++) {
			std::cout << "Bucket #" << i << " contains ";
			for (auto it = m_unmap.begin(i); it != m_unmap.end(i);it++) {
				std::cout << "[" << it->first << " => " <<  it->second << "] ";
			}
			std::cout << std::endl;
		}
	}

	// size
	template <typename Key, typename Mapped>
	void unmap_size(const std::unordered_map<Key, Mapped>& m_unmap) {
		std::cout << "Unordered map size: " << m_unmap.size() << std::endl;
	}

	// max size
	template <typename Key, typename Mapped>
	void unmap_max_size(const std::unordered_map<Key, Mapped>& m_unmap) {
		std::cout << "Unordered map max size: " << m_unmap.max_size() << std::endl;
	}

	// locate element bucket
	template <typename Key, typename Mapped>
	void unmap_bucket(const std::unordered_map<Key, Mapped>& m_unmap) {
		for (auto& it : m_unmap) {
			std::cout << it.first << " => " << it.second << " in bucket #" << m_unmap.bucket(it.first) << std::endl;
		}
	}

	// return bucket contains numbers of element
	template <typename Key, typename Mapped>
	void unmap_bucket_size(const std::unordered_map<Key, Mapped>& m_unmap) {
		int n = m_unmap.bucket_count();
		for (int i = 0;i < n; i++) {
			std::cout << "Bucket #" << i << " has " << m_unmap.bucket_size(i) << " elements\n";
		}
	}

	// return bucket size
	template <typename Key, typename Mapped>
	void unmap_bucket_count(const std::unordered_map<Key, Mapped>& m_unmap) {
		std::cout << "Unordered map bucket count: " << m_unmap.bucket_count() << std::endl;
	}

	// return max bucket count
	template <typename Key, typename Mapped>
	void unmap_max_bucket_count(const std::unordered_map<Key, Mapped>& m_unmap) {
		std::cout << "Unordered map max bucket count: " << m_unmap.max_bucket_count() << std::endl;
	}


	// count element with specific key
	template <typename Key, typename Mapped>
	void unmap_count(const std::unordered_map<Key, Mapped>& m_unmap, const Key& m_key) {
		std::cout << "Key: " << m_key << (m_unmap.count(m_key) > 0 ? " is" : " is not") << " found in the map\n";
	}

	// load factor will effect the collision in the hash table
	// container will automatic increate bucket to maintain below "max load factor"
	// load factor = size / bucket_count
	template <typename Key, typename Mapped>
	void unmap_load_factor(const std::unordered_map<Key, Mapped>& m_unmap) {
		std::cout << "Unordered map load factor: " << m_unmap.load_factor() << std::endl;
	}

	// return match/next element
	template <typename Key, typename Mapped>
	void unmap_equal_range(const std::unordered_map<Key, Mapped>& m_unmap, const Key& m_key) {
		if (m_unmap.count(m_key) > 0) {
			auto range = m_unmap.equal_range(m_key);
			std::cout << "Match element: " << range.first->first << " => " << range.first->second << '\n';

			if (range.second == m_unmap.end()) {
				--range.second;
				std::cout << "Return last element: " << range.second->first<< " => " << range.second->second << '\n';
			}
			else {
				std::cout << "Next element: " << range.second->first << " => " << range.second->second << '\n';
			}
		}
		else {
			std::cout << "No equal range is match\n";
		}
	}

	// return iterator element if found
	template <typename Key, typename Mapped>
	void unmap_find(const std::unordered_map<Key, Mapped>& m_unmap, const Key& m_key) {
		if (m_unmap.count(m_key) > 0) {
			std::cout << "Find " << m_key << " => " << m_unmap.find(m_key)->second << std::endl;
		}
		else {
			std::cout << "Key not found\n";
		}
	}

	// get hash function
	template <typename Key, typename Mapped>
	void unmap_hash_function(const std::unordered_map<Key, Mapped>& m_unmap, const Key& m_key) {
		std::hash<Key> hf = m_unmap.hash_function();
		std::cout << "Using current hash function to hash a value: " << m_key << " => " << hf(m_key) << std::endl;
	}

	// return true if key value is insensitive
	template <typename Key, typename Mapped>
	void unmap_key_eq(const std::unordered_map<Key, Mapped>& m_unmap1) {
		auto m = m_unmap1.begin(), n = --(m_unmap1.end());
		bool test = m_unmap1.key_eq()(m->first,n->first);
		std::cout << "[" <<  m->first << "] key equivalance [" << n->first << "] is Case "
			<< (test ? "Insensitive" : "sensitive") << std::endl;
	}



	// ### UPDATE ###

	// access element and oeprate value
	template <typename Key, typename Mapped>
	void unmap_at(std::unordered_map<Key, Mapped>& m_unmap,const Key& m_key) {
		std::cout << "Access with key value: " << m_key << " => " << m_unmap.at(m_key) << std::endl;
		std::cout << "Change mapped value: " << (m_unmap.at(m_key) = 100000) << std::endl;
	}

	// construct and insert element
	template <typename Key, typename Mapped>
	void unmap_emplace(std::unordered_map<Key, Mapped>& m_unmap, const Key& m_key, const Mapped& m_mapped) {
		if (m_unmap.find(m_key) == m_unmap.end()) {
			m_unmap.emplace(m_key, m_mapped);
			std::cout << "Emplace success\n";
		}
		else {
			std::cout << "Error: Emplace failed... Key: " << m_key << " already have\n";
		}	
	}

	// insert element
	template <typename Key, typename Mapped>
	void unmap_insert(std::unordered_map<Key, Mapped>& m_unmap, const Key& m_key, const Mapped& m_mapped) {
		std::unordered_map<Key, Mapped> m_map{ {-1,-11},{-2,-22} };
		std::pair<Key, Mapped> m_pair(m_key, m_mapped);
		m_unmap.insert({ m_key, m_mapped }); // initialize list
		m_unmap.insert(m_map.begin(), m_map.end()); // range
		m_unmap.insert(m_pair); // copy
	}

	// get/set max load factor
	template <typename Key, typename Mapped>
	void unmap_max_load_factor(std::unordered_map<Key, Mapped>& m_unmap) {
		float x = m_unmap.max_load_factor();
		std::cout << "Unordered map max load factor: " << x << std::endl;
		m_unmap.max_load_factor(x * 2.0);
		std::cout << "New max load factor: " << m_unmap.max_load_factor() << std::endl;
	}
	
	// Set numbers of bucket
	template <typename Key, typename Mapped>
	void unmap_rehash(std::unordered_map<Key, Mapped>& m_unmap) {
		int n = m_unmap.bucket_count();
		m_unmap.rehash(n * 10);
		std::cout << "Rehash bucket: " << m_unmap.bucket_count() << std::endl;
	}

	// request a capacity change
	template <typename Key, typename Mapped>
	void unmap_reserve(std::unordered_map<Key, Mapped>& m_unmap) {
		int n = m_unmap.bucket_count();
		m_unmap.reserve(n *10);
		std::cout << "Reserve bucket: " << m_unmap.bucket_count() << std::endl;
	}

	// ### DELETE ###
	
	// remove all element
	template <typename Key, typename Mapped>
	void unmap_clear(std::unordered_map<Key, Mapped>& m_unmap) {
		m_unmap.clear();
	}

	// remove element by iterator, key, range
	template <typename Key, typename Mapped>
	void unmap_erase(std::unordered_map<Key, Mapped>& m_unmap) {
		m_unmap.erase(m_unmap.begin()); // iterator
		m_unmap.erase(5); // key
		m_unmap.erase(m_unmap.find(2), m_unmap.end()); // range
	}

};

int main() {
	UnorderedMapMemberFunction um;
	um.unmap_print(unmap_2);
	um.unmap_at(unmap_2,1);
	um.unmap_emplace(unmap_2, 2,35);
	um.unmap_max_size(unmap_2);
	um.unmap_size(unmap_2);
	um.unmap_bucket(unmap_2);
	um.unmap_bucket_size(unmap_2);
	um.unmap_bucket_count(unmap_2);
	um.unmap_max_bucket_count(unmap_2);
	um.unmap_count(unmap_2, 1);
	um.unmap_load_factor(unmap_2);
	um.unmap_max_load_factor(unmap_2);
	um.unmap_rehash(unmap_2);
	um.unmap_reserve(unmap_2);
	um.unmap_equal_range(unmap_2, 2);
	um.unmap_find(unmap_2, 2);
	um.unmap_hash_function(unmap_2, 99);
	um.unmap_insert(unmap_2, 11, 25);
	um.unmap_key_eq(unmap_6);
	
	return 0;
} 