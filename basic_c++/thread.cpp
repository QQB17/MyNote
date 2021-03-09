#include <thread>
#include <iostream>
#include <mutex>

char c[512]; // share variable
bool finished = false;
std::mutex m;
int count = 0;

void send() {
	std::cout << "Start sending...\n";
	std::this_thread::sleep_for(std::chrono::milliseconds(100));
	while (!finished) {
		std::cout << "\nSend: ";
		std::cin.getline(c,512);
		
		if(strcmp(c, "exit") == 0) {
			finished = true;
		}
	}
	std::cout << "Closing send.\n";
}

void recv() {
	std::cout << "Start receive...\n";
	while (!finished) {
		if (strlen(c) != NULL) {
			std::cout << "Recv: " << c << std::endl;
			memset(c, 0, sizeof(c));
		}
	}
	std::cout << "Closing recv.\n";
}

void jobMutex() {
	// mutex can prevent synchronization problem between two thread when the variable was shared in thread.
	m.lock(); // lock current thread
	count += 1;
	std::cout << "Job " << count << " started." << std::endl;
	std::cout << "Job " << count << " finished." << std::endl;
	m.unlock(); // unlock current threads
}


int main() {
	//std::thread t1(send);
	//std::thread t2(recv);

	//std::cout << "Thread send id: " << t1.get_id() << std::endl; 
	//std::cout << "Thread recv id: " << t2.get_id() << std::endl;

	//std::cout << "Number of Hardware Concurrency: " << t1.hardware_concurrency() << " " << t2.hardware_concurrency() << std::endl;

	//// synchronize threads;
	//t1.join();
	//t2.join();

	std::thread t3(jobMutex), t4(jobMutex);
	t3.join(), t4.join();


	return 0;
}