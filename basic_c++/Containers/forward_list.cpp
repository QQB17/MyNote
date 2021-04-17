#include <iostream>
#include <forward_list>

// Forward list are sequence container
// Only poiting with the next element, "list" pointing back & next element
// Can't direct access element position, need to iteration to pointer element
// Only this container dont have "size" member function

// Construct forward list -- C++ 11
std::forward_list<int> flist_1;									// default
std::forward_list<int> flist_2(2, 33);							// assign size and value
std::forward_list<int> flist_3(flist_2.begin(),flist_2.end());	// range
std::forward_list<int> flist_4(flist_2);						// copy
std::forward_list<int> flist_5(std::move(flist_4));				// move, flist_4 now is NULL, but alive
std::forward_list<int> flist_6{ 2,4,6,8,9};						// intializer_list


class ForwardListMemberFunction {
public:
	// ### CREATE ###



	// ### READ   ###
	
	template <typename T>
	void fl_print(std::forward_list<T>& m_flist) {
		int size = 0;
		for (auto& a : m_flist) {
			std::cout << "[" << size++ << "]\t" << a << '\n';
		}
		std::cout << "Forward list size: " << size << "\n\n";
	}

	void fl_iterator(std::forward_list<int>& m_flist) {
		std::cout << "Iterator forward list: ";
		for (auto it = m_flist.begin();it != m_flist.end();it++) 
			std::cout << *it << '\n';
		std::cout << std::endl;
	}

	bool fl_empty(std::forward_list<int>& m_flist) {
		if (m_flist.empty()) {
			std::cout << "Forward list is empty.\n";
			return true;
		}
		else {
			std::cout << "Forward list in not empty.\n";
			return false;
		}
	}

	void fl_front(std::forward_list<int>& m_flist) {
		std::cout << "Front value: " << m_flist.front() << std::endl;
	}

	void fl_max_size(std::forward_list<int>& m_flist) {
		std::cout << "Max size: " << m_flist.max_size() << std::endl;
	}

	
	// ### UPDATE ###

	void fl_assign(std::forward_list<int>& m_flist1, std::forward_list<int>& m_flist2) {
		m_flist1.assign(5, 10); // size and value
		m_flist2.assign(m_flist1.begin(), m_flist1.end()); // iteration
		m_flist2.assign({ 5,6,7,8,9,10 }); // intialize list
	}

	void fl_insert_after(std::forward_list<int>& m_flist) {
		auto it = m_flist.begin();
		m_flist.insert_after(m_flist.before_begin(), 11); // return position before 1st element
		m_flist.insert_after(it,2, 8);  //it =[1], starting postion, add size, value
		m_flist.insert_after(it, m_flist.begin(), m_flist.end()); // starting position, assign list
		m_flist.insert_after(it, { 1,2,3 });
	}

	// construct and insert element in after the position
	void fl_emplace_after(std::forward_list<int>& m_flist) {
		m_flist.emplace_after(m_flist.before_begin(), 1);
	}

	// construct and insert element at the beginning
	void fl_emplace_front(std::forward_list<int>& m_flist) {
		m_flist.emplace_front(1);
	}

	// remove element after position
	void fl_erase_after(std::forward_list<int>& m_flist) {
		m_flist.erase_after(m_flist.begin()); // remove [1]
		m_flist.erase_after(m_flist.begin(), m_flist.end()); // remove [1] -> end
	}

	void fl_merge(std::forward_list<int>& m_flist1, std::forward_list<int>& m_flist2) {
		m_flist1.merge(m_flist2);
	}

	void fl_push_front(std::forward_list<int>& m_flist) {
		m_flist.push_front(111);
	}

	void fl_resize(std::forward_list<int>& m_flist) {
		m_flist.resize(1); // shrink size and remove other element
		m_flist.resize(10, 5); // like assign, give size and value
	}

	void fl_reverse(std::forward_list<int>& m_flist) {
		m_flist.reverse();
	}

	void fl_sort(std::forward_list<int>& m_flist) {
		m_flist.sort(); // default sort
		m_flist.sort(std::greater<int>()); // compare the the value and sort
	}

	void fl_splice_after(std::forward_list<int>& m_flist1, std::forward_list<int>& m_flist2) {
		auto it = m_flist1.begin();
		m_flist1.splice_after(m_flist1.before_begin(), m_flist2); // splice to the front
		m_flist2.splice_after(m_flist2.before_begin(), m_flist1, m_flist1.begin(), it);
	}

	void fl_swap(std::forward_list<int>& m_flist1, std::forward_list<int>& m_flist2) {
		m_flist1.swap(m_flist2);
	}

	// remove duplicate value
	void fl_unique(std::forward_list<int>& m_flist) {
		m_flist.unique();
	}


	// ### DELETE ###

	// remove all element
	void fl_clear(std::forward_list<int>& m_flist) {
		m_flist.clear();
	}

	// remove 1st element
	void fl_pop_front(std::forward_list<int>& m_flist) {
		m_flist.pop_front();
	}

	// remove specific value
	void fl_remove(std::forward_list<int>& m_flist) {
		m_flist.remove(2);
	}

	void fl_remove_if(std::forward_list<int>& m_flist) {
		auto even = [](int& value) {
			return ((value % 2) == 0); 
		};
		m_flist.remove_if(even);
	}
};

int main() {
	ForwardListMemberFunction f;
	f.fl_print(flist_6);
	f.fl_splice_after(flist_6,flist_2);
	f.fl_print(flist_6);

	return 0;
}