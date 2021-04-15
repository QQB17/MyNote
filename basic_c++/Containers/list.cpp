#include <iostream>
#include <list>
#include <vector>

// List are sequence container 
// Constant time to insert and erase element
// Can't direct access pointer position, need iterator to access from a known position
// It will use extra memory to keep linking information associated to each elements


// Construct list -- C++ 11
std::list<int> list_1;								 // default constructor
std::list<int> list_2(4, 100);						 // fill the value
std::list<int> list_3(list_2.begin(), list_2.end()); // iterating through list_2
std::list<int> list_4(list_3);						 // copy from list_3
std::list<int> list_5(std::move(list_4));			 // move, now list_4 is NUll but still alive
std::list<int> list_6{ 11,22,33,44,55 };

class ListMemberFunction {
public:
	
	template <typename T>
	void l_print(std::list<T>& m_list) {
		int x = 0, n = m_list.size();
		std::cout << "List size: " << n << std::endl;
		for (auto& a : m_list)
			std::cout << "[" << x++ << "]\t" << a << '\n';
		std::cout << std::endl;
	}

	void l_assign() {
		list_1.assign(5, 10); // assign size and value
		list_2.assign(list_1.begin(), list_1.end()); // copy
		int array_list[5] = { 1,2,3,4,5 };
		list_3.assign(array_list, array_list+4); // assign with list
	}

	// return last element
	void l_back() {
		std::cout << "Last number for list: " << list_6.back() << std::endl;
	}

	// return first element
	void l_front() {
		std::cout << "First number for list: " << list_6.front() << std::endl;
	}
	
	// remove all elements
	void l_clear() {
		l_print(list_2);
		list_2.clear();
		l_print(list_2);
	}

	// Check list, if empty return true
	void l_empty() {
		if (list_1.empty())
			std::cout << "List is empty.\n";
		else
			std::cout << "List is not empty.\n";
	}

	void l_iterator() {
		std::cout << "Iterator: ";
		for (auto it = list_6.begin(); it != list_6.end(); it++)
			std::cout << *it << ' ';
		std::cout << std::endl;
	}

	void l_reverse_iterator() {
		std::cout << "Iterator with reverse: ";
		for (auto it = list_6.rbegin(); it != list_6.rend();it++)
			std::cout << *it << ' ';
		std::cout << std::endl;
	}

	void l_emplace() {
		list_1.emplace(list_1.begin(), 100);
		l_print(list_1);
	}
};

int main() {
	ListMemberFunction lf;
	lf.l_emplace();
}

// References: 
// 1. https://www.cplusplus.com/reference/list/list/