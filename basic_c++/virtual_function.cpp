#include <iostream>

// virtual function is dyanamic dispatch
// It ask for the compiler create a virtual table to mapping the override function
// Need addition memory to store virtual table.
// Addition performance to find out which function is map.

class Shape {
public:
	virtual void getArea() { std::cout << "Shape area.\n"; }
};

class Rectangle : public Shape {
private:
	double height, width;
public:
	Rectangle(const double& h, const double& w)
		: height(h), width(w) {}

	// always write "override" while override function, it may help you a lot.
	void getArea() override {
		std::cout << "Rectange area: " << height * width << std::endl;
	}
};

void printGetArea(Shape* shape) {
	shape->getArea();
}

int main() {
	Shape s1;
	Shape* s = new Shape();
	s->getArea();
	s1.getArea();

	Rectangle* r = new Rectangle(2.5, 4.8);
	r->getArea();

	printGetArea(r);

	delete s;
	delete r;
	return 0;
}