#include <iostream>
#include <cstdlib>
#include <cmath>
// g++ Main.cpp -lm -lcrypt -O2 -std=c++11

const int LARGE_NEG = -110*110;
int main( int argc, const char* argv[]) {
	int P, N, B;
	std::cin >> P;
	for (int test_case=0; test_case<P; test_case++) {
		std::cin >> N >> B;
		int data[N][N];
		for (int i=0; i<N; i++) {
			for (int k=0; k<N; k++) {
				data[i][k] = 1;
			}
		}
		for (int i=0; i<B; i++) {
			int x1, y1, x2, y2;
			std::cin >> x1 >> y1 >> x2 >> y2;
			for (int x=x1-1; x<x2; x++) {
				for (int y=y1-1; y<y2; y++) {
					data[x][y] = LARGE_NEG;
				}
			}
		}
		int max_sum = 0;
		for (int i=0; i<N; i++) {
			for (int k=0; k<N; k++) {
				if (data[i][k] == 1) { max_sum = 1; }
				if (i>0) { data[i][k] += data[i-1][k]; }
				if (k>0) { data[i][k] += data[i][k-1]; }
				if (i>0 && k>0) { data[i][k] -= data[i-1][k-1]; }
			}
		}
		for (int i=0; i<N; i++) {
			for (int k=0; k<N; k++) {
				for (int i_end=i; i_end<N; i_end++) {
					for (int k_end=k; k_end<N; k_end++) {
						if (i_end==i && k_end==k) { continue; }
						int cur_sum = data[i_end][k_end];
						if (i>0) { cur_sum -= data[i-1][k_end]; }
						if (k>0) { cur_sum -= data[i_end][k-1]; }
						if (i>0 && k>0) { cur_sum += data[i-1][k-1]; }
						if (cur_sum == ((i_end-i+1)*(k_end-k+1))) {
							max_sum = std::max(max_sum, cur_sum);
						}
					}
				}
			}
		}
		std::cout << max_sum << std::endl;
	}

	return 0;
}