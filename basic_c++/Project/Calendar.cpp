#include <iostream>

class Calendar{
public:
	// Using Tomohiko Sakamoto’s Algorithm to Finding the day of the week
	// Function explain: https://stackoverflow.com/questions/6385190/correctness-of-sakamotos-algorithm-to-find-the-day-of-week

	int getPreviousMonthLastLocation(int day,int month,int year)
	{
		int t[] = { 0,3,2,5,0,3,5,1,4,6,2,4 };
		year -= month < 3;
		int n_day = (year + (year / 4) - (year / 100) + (year / 400) + t[month - 1] + day) % 7;
		return n_day;
	}

	std::string getMonthName(int monthNumber) {
		std::string months[] = { "January", "February", "March", "April", "May", "June", "July",
									"Augus", "September", "October", "November", "December" };
		return (months[monthNumber]);
	}

	int numberOfDays(int monthNumber,int year) {
		switch (monthNumber)
		{
		case 0:
		case 2:
		case 4:
		case 6:
		case 7:
		case 9:
		case 11:
			return (31);
			break;
			
		case 1:
			if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
				return (29);
			else
				return (28);
			break;

		case 3:
		case 5:
		case 8:
		case 10:
			return (30);
			break;
		}
	}

	void printYeart(int year)
	{
		std::cout << "Calendar - Year: " << year << '\n';
		int daysOfMonth;
		int currenct = getPreviousMonthLastLocation(1, 1, year);


		for (int i = 0;i < 12;i++) {
			daysOfMonth = numberOfDays(i, year);
			std::cout << " -------- " << getMonthName(i).c_str() << " --------" << '\n';
			std::cout << " Sun Mon Tue Wed Thu Fri Sat\n";
			int k;
			for (k = 0;k < currenct;k++)
				std::cout << "    ";

			for (int j = 1;j <= daysOfMonth;j++) {
				std::cout.width(4);
				std::cout << j;
				if (++k > 6){
					k = 0;
					std::cout << '\n';
				}
			}
			if (k) {
				std::cout << '\n';
				currenct = k;
			}
			std::cout << std::endl;
		}
		return;
	}

	void printMonth(int month,int year) {
		std::cout << "Calendar - Year: " << year << '\n';
		int daysOfMonth = numberOfDays(month - 1, year);
		int cur_day_location = getPreviousMonthLastLocation(1, month, year);

		// minus 1 from user input and make sure it was string object
		std::cout << " -------- " << getMonthName(month-1).c_str() << " --------" << '\n';
		std::cout << " Sun Mon Tue Wed Thu Fri Sat\n";
		int k = 0;
		for (k = 0;k < cur_day_location;k++)
			std::cout << "    ";

		for (int j = 1;j <= daysOfMonth;j++) {
			std::cout.width(4);
			std::cout << j;
			
			if (++k > 6) {
				k = 0;
				std::cout << std::endl;
			}
		}
		std::cout << std::endl;
	}
	
	void start() {
		int m_year, m_month, m_print;

		while (true) 
		{
			std::cout << "Please input a number: \n" 
				<< "[1] for Year Calendar\n"
				<< "[2] for Month Calendar\n"
				<< "[9] for Exit Program\n";
			std::cin >> m_print;

			switch (m_print)
			{
			case 1:
				std::cout << "Enter year with 4 digits: \n";
				std::cin >> m_year;
				printYeart(m_year);
				break;
			case 2:
				std::cout << "Enter year with 4 digits: \n";
				std::cin >> m_year;
				std::cout << "Enter month between 1 ~ 12: \n";
				std::cin >> m_month;
				std::cout << std::endl;
				printMonth(m_month, m_year);
				break;
			case 9:
				exit(0);
			default:
				std::cout << "Wrong number, please try again.\n";
				break;
			}
			std::cout << std::endl;
		}
	}

};

int main() {
	Calendar calendar;
	calendar.start();

	return 0;
}