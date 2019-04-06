#include <iostream>
#include <cstdlib>
#include <cmath>
// g++ Main.cpp -lm -lcrypt -O2 -std=c++11

int main( int argc, const char* argv[]) {
	int N;
	std::cin >> N;
	while (N != 0) {
		int max_streak = -1;
		int cur_streak = -1;
		for (int i=0; i<N; i++) {
			int value;
			std::cin >> value;
			cur_streak += value;
			if (value > cur_streak) {
				cur_streak = value;
			}
			max_streak = std::max(max_streak, cur_streak);
		}
		if (max_streak>0) {
			std::cout << "The maximum winning streak is " << max_streak << "." << std::endl;
		} else {
			std::cout << "Losing streak." << std::endl;
		}
		std::cin >> N;
	}
	return 0;
}