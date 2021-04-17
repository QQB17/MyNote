#include <iostream>
#include <stack>
#include <vector>
#include <deque>
#include <list>

// Stack is LIFO(Last In First Out) means elements are only insert or extracted from one end in this container.
// Implemented as container adaptor

// Construct container
std::vector<int> vec_1(3, 1);
std::deque<int> deque_1(4, 2);
std::list<int> list_1(5, 3);

// Construct stack -- C++ 11
std::stack<int> stack_1; // default
std::stack<int> stack_2(deque_1); // copy deque
std::stack<int, std::vector<int>> stack_3(vec_1); // copy vector
std::stack<int, std::list<int>> stack_4(list_1); // copy list
std::stack<int> stack_5(std::move(deque_1)); // move deque

class StackFunction {
public:
	// print stack
	template <typename T>
	void s_print(std::stack<T>& m_stack) {
		int n = m_stack.size();
		std::cout << "Stack size: " << n << std::endl;
		for (int i = 0;i < n;i++) {
			std::cout << "[" << i << "]\t" << m_stack.top() << '\n';
			m_stack.pop();
		}
	}

	// print stack with container
	template <typename T, typename Containter>
	void s_print(std::stack<T, Containter>& m_stack) {
		int n = m_stack.size();
		std::cout << "Stack size: " << n << std::endl;
		for (int i = 0;i < n;i++) {
			std::cout << "[" << i << "]\t" << m_stack.top() << '\n';
			m_stack.pop();
		}
	}
};

int main() {
	StackFunction sf;

	stack_3.push(10); // copy value and insert element on the top
	stack_3.emplace(5); // construct and insert element on the top
	stack_3.pop(); // remove top element
	stack_3.top(); // access top element
	stack_3.size(); // size
	stack_1.swap(stack_5); // exchange content must is same container
	sf.s_print(stack_3);

	return 0;
}

// References:
// 1. https://www.cplusplus.com/reference/stack/stack/