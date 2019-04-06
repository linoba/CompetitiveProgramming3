#include <iostream>
#include <cstdlib>
#include <cmath>
// g++ Main.cpp -lm -lcrypt -O2 -std=c++11

int main( int argc, const char* argv[]) {
	int t;
	std::cin >> t;
	for (int i=0; i<t; i++) {
		int n;
		std::cin >> n;
		double n_double = (double) n;
		n_double = n_double*1.0*567/9 + 7492;
		n_double = n_double * 235 / 47 - 498;
		n_double = n_double / 10;
		n = (int) n_double;
		int result = std::abs(n % 10);
		std::cout << result << std::endl;
	}
	return 0;
}