#include <iostream>
#include <cstdlib>
// g++ Main.cpp -lm -lcrypt -O2 -std=c++11

int main( int argc, const char* argv[]) {
	int t;
	std::cin >> t;
	for (int i=0; i<t; i++) {
		long long a, b;
		std::cin >> a >> b;
		if (a<b) { std::cout << "<" << std::endl; }
		else if (a>b) { std::cout << ">" << std::endl; }
		else { std::cout << "=" << std::endl; }
	}
	return 0;
}