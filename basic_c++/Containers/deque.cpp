#include <iostream>
#include <deque>

// Double ended queue are sequence container with dynamic size
// Can expanded or contracted on front or back
// Frequently insertion or removals are perform worse efficient within the deque container
// Less consistent iterator and reference than "list" and "forward list"

// Construct deque -- C++ 11
std::deque<int> deque_1;									// default
std::deque<int> deque_2(2, 5);								// size and value
std::deque<int> deque_3(deque_2.begin(), deque_2.end());	// range
std::deque<int> deque_4(deque_3);							// copy
std::deque<int> deque_5(std::move(deque_4));				// move, deque_4 now is NULL, but alive
std::deque<int> deque_6{ 1,3,5,7,9,10 };					// initialize list
std::deque<int> deque_7(10);								// size

class DequeMemberFunction {
public:

	// ### CREATE ###

	// Copy deque and Create a second template parameter
	void d_get_allocator(std::deque<int>& m_deque) {
		int* p;
		p = m_deque.get_allocator().allocate(5); // allocate size
		
		for (int i = 0;i < 5;i++) 
			m_deque.get_allocator().construct(&p[i], i); // assign value

		for (int i = 0;i < 5;i++) 
			std::cout << p[i] << ' '; // print
		
		// destroy and deallocate
		for (int i = 0;i < 5;i++)
			m_deque.get_allocator().destroy(&p[i]);
		m_deque.get_allocator().deallocate(p, 5);
	}



	// ### READ   ###
	
	template <typename T>
	void d_print(std::deque<T>& m_deque) {
		int x = 0, n = m_deque.size();
		std::cout << "Deque size: " << n << std::endl;
		for (auto& it : m_deque)
			std::cout << "[" << x++ << "]\t" << it << '\n';
		std::cout << std::endl;
	}

	void d_iterator(std::deque<int>& m_deque) {
		std::cout << "Iteration deque: ";
		for (auto it = m_deque.begin(); it != m_deque.end();it++) 
			std::cout << *it << ' ';
		std::cout << std::endl;
	}

	void d_reverse_iterator(std::deque<int>& m_deque) {
		std::cout << "Reverse iteration deque: ";
		for (auto it = m_deque.rbegin(); it != m_deque.rend();it++) 
			std::cout << *it << ' ';
		std::cout << std::endl;
	}

	// return last element
	void d_back(std::deque<int>& m_deque) {
		std::cout << "Deque back: " << m_deque.back() << std::endl;
	}

	// return first element
	void d_front(std::deque<int>& m_deque) {
		std::cout << "Deque front: " << m_deque.front() << std::endl;
	}

	// return element at position 
	void d_at(std::deque<int>& m_deque) {
		std::cout << "Positon [1]: " << m_deque.at(1) << std::endl;
	}

	bool d_empty(std::deque<int>& m_deque) {
		if (m_deque.empty()) {
			std::cout << "Deque is empty.\n";
			return true;
		}
		else {
			std::cout << "Deque is not empty.\n";
			return false;
		}
	}

	void d_max_size(std::deque<int>& m_deque) {
		std::cout << "Max size: " << m_deque.max_size() << std::endl;
	}

	// operator [] to direct access element postion
	void d_square_bracket(std::deque<int>& m_deque) {
		std::cout << "Operator [1]: " << m_deque[1] << std::endl;
	}



	// ### UPDATE ###

	// modify deque
	void d_assign(std::deque<int>& m_deque) {
		std::deque<int> s_deque{ 55,66 };
		m_deque.assign(s_deque.begin(), s_deque.end()); // iterator from other deque
		m_deque.assign(5,99); // size and value
		m_deque.assign({ 123,456,798 }); // initialize list
	}


	// construct and insert element to specific postion
	void d_emplace(std::deque<int>& m_deque) {
		m_deque.emplace(m_deque.begin(), 100); // position and value
	}

	// constrcut and insert element to front
	void d_emplace_front(std::deque<int>& m_deque) {
		m_deque.emplace_front(111); 
	}

	// construct and insert element to back
	void d_emplace_back(std::deque<int>& m_deque) {
		m_deque.emplace_back(99);
	}

	// Insert element
	void d_insert(std::deque<int>& m_deque) {
		m_deque.insert(m_deque.end()-1, 888); // position, value
		m_deque.insert(m_deque.begin(), 3, 33); // position, size, value
		m_deque.insert(m_deque.begin(), { 1,2,3 }); // initialize list
		// position, inputIterator first, inputIterator last
		m_deque.insert(m_deque.end(), m_deque.begin(), m_deque.end()); 
	}

	// Insert add new element to the end
	void d_push_back(std::deque<int>& m_deque) {
		m_deque.push_back(222);
	}

	// Insert add new element to the front
	void d_push_front(std::deque<int>& m_deque) {
		m_deque.push_front(5566);
	}

	void d_resize(std::deque<int>& m_deque) {
		m_deque.resize(1); // resize and remove over element
		m_deque.resize(5, 10); // resize and insert value
	}

	// request the container to reduce its memory usage to fit its size
	void d_shrink_to_fit(std::deque<int>& m_deque) {
		m_deque.shrink_to_fit();
	}

	void d_swap(std::deque<int>& m_deque1, std::deque<int>& m_deque2) {
		m_deque1.swap(m_deque2);
	}



	// ### DELETE ###

	// remove all element
	void d_clear(std::deque<int>& m_deque) {
		m_deque.clear();
	}

	// remove single or selected the range elements
	void d_erase(std::deque<int>& m_deque) {
		m_deque.erase(m_deque.begin()); // position
		m_deque.erase(m_deque.begin(), m_deque.end() - 1); // range
	}

	// remove last element
	void d_pop_back(std::deque<int>& m_deque) {
		m_deque.pop_back();
	}

	// remove first element
	void d_pop_front(std::deque<int>& m_deque) {
		m_deque.pop_front();
	}
};

int main() {
	DequeMemberFunction d;
	d.d_assign(deque_1);
	d.d_print(deque_1);
	d.d_at(deque_1);
	d.d_back(deque_1);
	d.d_front(deque_1);
	d.d_iterator(deque_1);
	d.d_reverse_iterator(deque_1);
	d.d_square_bracket(deque_1);
	d.d_push_back(deque_1);
	d.d_push_front(deque_1);
	d.d_print(deque_1);
	d.d_resize(deque_1);
	d.d_swap(deque_1, deque_6);
	d.d_print(deque_1);

	return 0;
}