#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
#include <queue>
#include <condition_variable>
#include <functional>
#include <future>


// What you need to learn before build the thread pool --
// 1. basic std::thread  
// 2. Varadic Template to take mutiple arguments and different type.
// 3. type deduction : auto , decltype
// 4. std::future to retrive data from asynchronous
// 5. std::mutex to prevent the shared variable become mutable
// 6. Condition_variable to control workflow of thread
// 7. std::forward or std::move
// 8. lambda expression

// In thread pool, 
// 1. std::vector<std::thread> mThreads		   -- execute the threads
// 2. std::queue<std::function<void()>> mTasks -- the task queue, emplace it to thread pool and pop out
// 3. std::mutex mThreadMutex				   -- prevent shared variable overwrite
// 4. std::condition_variable mCondition       -- block the thread until notify to wake up the thread
// 5. bool mFinished					       -- abort thread pool while true

// Simple thread pool
// Reference : https://www.youtube.com/watch?v=eWTGtp3HXiw
class ThreadPool {
private:
	std::vector<std::thread> mThreads;
	std::mutex mThreadMutex;
	std::condition_variable mCondition;
	std::queue<std::function<void()>> mTasks;
	bool mFinished = false;

public:

	ThreadPool(size_t numThread) { start(numThread); }
	~ThreadPool() { stop(); }

	// enqueue the task by wrapping the packaged_task
	template<typename T>
	auto enqueue(T task) -> std::future<decltype(task())>
	{
		auto wrapper = std::make_shared<std::packaged_task<decltype(task()) () >>(std::move(task));
		{
			// mutex lock
			std::unique_lock<std::mutex> lock{ mThreadMutex };
			// collect all value and overload function call
			mTasks.emplace([=] {
				(*wrapper) ();
				});
		}
		// awake
		mCondition.notify_one();
		return wrapper->get_future();

	}
	
	void start(size_t numThread) 
	{
		for (size_t i = 0;i < numThread;i++)
		{
			mThreads.emplace_back([=] {
				add_task();
			});
		}
	}

	void add_task() 
	{
		while(true) 
		{
			std::function<void()> task;
			{
				std::unique_lock<std::mutex> lock{ mThreadMutex };
				// wait for task
				mCondition.wait(lock, [=] {return mFinished || !mTasks.empty();});

				if (mTasks.empty() && mFinished) 
					break;
				task = std::move(mTasks.front());
				mTasks.pop();
			}
			task();
		}
	}
	
	void stop() 
	{
		{
			std::unique_lock<std::mutex> lock{ mThreadMutex };
			mFinished = true;
		}

		// awake all task and finish it
		mCondition.notify_all();
		for (auto& thread : mThreads)
			thread.join();
	}
};


// Mutiple arguments
class ThreadPool2 {
public:
	ThreadPool2(size_t numThread) {
		start(numThread);
	}
	~ThreadPool2() {
		stop();
	}

	template <typename T, typename... Args>
	auto enqueue(T t, Args... args) ->std::future<decltype(std::declval<T>()(std::declval<Args>()...))> {

		using return_type = decltype(std::declval<T>()(std::declval<Args>()...));

		auto wrapper = std::make_shared<std::packaged_task<return_type()>>(
			std::bind(std::forward<T>(t), std::forward<Args>(args)...)
			);
		
		{
			std::unique_lock <std::mutex> loc{ mThreadMutex };
			mTasks.emplace([=] {
				(*wrapper)();
				});
		}
		mCondition.notify_one();
		return wrapper->get_future();
	}

private:
	std::vector<std::thread> mThreads;
	std::mutex mThreadMutex;
	std::queue<std::function<void()>> mTasks;
	std::condition_variable mCondition;
	bool mFinished = false;

	void start(size_t numThread) {
		for (size_t i = 0; i < numThread;i++) {
			mThreads.emplace_back([=] {
				while (true) {
					std::function<void()> task;
					{
						std::unique_lock<std::mutex> lock{ mThreadMutex };
						mCondition.wait(lock, [=] { return mFinished || !mTasks.empty();});

						if (mFinished && mTasks.empty())
							break;

						task = std::move(mTasks.front());
						mTasks.pop();
					}
					task();
				}
			});
		}
	}

	void stop() {
		{
			std::unique_lock<std::mutex> lock{ mThreadMutex };
			mFinished = true;
		}
		
		mCondition.notify_all();
		for (auto& thread : mThreads)
			thread.join();
	}
};


const int mutiply(int x) {
	return x *= x;
}

void mutiply_output(int& n1, int&& n2, const int&& n3) {
	n1 = n2 * n3;
	std::cout << "\nMutiply output : " << n1 << std::endl;
}

int main() {

	{
		ThreadPool2 pool{ 36 };
		for (auto i = 0;i < 50;i++) {
			if (i % 10 == 0 && i != 0) std::cout << std::endl;
			auto f1 = pool.enqueue([=] {
				return mutiply(i);
				});
			std::cout << f1.get() << " ";
		}

		int r;
		// Able to run by lambda 
		auto f2 = pool.enqueue([&r] {
			mutiply_output(std::ref(r), 5, 6);
			});
		
		int& t = r;
		// function can't convert argument n from 'type 1' to 'type 2'
		auto f3 = pool.enqueue(mutiply_output, std::ref(t), 3, 4);
	}


	return 0;
}