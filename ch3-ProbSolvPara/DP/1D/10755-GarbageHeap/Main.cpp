#include <iostream>
#include <cstdlib>
#include <cmath>
// g++ Main.cpp -lm -lcrypt -O2 -std=c++11

int main( int argc, const char* argv[]) {
	int t;
	std::cin >> t;
	for (int test_case=0; test_case<t; test_case++) {
		int a,b,c;
		std::cin >> a >> b >> c;
		long long data[a][b][c];
		for (int x=0; x<a; x++) {
			for (int y=0; y<b; y++) {
				for (int z=0; z<c; z++) {
					std::cin >> data[x][y][z];
				}
			}
		}
		for (int x=0; x<a; x++) {
			for (int y=0; y<b; y++) {
				for (int z=0; z<c; z++) {
					if (z>0) {
						data[x][y][z] += data[x][y][z-1];
					}
					if (y>0) {
						data[x][y][z] += data[x][y-1][z];
					}
					if (z>0 && y>0) {
						data[x][y][z] -= data[x][y-1][z-1];
					}
				}
			}
		}
		long long cur_sum = 0, max_sum = 0;
		for (int x=0; x<a; x++) {
			/* (Actually, if all smaller parallelepiped
			has value less than the original one, the farmer will leave the original parallelepiped).
			*/
			max_sum += data[x][b-1][c-1]; 
		}
		for (int x=0; x<a; x++) {
			for (int y=0; y<b; y++) {
				for (int z=0; z<c; z++) {
					//
					for (int y_end=y; y_end<b; y_end++) {
						for (int z_end=z; z_end<c; z_end++) {
							for (int x_end=x; x_end<a; x_end++) {
								if (x_end == x) {
									cur_sum = 0;
								}
								cur_sum += data[x_end][y_end][z_end];
								if (y>0) {
									cur_sum -= data[x_end][y-1][z_end];
								}
								if (z>0) {
									cur_sum -= data[x_end][y_end][z-1];
								}
								if (y>0 && z>0) {
									cur_sum += data[x_end][y-1][z-1];
								}
								max_sum = std::max(max_sum, cur_sum);
							}
							cur_sum = 0;
						}
					}
				}
			}
		}
		std::cout << max_sum << std::endl;
		if (test_case+1 < t) {
			std::cout << std::endl; // Print a blank line between test cases.
		}
	}

	return 0;
}