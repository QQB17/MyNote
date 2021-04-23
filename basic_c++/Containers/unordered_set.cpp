#include <iostream>
#include <unordered_set>

// Unordered set are container the store unique element in no particular order
// Fast access to individual element by the value

int arr[5] = { 9,7,5,3,1 };

// Construct unordered_set -- C++ 11
std::unordered_set<int> unset_1; // default
std::unordered_set<int> unset_2{ 1,2,3,4,3,2,1 }; // initialize list
std::unordered_set<int> unset_3(arr, arr + 5); // array range
std::unordered_set<int> unset_4(unset_2); // copy
std::unordered_set<int> unset_5(100); // bucket size

class UnorderedSetMemberFunction {
public:

	// ### CREATE ###

	// ### READ   ###

	template <typename T>
	void unset_print(const std::unordered_set<T>& m_unset) {
		int x = 0, n = m_unset.size();
		std::cout << "Unordered set size: " << n << std::endl;
		for (auto it : m_unset) {
			std::cout << "[" << x++ << "]\t" <<  it << '\n';
		}
	}

	// iterator
	template <typename T>
	void unset_iterator(const std::unordered_set<T>& m_unset) {
		int x = 0, n = m_unset.size();
		std::cout << "Iterator unordered set size: " << n << std::endl;
		for (auto it = m_unset.begin(); it != m_unset.end();it++) {
			std::cout << "[" << x++ << "]\t" << *it << '\n';
		}
	}

	template <typename T>
	void unset_size(const std::unordered_set<T>& m_unset) {
		std::cout << "Size: " << m_unset.size() << std::endl;
	}

	template <typename T>
	void unset_max_size(const std::unordered_set<T>& m_unset) {
		std::cout << "Max size: " << m_unset.max_size() << std::endl;
	}

	// locate element bucket
	template <typename T>
	void unset_bucket(const std::unordered_set<T>& m_unset) {
		for (auto it : m_unset) 
			std::cout << it << " => " << m_unset.bucket(it) << '\n';
	}

	// bucket count
	template <typename T>
	void unset_bucket_count(const std::unordered_set<T>& m_unset) {
		std::cout << "Unordered set have : " << m_unset.bucket_count() << " buckets.\n";
	}

	template <typename T>
	void unset_max_bucket_count(const std::unordered_set<T>& m_unset) {
		std::cout << "Max bucket size: " << m_unset.max_bucket_count() << std::endl;
	}

	// return bucket size
	template <typename T>
	void unset_bucket_size(const std::unordered_set<T>& m_unset) {
		unsigned nbuckets = m_unset.bucket_count();
		for (unsigned i = 0;i < nbuckets;i++) {
			std::cout << "bucket # " << i  << " has " << m_unset.bucket_size(i) << " elements\n";
		}
	}

	// count element with a specific key
	template <typename T>
	void unset_count(const std::unordered_set<T>& m_unset, const std::initializer_list<T>& list) {
		for (auto it : list) 
			std::cout << it << (m_unset.count(it) > 0 ? " is found" : " not found") << std::endl;
	}

	// load_factor = size /bucket count
	template <typename T>
	void unset_load_factor(const std::unordered_set<T>& m_unset) {
		std::cout << "Load factor: "  << m_unset.load_factor() << std::endl;
	}

	// get iterator to element
	template <typename T>
	void unset_find(const std::unordered_set<T>& m_unset, const T& value) {
		auto m_find = m_unset.find(value);
		if (m_find != m_unset.end())
			std::cout << *m_find;
	}

	template <typename T>
	void unset_empty(const std::unordered_set<T>& m_unset) {
		std::cout << "Unordered set is " << (m_unset.empty() ? " empty" : "not empty") << std::endl;
	}

	// return match/next element 
	template <typename T>
	void unset_equal_range(const std::unordered_set<T>& m_unset, const T& value) {
		if (m_unset.count(value) > 0) {
			auto range = m_unset.equal_range(value);
			std::cout << "Equal range is match/next element: " << *(range.first) << '\n';
			if (range.second == m_unset.end()) {
				std::cout << "Return last element: " << *(--range.second) << std::endl;
			}
			else {
				std::cout << "Next element:  " << *(range.second) << std::endl;
			}
		}
		else {
			std::cout << "No equal range is match\n";
		}
	}

	// return a unique value of	type size_t(unsigned int(32bit),unsigned long long(64bit))
	template <typename T>
	void unset_hash_function(std::unordered_set<T>& m_unset, const T& value) {
		std::hash<T> m_hash = m_unset.hash_function();
		std::cout << value << " after hash function " << m_hash(value) << std::endl;
	}
	
	// return true if case is insensitive
	void unset_key_eq() {
		std::unordered_set<std::string> str1;
		bool it = str1.key_eq()("hello","hello");
		if (it) {
			std::cout << "Case insensitive\n";
		}
		else {
			std::cout << "Case sensitive\n";
		}
	}


	// ### UPDATE ###

	// construct and insert element
	template <typename T>
	void unset_emplace(std::unordered_set<T>& m_unset, const T& value) {
		m_unset.emplace(value);
	}
	
	// insert element
	template <typename T>
	void unset_insert(std::unordered_set<T>& m_unset, const T& value) {
		m_unset.insert(value);
	}

	// return maximun number
	template <typename T>
	void unset_max_load_factor(std::unordered_set<T> m_unset) {
		float f = m_unset.max_load_factor();
		std::cout << "Max load factor: " << f << std::endl;
		unset_size(m_unset);
		unset_bucket_count(m_unset);
		unset_load_factor(m_unset);
		std::cout << std::endl;
		 
		m_unset.max_load_factor(f / 10.0); // halved
		std::cout << "Max load factor: " << m_unset.max_load_factor() << std::endl;
		unset_size(m_unset);
		unset_bucket_count(m_unset);
		unset_load_factor(m_unset);
	}
	
	// set the number of buckets
	template <typename T>
	void unset_rehash(std::unordered_set<T>& m_unset, const T& number) {
		if (number < m_unset.bucket_count()) {
			std::cout << "Rehash is no effect.\n";
			return;
		}
		m_unset.rehash(number);
		std::cout << "New bucket size: " << m_unset.bucket_count() << std::endl;
	}

	// set the number of buckets
	template <typename T>
	void unset_reserve(std::unordered_set<T>& m_unset, const T& number) {
		if (number < m_unset.bucket_count()) {
			std::cout << "Reserver is no effect.\n";
			return;
		}
		m_unset.reserve(number);
		std::cout << "New bucket size: " << m_unset.bucket_count() << std::endl;
	}


	template <typename T>
	void unset_swap(std::unordered_set<T>& m_unset1, std::unordered_set<T>& m_unset2) {
		m_unset1.swap(m_unset2);
	}


	// ### DELETE ###


	// remove all element
	template <typename T>
	void unset_clear(std::unordered_set<T>& m_unset) {
		m_unset.clear();
	}

	// remove elementtemplate <typename T>
	template <typename T>
	void unset_erase(std::unordered_set<T>& m_unset, const T& value) {
		m_unset.erase(value);
	}
};


int main() {
	UnorderedSetMemberFunction un;
	un.unset_print(unset_3);
	un.unset_emplace(unset_3, 99);
	un.unset_insert(unset_3, 8);
	un.unset_bucket(unset_3);
	un.unset_bucket_count(unset_3);
	un.unset_bucket_size(unset_3);
	un.unset_load_factor(unset_3);
	un.unset_erase(unset_3, 9);
	un.unset_count(unset_3,{ 1,2,3 });
	un.unset_empty(unset_3);
	un.unset_equal_range(unset_3, 11);
	un.unset_find(unset_3, 1);
	un.unset_iterator(unset_3);

	un.unset_hash_function(unset_3, 10);
	un.unset_key_eq();
	//un.unset_max_load_factor(unset_3);
	un.unset_max_bucket_count(unset_3);
	un.unset_max_size(unset_3);
	un.unset_rehash(unset_3,1);
	un.unset_reserve(unset_3, 1);
	un.unset_swap(unset_3, unset_2);
	un.unset_print(unset_3);

	return 0;
}

// Reference
// 1. https://www.cplusplus.com/reference/unordered_set/unordered_set/