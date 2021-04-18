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


	// ### READ   ###

	template <typename T, typename Pr, typename Alloc>
	void s_print(std::set<T,Pr, Alloc>& m_set) {
		int x = 0, n = m_set.size();
		std::cout << "Set size: " << n << std::endl;
		for (auto& it : m_set) {
			std::cout << "[" << x++ << "]\t" << it << '\n';
		}
		std::cout << std::endl;
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
			std::cout << *it;
		}
		else {
			std::cout << *--it; // set::end - 1, last element
		}
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
	s.s_print(set_6);



	return 0;
}

// References:
// 1. https://www.cplusplus.com/reference/set/
// 