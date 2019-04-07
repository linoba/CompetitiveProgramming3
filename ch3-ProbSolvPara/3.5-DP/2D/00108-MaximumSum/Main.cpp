#include <iostream>
#include <cstdlib>
#include <cmath>
// g++ Main.cpp -lm -lcrypt -O2 -std=c++11

int main( int argc, const char* argv[]) {
	int n;
	std::cin >> n;
	int data[n][n];
	for (int x=0; x<n; x++) {
		for (int y=0; y<n; y++) {
			std::cin >> data[x][y];
			if (x>0) { data[x][y] += data[x-1][y]; }
			if (y>0) { data[x][y] += data[x][y-1]; }
			if (x>0 && y>0) { data[x][y] -= data[x-1][y-1]; }
		}
	}
	int cur_sum, max_sum;
	for (int x=0; x<n; x++) {
		for (int y=0; y<n; y++) {
			for (int x_end=x; x_end<n; x_end++) {
				for (int y_end=y; y_end<n; y_end++) {
					cur_sum = data[x_end][y_end];
					if (x_end==0 && y_end==0) { max_sum = cur_sum;}
					if (x>0) { cur_sum -= data[x-1][y_end]; }
					if (y>0) { cur_sum -= data[x_end][y-1]; }
					if (x>0 && y>0) { cur_sum += data[x-1][y-1]; }
					max_sum = std::max(max_sum, cur_sum);
				}
			}
		}
	}
	std::cout << max_sum << std::endl;
	return 0;
}