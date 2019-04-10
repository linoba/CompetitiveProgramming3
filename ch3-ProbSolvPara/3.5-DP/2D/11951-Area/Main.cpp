#include <iostream>
#include <cstdlib>
#include <cmath>
// g++ Main.cpp -lm -lcrypt -O2 -std=c++11

int main( int argc, const char* argv[]) {
	int T, N, M;
	long long K;
	std::cin >> T;
	for (int test_case=0; test_case<T; test_case++) {
		std::cin >> N >> M;
		std::cin >> K;
		long long data[N][M];
		long long total_cost = 0;
		int max_size = 0;
		for (int i=0; i<N; i++) {
			for (int k=0; k<M; k++) {
				long long price;
				std::cin >> price;
				if (price <= K) {
					max_size = 1;
					total_cost = std::min(total_cost, price);
				}
				data[i][k] = price;
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
						long long cur_price = data[i_end][k_end];
						if (i>0) { cur_price -= data[i-1][k_end]; }
						if (k>0) { cur_price -= data[i_end][k-1]; }
						if (i>0 && k>0) { cur_price += data[i-1][k-1]; }
						if (cur_price <= K) {
							int cur_size = (i_end-i+1) * (k_end-k+1);
							if (cur_size > max_size) {
								max_size = cur_size;
								total_cost = cur_price;
							} else if (cur_size == max_size) {
								total_cost = std::min(total_cost, cur_price);
							}
						}
					}
				}
			}
		}
		std::cout << "Case #" << test_case+1 << ": " << max_size << " " << total_cost << std::endl;
	}
	return 0;
}