#include <iostream>
#include <vector>
#include <cstdlib>
#include <set>
#include <cmath>
// g++ Main.cpp -lm -lcrypt -O2 -std=c++11

int main( int argc, const char* argv[]) {
	int n;
	std::cin >> n;
	while (std::cin){
		if (n==1) {
			std::cout << "Jolly" << std::endl;
			int blank;
			std::cin >> blank;
		} else {
			std::set<int> set_jolly;
			int data[n];
			for(int i=0; i<n; i++) {
				std::cin >> data[i];
				if (i>0) {
					set_jolly.insert(std::abs(data[i]-data[i-1]));
				}
			}
			if (set_jolly.size() != n-1 ||
				(*set_jolly.begin() != 1) ||
				(*set_jolly.rbegin() != n-1) ) {
				std::cout << "Not jolly" << std::endl;
			} else {
				std::cout << "Jolly" << std::endl;
			}
		}
		std::cin >> n;
	}
	return 0;
}