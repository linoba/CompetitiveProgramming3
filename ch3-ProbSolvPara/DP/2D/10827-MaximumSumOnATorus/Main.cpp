#include <iostream>
#include <cstdlib>
#include <cmath>
// g++ Main.cpp -lm -lcrypt -O2 -std=c++11

int main( int argc, const char* argv[]) {
	int T, N;
	std::cin >> T;
	for (int test_case=0; test_case<T; test_case++) {
		std::cin >> N;
		int data[N+N][N+N];
		int max_sum = 0;
		for (int i=0; i<N; i++) {
			for (int k=0; k<N; k++) {
				int cur_value;
				std::cin >> cur_value;
				data[i][k] = cur_value;
				data[i+N][k] = cur_value;
				data[i][k+N] = cur_value;
				data[i+N][k+N] = cur_value;
				max_sum = std::max(max_sum, cur_value);
			}
		}
		for (int i=0; i<N+N; i++) {
			for (int k=0; k<N+N; k++) {
				if (i>0) { data[i][k] += data[i-1][k]; }
				if (k>0) { data[i][k] += data[i][k-1]; }
				if (i>0 && k>0) { data[i][k] -= data[i-1][k-1]; }
			}
		}
		for (int i=0; i<N+N; i++) {
			for (int k=0; k<N+N; k++) {
				for (int i_end=i; i_end<N+N; i_end++) {
					if (i_end-i+1 > N) { break; }
					for (int k_end=k; k_end<N+N; k_end++) {
						if (k_end-k+1 > N) { break; }
						if (i_end==i && k_end==k) { continue; }
						int cur_sum = data[i_end][k_end];
						if (i>0) { cur_sum -= data[i-1][k_end]; }
						if (k>0) { cur_sum -= data[i_end][k-1]; }
						if (i>0 && k>0) { cur_sum += data[i-1][k-1]; }
						max_sum = std::max(max_sum, cur_sum);
					}
				}
			}
		}
		std::cout << max_sum << std::endl;
	}
	return 0;
}