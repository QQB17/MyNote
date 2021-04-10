#include <iostream>
#include <conio.h> // _kbhit(), _getch()
#include <chrono> // miliseconds
#include <thread> // sleep_for()

// "wsad" to move

class SnakeGame {

private:
	int pos_x, pos_y, fruit_x, fruit_y, num_tails = 0;
	int tail_x[100]{0}, tail_y[100]{0};
	const size_t m_height, m_width;
	int dir_x = 0, dir_y = 0;
	bool b_gameover = false;

public:

	SnakeGame(size_t height, size_t width) : m_height(height),m_width(width)
	{
		srand(time(0));
		pos_x = width / 2;
		pos_y = height / 2;
		fruit_x = rand() % (m_height - 1);
		fruit_y = rand() % (m_width - 1);
	}

	bool c_gameover() {
		return this->b_gameover;
	}

	void draw() 
	{
		std::system("cls");

		for (int x = 0;x <= m_width;x++) 
			std::cout << "# ";

		std::cout << std::endl;

		for (int i = 0;i < m_height; i++) {
			for (int j = 0; j < m_width;j++)
			{
				if (j == 0) std::cout << '#';
				std::cout << ' ';

				if (pos_x == j && pos_y == i)
					std::cout << '*';
				else if (fruit_x == j && fruit_y == i)
					std::cout << '@';
				else if (num_tails > 0) {
					bool print = false;
					for (int k = 0;k < num_tails;k++) {
						if (tail_x[k] == j && tail_y[k] == i) {
							std::cout << '*';
							print = true;
						}
					}
					if (!print) std::cout << ' ';
				}
				else std::cout << ' ';


				if (j == m_width - 1) std::cout << '#';
			}
			std::cout << '\n';
		}
		for (int i = 0;i <= m_width;i++)
			std::cout << "# ";
		std::cout << std::endl;
	}

	void input() 
	{
		if (_kbhit())
		{
			switch (_getch())
			{
			// Prevent move reverse
			case 'w':
				if (dir_y != 1) dir_y = -1; 
				dir_x = 0;
				break;
			case 's':
				if (dir_y != -1) dir_y = 1;
				dir_x = 0;
				break;
			case 'd':
				if (dir_x != -1) dir_x = 1;
				dir_y = 0;
				break;
			case 'a':
				if (dir_x != 1) dir_x = -1;
				dir_y = 0;
				break;
			default:
				break;
			}
		}
	}

	void move() {
		int prev_x = tail_x[0];
		int prev_y = tail_y[0];
		int prev_2x, prev_2y;
		tail_x[0] = pos_x;
		tail_y[0] = pos_y;

		// move forward for previous node
		for (int i = 1; i < num_tails;i++) {
			prev_2x = tail_x[i];
			prev_2y = tail_y[i];
			tail_x[i] = prev_x;
			tail_y[i] = prev_y;
			prev_x = prev_2x;
			prev_y = prev_2y;
		}

		pos_x += dir_x;
		pos_y += dir_y;

		if (pos_x < 0)
			pos_x = m_width - 1;
		else if (pos_x > m_width - 1)
			pos_x = 0;

		if (pos_y < 0)
			pos_y = m_height - 1;
		else if (pos_y > m_height - 1)
			pos_y = 0;

		// If Head is hit the tail, snake was died
		for (int i = 0;i < num_tails;i++)
			if (tail_x[i] == pos_x && tail_y[i] == pos_y)
				b_gameover = true;

		// Generate a fruit after eated
		if (pos_x == fruit_x && pos_y == fruit_y) {
			fruit_x = rand() % (m_height - 1);
			fruit_y = rand() % (m_width - 1);
			num_tails++;
		}

		// Tracking position
		std::cout << "x: " << pos_x << " y: " << pos_y << '\n';
	}

};

int main() {

	SnakeGame snake(25, 25);

	while (!snake.c_gameover()) {
		std::this_thread::sleep_for(std::chrono::milliseconds(200));
		snake.draw();
		snake.input();
		snake.move();
	}

	std::cout << "You're dead.\n";
	
	return 0;
}

// References:
// 1. C++ Snake Game : https://www.instructables.com/C-Snake-Game-Simple/