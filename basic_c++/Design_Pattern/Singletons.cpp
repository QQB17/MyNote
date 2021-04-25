#include <iostream>

// Singletons to instantiate to single instance
// we not need to create mutiple instance, if the same method keep repeating

class Singleton
{
public:
	// Delete the function of copy constructor
	Singleton(const Singleton&) = delete;
	static Singleton& Get(){ return s_Instances; }

	void Function() {}
	
private:
	Singleton() {}

	static Singleton s_Instances;
};

Singleton Singleton::s_Instances;

class Random {
public:
	// Non copyable
	Random& operator=(const Random&) = delete;
	Random(const Random&) = delete;

	static Random& Get() 
	{
		static Random Instances;
		return Instances; 
	}

	static float Float() { return  Get().IFloat(); }

private:
	// internal function
	float IFloat() { return m_RandomGenerator; }
	Random() {}

	float m_RandomGenerator = 0.5;

};


namespace RandomClass {
	float m_RandomGenerator = 0.5;

	static float Float() {
		return m_RandomGenerator;
	}
}


int main() {

	float number = Random::Float();
	std::cout << number << std::endl;

	float number2 = RandomClass::Float();
	std::cout << number2 << std::endl;

	auto& instance = Singleton::Get();

	Singleton::Get().Function();
}

// References
// 1. Singletons in c++ : https://www.youtube.com/watch?v=PPup1yeU45I
