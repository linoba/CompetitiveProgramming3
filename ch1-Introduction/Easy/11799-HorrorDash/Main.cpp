#include <iostream>
#include <cstdlib>
#include <cmath>
// g++ Main.cpp -lm -lcrypt -O2 -std=c++11

int main( int argc, const char* argv[]) {
	int T, N;
	std::cin >> T;
	for (int i=0; i<T; i++) {
		std::cin >> N;
		int max_speed=0, speed;
		for (int k=0; k<N; k++) {
			int speed; 
			std::cin >> speed;
			max_speed = std::max(max_speed, speed);
		}
		std::cout << "Case " << (i+1) << ": " << max_speed << std::endl;
	}
	return 0;
}