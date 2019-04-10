#include <iostream>
#include <cstdlib>
#include <string>
// g++ Main.cpp -lm -lcrypt -O2 -std=c++11

int main( int argc, const char* argv[]) {
	int N, M;
	int test_case = 0;
	while (std::cin >> N) {
		if (test_case > 0) { std::cout << std::endl; }
		std::cin >> M;
		short data[N][N];
		int res_size = N-M+1;
		int result[res_size][res_size];
		long long total_sum = 0;
		for (int i=0; i<N; i++) {
			for (int k=0; k<N; k++) {
				std::cin >> data[i][k];
				if (i>0) { data[i][k] += data[i-1][k]; }
				if (k>0) { data[i][k] += data[i][k-1]; }
				if (i>0 && k>0) { data[i][k] -= data[i-1][k-1]; }
			}
		}
		for (int i=0; i<res_size; i++) {
			for (int k=0; k<res_size; k++) {
				int cur_sum = data[i+M-1][k+M-1];
				if (i>0) { cur_sum -= data[i-1][k+M-1]; }
				if (k>0) { cur_sum -= data[i+M-1][k-1]; }
				if (i>0 && k>0) { cur_sum += data[i-1][k-1]; }
				result[i][k] = cur_sum;
				total_sum += cur_sum;
				std::cout << cur_sum << std::endl;
			}
		}
		std::cout << total_sum << std::endl;
		test_case++;
	}
	return 0;
}