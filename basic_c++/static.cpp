#include <iostream>

// static variable outside the class internal meaning
// declare variable like private in a class
static int s_Variable = 5;

// static variable inside a class means that variable is actually going to share memory with all instance of the class
// only be one instance of the static variable

extern int s_Variable;

struct Entity
{
	static int x, y;
	int x2, y2;
	static void print() {
		std::cout << x << ' ' << y << std::endl;
	}

	// illegal reference to non-static member
	// compiler have no idea which entity you want to access
	/*static void s_print() {
		std::cout << x2 << ' ' << y2 << std::endl;
	}*/
};

// how class method that is non-static actually look likes 
static void s_print(Entity e) 
{
	std::cout << e.x2 << ' ' << e.y2 << std::endl;
}

//  unresolved external symbol because we actually have to define those static variable somewhere
int Entity::x;
int Entity::y;

// declare global variable is mutable and easy to do mistake
int i = 10;

void Function()
{
	// if you don't want anyone to access the variable, declare static in a local scope
	// 
	static int i = 0;
	i++;
	std::cout << i << std::endl;
}

class Singleton
{
public:
	static Singleton& Get() {
		static Singleton Instance;
		return Instance;
	}

	void Hello() { };
};

int main() {
	Function();
	Function();
	Function();
	Function();

	Singleton::Get().Hello();

	Entity e;
	e.x = 10;
	e.y = 12;

	Entity e1;
	Entity::x = 5;
	Entity::y = 6;
	Entity::print();
	e1.print();

	return 0;

}

// References
// 1. Static in C++ : https://www.youtube.com/watch?v=f3FVU-iwNuA
// 2. Static for Classes and Structs in C++ :https://www.youtube.com/watch?v=V-BFlMrBtqQ&t=40s
// 3. Local Static in C++ : https://www.youtube.com/watch?v=f7mtWD9GdJ4