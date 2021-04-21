#include <iostream>
#include <set>
#include <vector>

// sets are containers the store unique elements following a specific order
// The value of element inside the container can't be modified but can insert or remove

// Construct container
int arr[5] = { 1,2,3,4,5 };
std::vector<int> vec_1{ 8,76,11,100,2 };

// Construct set -- C++ 11
std::set<int> set_1; // default
std::set<int> set_2{ 4,5,2,1 }; // intialize list
std::set<int> set_3(arr, arr+5); // array range 
std::set<int> set_4(set_3); // copy set
std::set<int> set_5(set_4.begin(), set_4.end()); // iterator set
std::set<int, std::less<int>> set_6(vec_1.begin(),vec_1.end()); // set comparasion and insert vector
std::set<int> set_7(std::move(set_5)); // move set_5

class SetMemberFunction {
public:

	// ### CREATE ###

	template <typename T, typename Pr, typename Alloc>
	void s_get_allocator(std::set<T, Pr, Alloc>& m_set) {
		int* p;
		p = m_set.get_allocator().allocate(10);
		for (int i = 0;i < 10;i++) 
			p[i] = i * 10;

		for (int i = 0;i < 10;i++) 
			std::cout << p[i] << ' ';
		std::cout << std::endl;
		m_set.get_allocator().deallocate(p, 10);
	}


	// ### READ   ###

	template <typename T, typename Pr, typename Alloc>
	void s_print(std::set<T,Pr, Alloc>& m_set) {
		int x = 0, n = m_set.size();
		std::cout << "Set size: " << n << std::endl;
		for (auto& it : m_set) {
			std::cout << "[" << x++ << "]\t" << it << '\n';
		}
	}

	template <typename T, typename Pr>
	void s_iterator(std::set<T,Pr>& m_set) {
		std::cout << "Iterator: ";
		for (auto it = m_set.begin();it != m_set.end();it++) {
			std::cout << *it << ' ';
		}
		std::cout << std::endl;
	}

	template <typename T, typename Pr>
	void s_reverse_iterator(std::set<T, Pr>& m_set) {
		std::cout << "Reverse Iterator: ";
		for (auto it = m_set.rbegin();it != m_set.rend();it++) {
			std::cout << *it << ' ';
		}
		std::cout << std::endl;
	}

	// search elements match with value and return bool
	template <typename T, typename Pr>
	bool s_count(std::set<T, Pr>& m_set, const T& value) {
		if (m_set.count(value)) {
			std::cout << value << " is found in set\n";
			return true;
		}
		else {
			std::cout << value << " is not found in set\n";
			return false;
		}
	}

	// find elements is match the value and return iterator element
	// return set::end if not found
	template <typename T, typename Pr>
	void s_find(std::set<T, Pr>& m_set, const T& value) {
		auto it = m_set.find(value);
		if (it != m_set.end()) {
			std::cout << "Element is found : " << *it;
		}
		else {
			std::cout << "Element not found return last element : " << *--it; // set::end - 1, last element
		}
		std::cout << std::endl;
	}

	// check empty and return bool
	template <typename T, typename Pr>
	bool s_empty(std::set<T, Pr>& m_set) {
		if (m_set.empty()) {
			std::cout << "Set is empty.\n";
			return true;
		}
		else {
			std::cout << "Set is not empty.\n";
			return false;
		}
	}

	// get range of equal elements, return equally element and the next element
	template <typename T, typename Pr>
	void s_equal_range(std::set<T, Pr>& m_set, const T& value) {
		auto it = m_set.rbegin(); // access last element
		if (value > *it) return; // value bigger than last element will fault

		std::pair<std::set<int>::const_iterator, std::set<int>::const_iterator> ret;
		ret = m_set.equal_range(value);
		std::cout << "Equal range match/next element: " << *ret.first << "\tnext: " << *ret.second << std::endl;
	}

	// returns a copy of the comparison
	template <typename T, typename Pr>
	void s_key_comp(std::set<T, Pr>& m_set) {
		auto comp = m_set.key_comp();
		for (auto it : m_set) {
			// comparision by less than
			if (comp(it, 5)) 
				std::cout << it << " is less than 5\n";

			// comparision by greater than
			if (comp(5, it)) 
				std::cout << it << " is greater than 5\n";
		}
	}

	// ### UPDATE ###

	// construct and insert element
	template <typename T, typename Pr>
	void s_emplace(std::set<T, Pr>& m_set, const T& value) {
		m_set.emplace(value);
	}

	// construct and insert element with hints
	template <typename T, typename Pr>
	void s_emplace_hint(std::set<T, Pr>& m_set, const T& value) {
		m_set.emplace_hint(m_set.begin(), value);
	}

	// insert element 
	template <typename T, typename Pr>
	void s_insert(std::set<T, Pr>& m_set, const T& value) {
		m_set.insert(value);
		// m_set.insert(m_set.begin(), 100); // position and value
		// int arr[] ={ 99,2,3 };
		// m_set.insert(arr,arr+3); // insert array
	}

	// return iterator position with pointing element
	template <typename T, typename Pr>
	void s_upper_bound(std::set<T, Pr>& m_set) {
		auto itup = m_set.upper_bound(12); 
		std::cout << "Start iterate: \n";
		for (auto it = m_set.begin(); it != itup ;it++) {
			std::cout << *it << '\n';
		}
		std::cout << "Reach upper bound: " << *itup << std::endl;
	}

	// return iterator position with pointing element
	template <typename T, typename Pr>
	void s_lower_bound(std::set<T, Pr>& m_set) {
		auto itlow = m_set.lower_bound(8);
		std::cout << "Start iterate with lower bound: " << *itlow << std::endl;
		for (auto it = itlow; it != m_set.end();it++) {
			std::cout << *it << '\n';
		}
		std::cout << "Container end.\n";
	}


	// ### DELETE ###

	// remove all elements
	template <typename T, typename Pr>
	void s_clear(std::set<T, Pr>& m_set) {
		m_set.clear();
	}

	// remove single element or selected range
	template <typename T, typename Pr>
	void s_erase(std::set<T, Pr>& m_set, const T& value) {
		m_set.erase(value);
		//m_set.erase(m_set.begin(),m_set.end());
	}
};


int main() {
	SetMemberFunction s;
	s.s_iterator(set_6);
	s.s_count(set_6, 100);
	s.s_emplace(set_6, 12);
	s.s_emplace_hint(set_6,12);
	s.s_equal_range(set_6,15);
	s.s_print(set_6);
	
	s.s_erase(set_6,11);
	s.s_find(set_6, 120);
	s.s_get_allocator(set_1);
	s.s_insert(set_1,10);
	s.s_key_comp(set_6);
	s.s_upper_bound(set_6);
	s.s_lower_bound(set_6);
	s.s_print(set_6);
	s.s_print(set_2);
	s.s_print(set_3);
	s.s_print(set_4);
	s.s_print(set_5);
	s.s_print(set_6);
	s.s_print(set_7);
	return 0;
}

// References:
// 1. https://www.cplusplus.com/reference/set/