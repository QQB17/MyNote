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
// 3. lambda expression
// 2. std::future to retrive data from asynchronous
// 4. std::mutex to prevent the shared variable become mutable
// 5. Varadic Template to take mutiple arguments and different type.
// 6. Condition_variable to control workflow of thread
// 7. std::forward or std::move

// In thread pool, 
// 1. std::vector<std::thread> mThreads		   -- tracking the threads
// 2. std::queue<std::function<void()>> mTasks -- the task queue, emplace it to pool and pop out
// 3. std::mutex mThreadMutex				   -- prevent shared variable overwrite
// 4. std::condition_variable mCondition       -- block the thread until notify to wake up the thread
// 5. bool mFinished					       -- abort thread pool while true

// Simple thread pool
// Reference : https://www.youtube.com/watch?v=eWTGtp3HXiw
class ThreadPool {
public:
	ThreadPool(size_t numThread){
		start(numThread);
	}
	~ThreadPool() {
		stop();
	}

	template<typename T>
	auto enqueue(T task) -> std::future<decltype(task())>
	{
		auto wrapper = std::make_shared<std::packaged_task<decltype(task()) () >>(std::move(task));
		{
			std::unique_lock<std::mutex> lock{ mEventMutex };
			mTasks.emplace([=] {
				(*wrapper) ();
				});
		}
		mCondition.notify_one();
		return wrapper->get_future();

	}

public:
	std::vector<std::thread> mThreads;
	std::mutex mEventMutex;
	std::condition_variable mCondition;
	std::queue<std::function<void()>> mTasks;
	bool mFinished = false;

	void start(size_t numThread) 
	{
		for (size_t i = 0;i < numThread;i++)
		{
			mThreads.emplace_back([=] {
				while (true)
				{
					std::function<void()> task;
					{
						std::unique_lock<std::mutex> lock{ mEventMutex };
						mCondition.wait(lock, [=] {return mFinished || !mTasks.empty();});

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
	
	void stop() 
	{
		{
			std::unique_lock<std::mutex> lock{ mEventMutex };
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

int main() {

	{
		ThreadPool pool{ 36 };
		for (auto i = 0;i < 36;i++) {
			auto f1 = pool.enqueue([=] {
				return mutiply(i);
				});
			std::cout << f1.get() << " ";
		}
	}
	return 0;
}