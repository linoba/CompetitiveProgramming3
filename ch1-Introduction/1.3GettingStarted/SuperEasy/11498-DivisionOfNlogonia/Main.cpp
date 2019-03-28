#include <iostream>
#include <cstdlib>
// g++ Main.cpp -lm -lcrypt -O2 -std=c++11

int main( int argc, const char* argv[]) {
	int k;
	while (true) {
		std::cin >> k;
		if (k==0) {
			return 0;
		}
		int n=0, m=0;
		for (int i=0; i<=k; i++) {
			if (i==0) {
				std::cin >> n >> m;
			} else {
				int x, y;
				std::cin >> x >> y;
				if (x==n || y==m) {
					std::cout << "divisa" << std::endl;
				} else if (x < n && y < m) {
					std::cout << "SO" << std::endl;
				} else if (x < n && y > m) {
					std::cout << "NO" << std::endl;
				} else if (x > n && y > m) {
					std::cout << "NE" << std::endl;
				} else {
					std::cout << "SE" << std::endl;
				}
			}
		}
	}
	return 0;
}