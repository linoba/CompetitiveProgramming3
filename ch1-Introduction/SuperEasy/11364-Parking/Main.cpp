#include <iostream>
#include <cstdlib>
#include <cmath>
// g++ Main.cpp -lm -lcrypt -O2 -std=c++11

int main( int argc, const char* argv[]) {
	int t = 0;
	std::cin >> t;
	int pos_min=0, pos_max=0;
	for (int i=0; i<t; i++) {
		int n = 0;
		std::cin >> n;
		for (int k=0; k<n; k++) {
			int pos = 0;
			std::cin >> pos;
			if (k==0) {
				pos_min = pos;
				pos_max = pos;
			} else {
				pos_min = std::min(pos_min, pos);
				pos_max = std::max(pos_max, pos);
			}
		}
		int result = 2 * (pos_max-pos_min);
		std::cout << result << std::endl;
	}
	return 0;
}