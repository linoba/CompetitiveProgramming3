#include <iostream>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <cmath>
// g++ Main.cpp -lm -lcrypt -O2 -std=c++11

int main( int argc, const char* argv[]) {
	int t;
	std::cin >> t;
	for (int i=0; i<t; i++) {
		int n,m;
		std::cin >> n >> m;
		int result = (std::max(1, (int) std::ceil((n-2.0)/3))) * (std::max(1, (int) std::ceil((m-2.0)/3)));
		std::cout << result << std::endl;
	}
	return 0;
}