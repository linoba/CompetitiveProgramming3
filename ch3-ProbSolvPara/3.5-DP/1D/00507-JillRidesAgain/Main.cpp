#include <iostream>
#include <cstdlib>
#include <cstdio>
// g++ Main.cpp -lm -lcrypt -O2 -std=c++11

int main( int argc, const char* argv[]) {
	int n;
	std::cin >> n;
	for (int r=1; r<=n; r++) {
		int s;
		std::cin >> s;
		int data[s-1];
		for (int a=0; a<s-1; a++) {
			std::cin >> data[a];
		}
		int max_value = 0, max_length = 0, max_start = 0;
		int cur_value = 0, cur_length = 0, cur_start = 0;
		for (int a=0; a<s-1; a++) {
			cur_value += data[a];
			if (cur_value < 0) {
				cur_value = 0;
				cur_length = 0;
				cur_start = a+1;
			} else {
				cur_length++;
			}
			if ((cur_value > max_value) || ((cur_value == max_value) && (cur_length > max_length))) {
				max_value = cur_value;
				max_length = cur_length;
				max_start = cur_start;
			}
		}
		if (max_value > 0) {
			std::printf("The nicest part of route %d is between stops %d and %d\n", r, max_start+1, max_start+1+max_length);
		} else {
			std::printf("Route %d has no nice parts\n", r);
		}
	}
	return 0;
}