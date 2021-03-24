#include <iostream>
#include <time.h>


// Please run with IDE, mingw is not support "localtime_s"

long long int fibonacii(int n) {
	long long int a = 0, b = 1, c;
	for(int i =2; i<=n;i++) {
		c = a + b;
		a = b;
		b = c;
	}
	return b;
}

class time_function {
private:
	// types:
	time_t raw_time; // time type
	struct tm timeinfo; // time structure

	char str[100];

public:

	void asctime_Func() {
		// conveter time structure to string by format:
		// Www Mmm dd hh:mm:ss yyy
		// Tue Mar 23 22:25:26 2021
		// format is fixed
		time(&raw_time);
		localtime_s(&timeinfo,&raw_time);
		asctime_s(str, sizeof(str), &timeinfo);
		std::cout << "Asctime function to display date/time: " << str;
		 //std::cout << "Current date/time: " << asctime(&timeinfo); // not thread safe
	}

	void clock_Func() {
		// return process time
		time_t t, res;
		double dur;
		t = clock();
		std::cout << "Fibonacii: " << fibonacii(100) << std::endl;
		res = clock() - t;
		dur = res / (double)CLOCKS_PER_SEC;
		std::cout << "Process time: " << dur << "ms"<< std::endl;
	}

	void ctime_Func() {
		// convert time_t value to string by format:
		// Www Mmm dd hh::mm::ss yyyy
		// same as asctime Function
		ctime_s(str, sizeof(str), &raw_time); // use ctime_s for theard safe
		std::cout << "Ctime function to display date/time: " << str;
	}

	void difftime_Func() {
		// return the difference in seconds between two times
		double seconds;
		struct tm newyear;

		time(&raw_time);
		localtime_s(&newyear, &raw_time);
		newyear.tm_sec = 10;
		seconds = difftime(raw_time, mktime(&newyear));
		std::cout << "Difference between two time with seconds: " << seconds << std::endl;
	}

	void gmtime_Func() {
		// convert time_t to tm as UTC time
		enum { MST = (-7), UTC = (0), CCT = (+8) };
		time(&raw_time);
		gmtime_s(&timeinfo, &raw_time);
		std::cout << "Coordinated Universal Time: " << (timeinfo.tm_hour + UTC) << ":" << timeinfo.tm_min;
		std::cout << "\tSingapore time: " << (timeinfo.tm_hour + CCT) % 24 << ":" << timeinfo.tm_min;
		std::cout << "\tU.S time: " << (timeinfo.tm_hour + MST) % 24 << ":" << timeinfo.tm_min << std::endl;
	}

	void mktime_Func() {
		// convert tm structure to time_t
		int year, month, day;
		tm* t_ptr = nullptr;
		
		const char* weekday[] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };
		std::cout << "Enter year: ";
		std::cin >> year;
		std::cout << "Enter month: ";
		std::cin >> month;
		std::cout << "Enter day: ";
		std::cin >> day;

		time(&raw_time);

		localtime_s(&timeinfo, &raw_time);
		timeinfo.tm_year = year- 1900;
		timeinfo.tm_mon = month - 1;
		timeinfo.tm_mday = day;

		if ( mktime(&timeinfo) == (time_t)-1) 
			std::cout << "mktime failed.\n";
		else 
			std::cout << "That day is: " << weekday[timeinfo.tm_wday] << std::endl;
	}

	void strftime_Func() {
		// format time as string
		// more format http://www.cplusplus.com/reference/ctime/strftime/
		time(&raw_time);
		localtime_s(&timeinfo, &raw_time);

		strftime(str, sizeof(str), "Now it's %I:%M%p.", &timeinfo);
		std::cout << str << std::endl;
	}
};

int main() {
	time_function t;
	t.asctime_Func();
	t.ctime_Func();
	t.clock_Func();
	t.difftime_Func();
	t.gmtime_Func();
	t.strftime_Func();
	t.mktime_Func();
	
}