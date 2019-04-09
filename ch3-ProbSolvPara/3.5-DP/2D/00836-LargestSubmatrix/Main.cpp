#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <cmath>
// g++ Main.cpp -lm -lcrypt -O2 -std=c++11

const int LARGE_NEG = -30*30;

int main( int argc, const char* argv[]) {
	int t;
	std::cin >> t;
	std::string cur_line;
	std::getline(std::cin, cur_line);
	std::getline(std::cin, cur_line);
	for (int test_case=0; test_case<t; test_case++) {
		int N = 0;
		//std::getline(std::cin, cur_line); // blank line
		std::vector<std::vector<bool>> data_bool;
		std::vector<std::vector<int>> data_sum;
		while (std::getline(std::cin, cur_line) && !cur_line.empty()) {
			std::vector<bool> cur_bool;
			std::vector<int> cur_int;
			if (N==0) {
				N = cur_line.size();
				//std::cout << "N = " << N << std::endl;
				cur_bool = std::vector<bool>(N+1, false);
				cur_int = std::vector<int>(N+1, LARGE_NEG);
				data_bool.push_back(cur_bool);
				data_sum.push_back(cur_int);
				cur_bool.clear();
				cur_int.clear();
			}
			for (int i=-1; i<N; i++) {
				if (i==-1) {
					cur_bool.push_back(false);
					cur_int.push_back(LARGE_NEG);
				} else {
					if (cur_line.at(i)=='1') {
						cur_bool.push_back(true);
						cur_int.push_back(1);
					} else {
						cur_bool.push_back(false);
						cur_int.push_back(LARGE_NEG);
					}
				}
			}
			data_bool.push_back(cur_bool);
			data_sum.push_back(cur_int);
		}
		for (int x=0; x<data_sum.size(); x++) {
			for (int y=0; y<data_sum[x].size(); y++) {
				if (x>0) { data_sum[x][y] += data_sum[x-1][y]; }
				if (y>0) { data_sum[x][y] += data_sum[x][y-1]; }
				if (x>0 && y>0) { data_sum[x][y] -= data_sum[x-1][y-1]; }
			}
		}
		int result = 0;
		for (int x=0; x<data_sum.size(); x++) {
			//std::cout << std::endl;
			for (int y=0; y<data_sum[x].size(); y++) {
				//std::cout << data_sum[x][y] << " ";
				for (int x_end=x; x_end<data_sum.size(); x_end++) {
					for (int y_end=y; y_end<data_sum[x].size(); y_end++) {
						int cur = 0;
						if (x==x_end && y==y_end) { 
							cur = data_bool[x][y];
						} else if (x==x_end) {
							int cur_diff = data_sum[x][y_end] - data_sum[x][y] + data_bool[x][y];
							if ((y_end-y+1) == cur_diff) {
								cur = cur_diff;
							} 
						} else if (y==y_end) {
							int cur_diff = data_sum[x_end][y] - data_sum[x][y] + data_bool[x][y];
							if ((x_end-x+1) == cur_diff) {
								cur = cur_diff;
							}
						} else {
							int cur_diff = data_sum[x_end][y_end];
							if (y>0) { cur_diff -= data_sum[x_end][y-1]; }
							if (x>0) { cur_diff -= data_sum[x-1][y_end]; }
							if (x>0 && y>0) { cur_diff += data_sum[x-1][y-1]; }
							if ((x_end-x+1)*(y_end-y+1) == cur_diff) {
								cur = cur_diff;
							}
						}
						result = std::max(result, cur); 
					}
				}
			}
		}
		std::cout << result << std::endl;
		if (test_case+1 < t) {
			std::cout << std::endl;
		}
	}
	return 0;
}