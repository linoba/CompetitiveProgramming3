#include <iostream>
#include <cstdlib>
#include <cmath>
// g++ Main.cpp -lm -lcrypt -O2 -std=c++11

const int LARGE_NEG = -110*110;
int main( int argc, const char* argv[]) {
	int N, M;
	std::cin >> N >> M;
	while (N!=0 && M!=0) {
		int data[N][M];
		int max_sum = 0;		
		for (int i=0; i<N; i++) {
			for (int k=0; k<M; k++) {
				bool cur_value;
				std::cin >> cur_value;
				if (cur_value) { 
					data[i][k] = LARGE_NEG; 
				}
				else { 
					data[i][k] = 1; 
					max_sum = 1;
				}
				if (i>0) { data[i][k] += data[i-1][k]; }
				if (k>0) { data[i][k] += data[i][k-1]; }
				if (i>0 && k>0) { data[i][k] -= data[i-1][k-1]; }
			}
		}
		for (int i=0; i<N; i++) {
			for (int k=0; k<M; k++) {
				for (int i_end=i; i_end<N; i_end++) {
					for (int k_end=k; k_end<M; k_end++) {
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
		std::cin >> N >> M;
		//std::cout << "N " << N << ", M " << M << std::endl;
	}
	return 0;
}