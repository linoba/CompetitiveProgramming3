#include <iostream>
#include <cstdlib>
#include <string>
// g++ Main.cpp -lm -lcrypt -O2 -std=c++11

int main( int argc, const char* argv[]) {
	std::string lineInput;
	int a, b, c, d;
	while (std::cin >> a) {
		std::cin >> b;
		std::cin >> c;
		std::cin >> d;
		if (a == b && b == c && c == d && d == 0) {
			return 0;
		}
		int result = 3*360;
		result += ((a - b + 40) % 40) * 9;
		result += ((c - b + 40) % 40) * 9;
		result += ((c - d + 40) % 40) * 9;
		std::cout << result << std::endl;
	}
	return 0;
}