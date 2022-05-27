#include <thread>
#include <iostream>
#include <mutex>
#include <shared_mutex>

class ThreadFunction {
private:
	char c[512]; // share variable
	bool finished = false;
	std::shared_mutex s_mutex;
	std::mutex mutex1, mutex2;
	int count = 0;

public:
	void jobMutex() {
		// mutex can prevent synchronization problem between two thread when the variable was shared in thread.
		mutex1.lock(); // lock current thread
		count += 1;
		std::cout << "Job " << count << " started." << std::endl;
		std::cout << "Job " << count << " finished." << std::endl;
		mutex1.unlock(); // unlock current threads
	}

	void lock_unlock_mutex() {
		// lock_guard is mutex wrapper
		// It will lock mutex within the scope and unlock the mutex after the scope
		std::lock_guard <std::mutex> lock(mutex1);
		count++;
		std::cout << "Count: " << count << "\tThread id: " << std::this_thread::get_id() << std::endl;
	}

	void operate_value() {
		// unique_lock only given one thread to operate the value
		// use unique_lock when it's input function and have more parallelizable code	
		// std::condition_variable::wait(...) had to use unique_lock as an input 
		std::unique_lock<std::mutex> lock(mutex1);
		std::cout << "Count: " << ++count << '\n';
	}

	void send() {
		// using shared_lock able to read the value at the same time for mutiple thread/reader 
		std::shared_lock<std::shared_mutex> lock(s_mutex);
		std::cout << "Start sending...\n";
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
		while (!finished) {
			std::cout << "\nSend: ";
			std::cin.getline(c, 512);

			if (strcmp(c, "exit") == 0) {
				finished = true;
			}
		}
		std::cout << "Closing send.\n";
	}

	void recv() {
		std::shared_lock<std::shared_mutex> lock(s_mutex);
		std::cout << "Start receive...\n";
		memset(c, 0, sizeof(c));
		while (!finished) {
			if (strlen(c) != NULL) {
				std::cout << "Recv: " << c << std::endl;
				memset(c, 0, sizeof(c));
			}
		}
		std::cout << "Closing recv.\n";
	}

	// if two mutex is lock together will become deadlock
	void deadlock1() {
		mutex1.lock();
		mutex2.lock();
		for (int i = 0;i < 10;i++)
			std::cout << "Deadlock 1: " << count++ << '\n';
	}

	void deadlock2() {
		mutex2.lock();
		mutex1.lock();
		for (int i = 0;i < 10;i++)
			std::cout << "Deadlock 2: " << count++ << '\n';
	}

	void get_thread_id(const std::thread& t) {
		std::lock_guard<std::mutex> lock(mutex1);
		std::cout << "Thread id: " << t.get_id() << '\t';
		std::cout << "Num of Hardware Concurrency: " << t.hardware_concurrency() << '\n';
	}

};

int main() {
	ThreadFunction tf;
	// Call class function
	std::thread t1(&ThreadFunction::lock_unlock_mutex, &tf);
	std::thread t2(&ThreadFunction::lock_unlock_mutex , &tf);
	std::thread t3(std::move(t2)); // move t2 to t3, t2 is no longer a thread

	tf.get_thread_id(t1);
	tf.get_thread_id(t2); // t2 is empty
	tf.get_thread_id(t3);

	// synchronize threads;
	t1.join();
	//t2.join(); // throw exception if running t2
	t3.join();

	/*std::thread t4(&ThreadFunction::deadlock1, &tf);
	std::thread	t5(&ThreadFunction::deadlock2, &tf);
	t4.join();
	t5.join();*/

	std::string str = "hello";
	std::cout << str[1];

	return 0;
}

// References:
// 1. How to call thread : https://en.cppreference.com/w/cpp/thread/thread/thread
// 2. Shared_mutex : https://en.cppreference.com/w/cpp/thread/shared_mutex
// 3. Different lock_gurad and unique_lock : http://jakascorner.com/blog/2016/02/lock_guard-and-unique_lock.html