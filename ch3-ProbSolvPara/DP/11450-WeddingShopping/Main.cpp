#include <iostream>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <cstdio>
// g++ Main.cpp -lm -lcrypt -O2 -std=c++11

int M, C, price[22][22];
int memo[202][22];

int shop(int money, int g) {
	if (money < 0) { 
		return -1000000;
	}
	if (g == C) {
		return M - money;
	}
	if (memo[money][g] != -1) {
		return memo[money][g];
	}
	int result = -1;
	for (int model=1; model<=price[g][0]; model++) {
		result = std::max(result, shop(money-price[g][model], g+1));
	}
	memo[money][g] = result;
	return result;
}

int main( int argc, const char* argv[]) {
	int n;
	std::cin >> n;
	for (int i=0; i<n; i++) {
		// test case
		std::cin >> M >> C;
		for (int k=0; k<C; k++) { 
			// models
			std::cin >> price[k][0];
			for (int l=1; l<=price[k][0]; l++) {
				// garment
				std::cin >> price[k][l];
			}
		}
		memset(memo, -1, sizeof memo);
		int result = shop(M, 0);
		if (result < 0) { 
			std::cout << "no solution" << std::endl; 
		} else {
			std::cout << result << std::endl;
		}
	}
	return 0;
}