#include <iostream>
#include <vector>

// 1. Vector is to store element in sequential location.
// 2. Efficient with resize, access element.
// 3. 

// Allocate Statement: https://stackoverflow.com/questions/8036474/when-vectors-are-allocated-do-they-use-memory-on-the-heap-or-the-stack
// 1. vector<Type> vec; // will allocate the vector on the stack,but the element on the heap
// 2. vector<Type> *vec = new vector<Type>; // allocate on the heap
// 3 .vector<Type*> vec; // allocate vector on the stack, and a bunch of pointers on the heap

// Construct vector -- C++11
std::vector<int> vec1;								// default
std::vector<int> vec2(2,100);						// fill size and value
std::vector<int> vec3(vec2.begin(), vec2.end());	// iterating from vec2
std::vector<int> vec4{ 11,22,33,44 };				// fill value
std::vector<int> vec5(vec4);						// copy
std::vector<int> vec6(std::move(vec5));				// move, now vec5 is NULL but still alive

class VectorMemberFunction {
public:
	template <typename T>
	void v_print(std::vector<T>& vec) {
		int x = 0, n = vec.size();
		v_capacity(vec);
		for (auto& a : vec)
			std::cout << "[" << x++ << "]\t" << a << '\n';
		std::cout << std::endl;
	}
	
	// Assign size and value
	void v_assign() {
		// Assign vector size and value
		vec1.assign(10, 100);

		// Assign with iterator value
		std::vector<int>::iterator it;
		it = vec1.begin() + 1;
		vec2.assign(it, vec1.end() - 1);

		// Assign an array to vector
		int ints[] = { 33,44,55 };
		vec3.assign(ints,ints + 3);
	}

	// vector position
	void v_at() {
		for (int i = 0;i < vec4.size();i++) 
			std::cout << "Vector value: " << vec4.at(i) << " At: " << i << '\n';
		std::cout << std::endl;
	}

	// Vector front value
	void v_front() {
		std::cout << "Vector value at front: " << vec4.front() << '\n';
	}

	// Vector back value
	void v_back() {
		std::cout << "Vector value at back: " << vec4.back() << '\n';
	}

	// vector postion in begin & end
	void v_iterator() {
		std::cout << "Iterator value using begin and end: ";
		// return iterator value must pointer to the object
		for (auto it = vec4.begin(); it != vec4.end();it++) 
			std::cout << *it << ' ';
		std::cout << std::endl;
	}

	void v_reverse_iterator() {
		std::cout << "Reverse iterator value using cbegin and cend: ";
		for (auto it = vec4.rbegin(); it != vec4.rend() ;it++)
			std::cout << *it << ' ';
		std::cout << std::endl;
	}

	// Currently allocated storage capacity, it can be bigger than current size
	template <typename T>
	void v_capacity(std::vector<T>& vec) {
		std::cout << "Current Vector size: " << vec.size() << std::endl;
		std::cout << "Current Vector capacity: " << vec.capacity() << std::endl;
	}

	// Remove all elements
	void v_remove() {
		v_print(vec4);
		vec4.clear();
		v_print(vec4);
	}

	// direct pointer to the array
	void v_data() {
		// Need to initial vector, because p can't be nullptr
		vec2.assign(5,0);

		int* p = vec2.data(); 
		*p = 10; // vec2[0] = 10;
		++p; // vec2[1]
		*p = 20; // vec2[1] = 20;
		p[3] = 99; // vec2[3] = 99;

		v_print(vec2);
	}

	// insert new element in selected position to the vector without creating a temporary storage
	// efficient increases the container size by one
	void v_emplace() {
		v_print(vec4);
		vec4.emplace(vec4.begin(), 9);
		vec4.emplace(vec4.end(), 100);
		v_print(vec4);
	}

	// insert new element at the end of the vector
	// directly insert the object without calling the copy construct
	// emplace_back is better than push_back
	void v_emplace_back() {
		v_print(vec4);
		vec4.emplace_back(100);
		v_print(vec4);
	}

	// insert new element at the end of the vector
	// create a temporary object to storage the data, then copy or move the object to the vector
	void v_push_back() {
		v_print(vec4);
		vec4.push_back(10);
		v_print(vec4);
	}

	// Change the vector size and intialize the value
	void v_resize() {
		vec4.resize(20);
		v_print(vec4);
	}

	// Only allocated memory and increase the capacity
	void v_reserve() {
		vec4.reserve(30);
		v_print(vec4);
	}


	// Shrink the capacity to actual size
	void v_shrink_to_fit() {
		v_reserve();
		vec4.shrink_to_fit();
		v_print(vec4);
	}
};

class VectorType : public VectorMemberFunction {
public:
	std::vector<std::pair<int, int>> v_pair{ {1,2},{3,4},{5,6} };
	std::vector<std::vector<char>> v_char{ {'h','e','l','l','o'},{'w','o','r','l','d'} };
	std::vector<std::vector<double>> v_double{ {3.142,5.16},{7.66,4.22},{1.11,3.33} }; 

	void v_vector_pair() {
		for (auto& v : v_pair) 
			std::cout << v.first <<' ' << v.second << '\n';
	}

	template <typename T>
	void v_vector_vector(std::vector<std::vector<T>> vec) {
		int n = vec.size();  // Size of row
		int m = vec[0].size(); // Size of column
		v_capacity(vec);
		v_capacity(vec[0]);

		std::cout << "Print double vector elements: " << std::endl;
		for (int i = 0; i < n;i++) {
			std::cout << "[" << i << "]\t";
			for (int j = 0; j < m;j++) 
				std::cout << vec[i][j] << ' ';
			std::cout << '\n';
		}
	}
};

int main() {
	VectorMemberFunction func;
	VectorType vt;

	func.v_print(vec5);
	func.v_print(vec6);

	vt.v_vector_vector(vt.v_double);

	return 0;
}

// References :
// 1. https://www.cplusplus.com/reference/vector/