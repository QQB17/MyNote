#include <thread>
#include <iostream>

bool finished = false; 

void send(char* c) {
	std::cout << "Start sending...\n";
	while (!finished) {
		std::cout << "\nSend: ";
		std::cin.getline(c,512);
		
		if(strcmp(c, "exit") == 0) {
			finished = true;
		}
	}
	std::cout << "Closing send.\n";
}

void recv(char* c) {
	std::cout << "Start receive...\n";
	while (!finished) {
		if (strlen(c) != NULL) {
			std::cout << "Recv: " << c << std::endl;
			std::this_thread::sleep_for(std::chrono::microseconds(100));
			memset(c, 0, sizeof(c));
		}
	}
	std::cout << "Closing recv.\n";
}

int main() {
	char c[512] = "Welcome"; // share variable

	std::thread t1(send, c);
	std::thread t2(recv, c);
	
	std::cout << "Thread send id: " << t1.get_id() << std::endl; 
	std::cout << "Thread recv id: " << t2.get_id() << std::endl;

	std::cout << "Number of Hardware Concurrency: " << t1.hardware_concurrency() << " " << 
		t2.hardware_concurrency() << std::endl;

	// synchronize threads;
	t1.join();
	t2.join();

	return 0;
	
}