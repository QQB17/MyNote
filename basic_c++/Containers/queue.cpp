#include <iostream>
#include <queue>
#include <vector>
#include <list>
#include <deque>

// Queue are a type of container adaptor, design for operate in FIFO (First-In Fisrt-Out)
// Element can inserted and extracted from end either front
// Use "push" to insert element, use "front" to access element

// Construct Container
std::vector<int> vec_1{ 4,5,6,7,8 };
std::list<int> list_1(3, 2);
std::deque<int> deque_1(4, 3);

// Construct Queue -- C++ 11
std::queue<int> queue_1; // default
std::queue<int> queue_2(deque_1); // copy deque
std::queue<int, std::vector<int>> queue_3(vec_1); // copy vec
std::queue<int, std::list<int>> queue_4(list_1); // copy list
std::queue<int> queue_5(std::move(queue_2)); // move queue
std::queue<int, std::vector<int>> queue_6(std::move(vec_1)); // move vector

// Priority Queue are a type of container adaptor, design for store greatest element in the begin
// Sort after operate the adaptor depends on comparasion setting.

// Construct Container
std::vector<int> vec_2{ 5,2,3,8,1,10 };

// Construct Priority Queue -- C++ 11
std::priority_queue<int> p_queue_1; // default
std::priority_queue<int> p_queue_2(3, 100); // size and increment starting value by size
std::priority_queue<int> p_queue_3(vec_2.begin(), vec_2.end()); // copy iteration
std::priority_queue<int> p_queue_4(std::move(p_queue_3)); // move
// default container is "vector", default comparsion is "less", insert intialize list
std::priority_queue<int, std::vector<int>, std::less<int>> p_queue_5(5,10); 
// set container to "dequeu" and set comparasion to "greater", copy iteration vector
std::priority_queue<int, std::deque<int>,std::greater<int>> p_queue_6(vec_2.begin(),vec_2.end()); 

class QueueMemberFunction {
public:

	template <typename T, typename Container>
	void q_print(std::queue<T, Container>& m_queue) {
		if (m_queue.empty()) return;
		int n = m_queue.size();
		std::cout << "Queue size: " << n << std::endl;

		// get the first index and iterate it
		auto it = m_queue.front();
		for (int i = 0; i < n;i++) 
			std::cout << "[" << i << "]\t" << it++ << '\n';
	}

	// Insert element to the end
	template <typename T, typename Container>
	void q_push(std::queue<T, Container>& m_queue, const T& value) {
		m_queue.push(value);
	}

	// Construct and insert element to the end
	template <typename T, typename Container>
	void q_emplace(std::queue<T, Container>& m_queue, const T& value) {
		m_queue.emplace(value);
	}

	// remove first element
	template <typename T, typename Container>
	void q_pop(std::queue<T, Container>& m_queue) {
		//m_queue.pop();
	}

	template <typename T, typename Container>
	void q_front(std::queue<T, Container>& m_queue) {
		//std::cout << "First element of Queue[0]: " << m_queue.front() << std::endl;
	}
	template <typename T, typename Container>
	void q_back(std::queue<T, Container>& m_queue) {
		//std::cout << "Last element of Queue[" << m_queue.size() - 1 << "]: " << m_queue.back() << std::endl;
	}

	template <typename T, typename Container>
	bool q_empty(std::queue<T, Container>& m_queue) {
		if (m_queue.empty()) {
			std::cout << "Queue is empty.\n";
			return true;
		}
		else {
			std::cout << "Queue is not empty.\n";
			return false;
		}
	}

	template <typename T, typename Container>
	void q_swap(std::queue<T, Container>& m_queue1, std::queue<T, Container>& m_queue2) {
		m_queue1.swap(m_queue2);
	}

};

class PriorityQueueMemberFunction {
public:
	
	template <typename T,typename Container, typename Pr >
	void pq_print(std::priority_queue<T, Container, Pr>& m_priority) {
		if (m_priority.empty()) return;
		int n = m_priority.size();
		std::cout << "Priority Queue size: " << n << std::endl;
		// get the first index and iterate it
		auto it = m_priority.top();
		for (int i = 0; i < n;i++)
			std::cout << "[" << i << "]\t" << it++ << '\n';
	}

	// insert element and sort
	template <typename T, typename Container, typename Pr >
	void pq_push(std::priority_queue<T, Container, Pr>& m_priority,const T& value) {
		m_priority.push(value);
	}

	// constrcut and insert element and sort
	template <typename T, typename Container, typename Pr >
	void pq_emplace(std::priority_queue<T, Container, Pr>& m_priority, const T& value) {
		m_priority.emplace(value);
	}

	template <typename T, typename Container, typename Pr >
	bool pq_empty(std::priority_queue<T, Container, Pr>& m_priority) {
		if (m_priority.empty()) {
			std::cout << "Queue is empty.\n";
			return true;
		}
		else {
			std::cout << "Queue is not empty.\n";
			return false;
		}
	}

	// remove top element

	template <typename T, typename Container, typename Pr >
	void pq_pop(std::priority_queue<T, Container, Pr>& m_priority) {
		m_priority.pop();
	}

	template <typename T, typename Container, typename Pr >
	void pq_top(std::priority_queue<T, Container, Pr>& m_priority) {
		std::cout << "Priority_queue first element: " << m_priority.top() << std::endl;
	}

	template <typename T, typename Container, typename Pr >
	void pq_swap(std::priority_queue<T, Container, Pr>& m_priority1, 
		std::priority_queue<T, Container, Pr>& m_priority2) 
	{
		m_priority1.swap(m_priority2);
	}
};

int main() {
	QueueMemberFunction q;
	q.q_push(queue_3,20);
	q.q_emplace(queue_3,10);
	q.q_front(queue_3);
	q.q_back(queue_3);
	 q.q_pop(queue_3);
	q.q_swap(queue_3,queue_6);
	q.q_print(queue_3);
	q.q_print(queue_6);
	q.q_print(queue_5);
	q.q_print(queue_4);

	PriorityQueueMemberFunction pr;
	pr.pq_push(p_queue_1,100);
	pr.pq_emplace(p_queue_1,3412);
	pr.pq_top(p_queue_1);
	pr.pq_swap(p_queue_1, p_queue_2);
	pr.pq_print(p_queue_1);
	pr.pq_print(p_queue_2);
	pr.pq_print(p_queue_3);
	pr.pq_print(p_queue_4);
	pr.pq_print(p_queue_5);

	return 0;
}