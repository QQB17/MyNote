#include <iostream>
#include <queue>
#include <vector>
#include <list>
#include <deque>

// Queue are a type of container adaptor, design for operate in FIFO (First-In Fisrt-Out)
// Element can inserted and extracted from end either front
// Use "push" to insert element, use "front" to access element

// Construct Container
std::vector<int> vec_1(2, 1);
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
std::priority_queue<int> p_queue_2(3, 5); // size and value
std::priority_queue<int> p_queue_3(vec_2.begin(), vec_2.end()); // copy iteration
std::priority_queue<int> p_queue_4(std::move(p_queue_3)); // move
// default container is "vector", default comparsion is "less", insert intialize list
std::priority_queue<int, std::vector<int>, std::less<int>> p_queue_5(5,10); 
// set container to "dequeu" and set comparasion to "greater", copy iteration vector
std::priority_queue<int, std::deque<int>,std::greater<int>> p_queue_6(vec_2.begin(),vec_2.end()); 

class QueueMemberFunction {
public:

	template <typename T>
	void q_print(std::queue<T>& m_queue) {
		int n = m_queue.size();
		std::cout << "Queue size: " << n << std::endl;
		std::cout << "Start of the Queue\n";
		for (int i = 0;i < n;i++) {
			std::cout << "[" << i << "]\t" << m_queue.front() << '\n';
			m_queue.pop();
		}
		std::cout << "End of the Queue\n";
	}

	template <typename T, typename Container>
	void q_print(std::queue<T, Container>& m_queue) {
		int n = m_queue.size();
		std::cout << "Queue size: " << n << std::endl;
		std::cout << "Start of the Queue\n";
		for (int i = 0;i < n;i++) {
			std::cout << "[" << i << "]\t" << m_queue.front() << '\n';
			m_queue.pop();
		}
		std::cout << "End of the Queue\n";
	}

	// Insert element to the end
	void q_push() {
		int x = 99;
		queue_1.push(x);
		queue_1.push(10);
	}

	// Construct and insert element to the end
	void q_emplace() {
		queue_1.emplace(50);
	}

	// remove first element
	void q_pop() {
		queue_1.pop();
	}

	void q_front() {
		std::cout << "First element of Queue[0]: " << queue_1.front() << std::endl;
	}
	
	void q_back() {
		std::cout << "Last element of Queue[" << queue_1.size() - 1 << "]: " << queue_1.back() << std::endl;
	}

	bool q_empty() {
		if (queue_1.empty()) {
			std::cout << "Queue is empty.\n";
			return true;
		}
		else {
			std::cout << "Queue is not empty.\n";
			return false;
		}
	}

	void q_swap() {
		queue_1.swap(queue_5);
	}
};

class PriorityQueueMemberFunction {
public:

	template <typename T>
	void pq_print(std::priority_queue<T>& m_priority) {
		int n = m_priority.size();
		std::cout << "Priority Queue size: " << n << std::endl;
		for (int i = 0;i < n;i++) {
			std::cout << "[" << i << "]\t" << m_priority.top() << '\n';
			m_priority.pop();
		}
	}

	template <typename T, typename Container>
	void pq_print(std::priority_queue<T, Container>& m_priority) {
		int n = m_priority.size();
		std::cout << "Priority Queue size: " << n << std::endl;
		for (int i = 0;i < n;i++) {
			std::cout << "[" << i << "]\t" << m_priority.top() << '\n';
			m_priority.pop();
		}
	}
	
	template <typename T,typename Container, typename Pr >
	void pq_print(std::priority_queue<T, Container, Pr>& m_priority) {
		int n = m_priority.size();
		std::cout << "Priority Queue size: " << n << std::endl;
		for (int i = 0;i < n;i++) {
			std::cout << "[" << i << "]\t" << m_priority.top() << '\n';
			m_priority.pop();
		}
	}

	// insert element and sort
	void pq_push() {
		int x = 1;
		p_queue_1.push(x);
		p_queue_1.push(5);
	}

	// constrcut and insert element and sort
	void pq_emplace() {
		p_queue_1.emplace(2);
	}

	void pq_empty() {
		if (p_queue_1.empty()) {
			std::cout << "Queue is empty.\n";
		}
		else {
			std::cout << "Queue is not empty.\n";
		}
	}

	// remove top element
	void pq_pop() {
		p_queue_1.pop();
	}

	void pq_top() {
		std::cout << p_queue_1.top() << std::endl;
	}

	void pq_swap() {
		p_queue_1.swap(p_queue_2);
	}
};

int main() {
	/*QueueMemberFunction q;
	q.q_push();
	q.q_emplace();
	q.q_front();
	q.q_back();
	q.q_pop();
	q.q_swap();
	q.q_print(queue_1);*/

	PriorityQueueMemberFunction pr;
	pr.pq_push();
	pr.pq_emplace();
	pr.pq_top();
	pr.pq_swap();
	pr.pq_print(p_queue_1);
	pr.pq_print(p_queue_2);

	return 0;
}