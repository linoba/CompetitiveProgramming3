#include <iostream>
#include <vector>
#include <cstdlib>
#include <set>
#include <cmath>
// g++ Main.cpp -lm -lcrypt -O2 -std=c++11

int main( int argc, const char* argv[]) {
	int n;
	std::cin >> n;
	while (std::cin){
		int num_elements = 1 << n;
		int data[num_elements];
		int potency[num_elements];
		for(int i=0; i<num_elements; i++) {
			std::cin >> data[i];
		}

		for (int i=0; i<num_elements; i++) {
			int cur_sum = 0;
			for (int k=0; k<n; k++) {
				int cur_index = i ^ (1 << k);
				cur_sum += data[cur_index];
			}
			potency[i] = cur_sum;
		}
		
		int max_potency = 0;
		for (int i=0; i<num_elements; i++) {
			for (int k=0; k<n; k++) {
				int cur_index = i ^ (1 << k);
				int cur_sum = potency[i] + potency[cur_index];
				max_potency = std::max(max_potency, cur_sum);
			}
		}
		std::cout << max_potency << std::endl;
		std::cin >> n;
	}
	return 0;
}