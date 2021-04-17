#include <iostream>
#include <list>

// List are sequence container 
// Constant time to insert and erase element
// Pointing back & next element
// Can't direct access pointer position, need iterator to access from a known position
// It will use extra memory to keep linking information associated to each elements


// Construct list -- C++ 11
std::list<int> list_1;								 // default constructor
std::list<int> list_2(4, 100);						 // fill the value
std::list<int> list_3(list_2.begin(), list_2.end()); // iterating through list_2
std::list<int> list_4(list_3);						 // copy from list_3
std::list<int> list_5(std::move(list_4));			 // move, now list_4 is NUll but still alive
std::list<int> list_6{ 11,22,33,44,55 };			 // assign value

class ListMemberFunction {
public:
	// ### Create ###

	// Allocate your own container is very usefull rather than "new foo"
	// Allow to control the container allocate memory and construct the object in seperate step
	void l_get_allocator(std::list<int>& m_list) {
		int* p;
		p = m_list.get_allocator().allocate(5);
		for (int i = 0;i < 5;i++)
			p[i] = i;

		for (int i = 0;i < 5;i++)
			std::cout << p[i] << ' ';
		std::cout << std::endl;
		std::cout << "Allocator address: " << m_list.get_allocator().address(*p) << std::endl;
		m_list.get_allocator().deallocate(p, 5);
		m_list.get_allocator().destroy(p);
	}


	
	// ### Read  ###
	template <typename T>
	void l_print(std::list<T>& m_list) {
		int x = 0, n = m_list.size();
		std::cout << "List size: " << n << std::endl;
		for (auto& a : m_list)
			std::cout << "[" << x++ << "]\t" << a << '\n';
		std::cout << std::endl;
	}

	// return last element
	void l_back(std::list<int>& m_list) {
		std::cout << "Last number for list: " << m_list.back() << std::endl;
	}

	// return first element
	void l_front(std::list<int>& m_list) {
		std::cout << "First number for list: " << m_list.front() << std::endl;
	}

	// Check list, if empty return true
	bool l_empty(std::list<int>& m_list) {
		if (m_list.empty()) {
			std::cout << "List is empty.\n";
			return true;
		} else {
			std::cout << "List is not empty.\n";
			return false;
		}
	}

	void l_max_size(std::list<int>& m_list) {
		std::cout << "Max size: " << m_list.max_size() << std::endl;
	}

	void l_iterator(std::list<int>& m_list) {
		std::cout << "Iterator: ";
		for (auto it = m_list.begin(); it != m_list.end(); it++)
			std::cout << *it << ' ';
		std::cout << std::endl;
	}

	void l_reverse_iterator(std::list<int>& m_list) {
		std::cout << "Iterator with reverse: ";
		for (auto it = list_6.rbegin(); it != list_6.rend();it++)
			std::cout << *it << ' ';
		std::cout << std::endl;
	}
	

	// ### Update ###

	void l_assign() {
		list_1.assign(5, 10); // assign size and value
		list_2.assign(list_1.begin(), list_1.end()); // copy
		int array_list[5] = { 1,2,3,4,5 };
		list_3.assign(array_list, array_list + 4); // assign with list
	}

	void l_resize(std::list<int>& m_list) {
		m_list.resize(m_list.size() * 2);
	}

	// Construct and insert element in a new position
	void l_emplace(std::list<int>& m_list) {
		m_list.emplace(m_list.begin(), 100);
		m_list.emplace(m_list.end(), 99);
	}

	// Insert new element in end of the list
	void l_emplace_back(std::list<int>& m_list) {
		m_list.emplace_back(99);
	}

	// Insert new element in front of the list.
	void l_emplace_front(std::list<int>& m_list) {
		m_list.emplace_front(1);
	}

	// Copy or move the element to last element
	void l_push_back(std::list<int>& m_list) {
		int x = 33;
		m_list.push_back(x);
		m_list.push_back(99);
	}

	void l_push_front(std::list<int>& m_list) {
		int x = 2;
		m_list.push_front(x);
		m_list.push_front(1);
	}

	// Insert element
	void l_insert(std::list<int>& m_list) {
		int n = m_list.size();
		auto it = m_list.begin(); // iterator to point element index
		for (int i = 0;i < n;i++) {
			m_list.insert(it++, i);
		}
	}

	void l_pop_back(std::list<int>& m_list) {
		m_list.pop_back();
	}

	void l_pop_front(std::list<int>& m_list) {
		m_list.pop_front();
	}

	// merge two list
	void l_merge(std::list<int>& m_list1, std::list<int>& m_list2) {
		m_list1.merge(m_list2);
	}

	void l_reverse(std::list<int>& m_list) {
		m_list.reverse();
	}

	void l_sort(std::list<int>& m_list) {
		m_list.sort();
	}

	// transfer element from list to list
	void l_splice(std::list<int>& m_list1, std::list<int>& m_list2) {
		auto it = m_list1.begin();
		m_list1.splice(++it, m_list2); // insert to list[1]
		// move original m_list1 with current index to front
		m_list1.splice(m_list1.begin(), m_list1, it, m_list1.end());  // m_list1[2] = front
	}

	// swap two list
	void l_swap(std::list<int>& m_list1, std::list<int>& m_list2) {
		m_list1.swap(m_list2);
	}

	// remove duplicate value
	void l_unique() { 
		std::list<double> d_list{ 11.1, 11.9, 3.142, 3.98765456, 0.0001, 0.9999 };
		l_print(d_list);
		auto near = [](double& val1, double& val2) {
			return (int(val1) == int(val2));
		};
		d_list.unique(near);
		l_print(d_list);
	}


	// ### Delete  ###

	// remove all elements
	void l_clear(std::list<int>& m_list) {
		m_list.clear();
	}

	// Remove single element front list
	void l_erase(std::list<int>& m_list) {
		m_list.erase(m_list.begin());
		//m_list.erase(m_list[5]); // Can't direct access index number
	}

	// remove element with specific value
	void l_remove(std::list<int>& m_list) {
		m_list.remove(100);
	}
	
	// remove element fulfilling condition
	void l_remove_if(std::list<int>& m_list) {
		// Create a function : bool b (int& value) { return (value <100); }
		auto b = [](int& value) { 
			return (value < 100);
		};
		m_list.remove_if(b);
	}
};

int main() {
	ListMemberFunction lf;
	lf.l_unique();

	return 0;
}

// References: 
// 1. https://www.cplusplus.com/reference/list/list/