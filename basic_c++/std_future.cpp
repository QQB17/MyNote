#include <future>
#include <iostream>
#include <thread>

// std::future can access to the thread and do some asynchronous operations to the value
// It can get the value from the future.
// We also can check the current status using std::future_status

// Check for future status
template <typename F>
void futureStatus(F&& f) {
	std::future_status status;
	do {
		std::cout << "Status: ";
		
		status = f.wait_for(std::chrono::seconds(1));
		if (status == std::future_status::deferred) {
			std::cout << "deferred.\n";
		}
		else if (status == std::future_status::timeout) {
			std::cout << "timeout.\n";
		}
		else if (status == std::future_status::ready) {
			std::cout << "ready.\n";
		}

	} while (status != std::future_status::ready);

}

int main() {
	// future from a packaged task
	std::packaged_task<int()> task([] {return 7;}); // wrap_function
	std::future<int> f1 = task.get_future(); // get a future
	std::thread t(std::move(task)); // launch on a thread

	// future from an async()
	std::future<int> f2 = std::async(std::launch::async, [] {return 8;});

	// future from a promise
	std::promise<int> p;
	std::future<int> f3 = p.get_future();
	std::thread([&p] {p.set_value_at_thread_exit(9);}).detach();

	std::cout << "Waiting ...\n" << std::flush;
	f1.wait();
	f2.wait();
	f3.wait();

	futureStatus(f1);
	futureStatus(f2);
	futureStatus(f3);

	std::cout << "Result of get: " << f1.get() << " " << f2.get() << " " << f3.get() << std::endl;

	t.join();

	return 0;
}

// Reference from : 
// 1. std::future https://en.cppreference.com/w/cpp/thread/future
// 2. std::future_status https://www.cnblogs.com/qicosmos/p/3534211.html