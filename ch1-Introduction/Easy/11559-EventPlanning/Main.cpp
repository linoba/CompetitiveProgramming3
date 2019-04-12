#include <iostream>
#include <cstdlib>
#include <cmath>
// g++ Main.cpp -lm -lcrypt -O2 -std=c++11

int main( int argc, const char* argv[]) {
	int test_case = 0;
	int N, B, H, W;
	while (std::cin >> N) {
		std::cin >> B >> H >> W;
		if (H==0 || W==0) {
			std::cout << "stay home" << std::endl;
			test_case++;
			continue;
		}
		//std::cout << "N " << N << ", B " << B << ", H " << H << ", W " << W << std::endl;
		int price, best_price;
		int beds;
		bool flag_possible = false;
		for (int i=0; i<H; i++) {
			std::cin >> price;
			for (int week=0; week<W; week++) {
				std::cin >> beds; 
				if ((beds>=N) && (price*N<=B)) {
					if (!flag_possible) {
						flag_possible = true;
						best_price = price;
					} 
					best_price = std::min(best_price, price);
				}
			}
		}
		if (flag_possible) {
			std::cout << int (best_price*N) << std::endl;
		} else {
			std::cout << "stay home" << std::endl;
		}
		test_case++;
	}
	return 0;
}