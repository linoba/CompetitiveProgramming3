#include <iostream>
#include <cstdlib>
#include <string>
// g++ Main.cpp -lm -lcrypt -O2 -std=c++11

const int dirsize = 6;
const std::string dirs[dirsize] = { "+x", "-x", "+y", "-y", "+z", "-z"};

const int matrix[6][4] = {
	{2, 3, 4, 5},
	{3, 2, 5, 4},
	{1, 0, 2, 2},
	{0, 1, 3, 3},
	{4, 4, 1, 0},
	{5, 5, 0, 1},
};

int getValue(std::string line) {
	for (int i=0; i<dirsize; i++) {
		if (line == dirs[i]) { return i; }
	}
	return -1;
}

int main( int argc, const char* argv[]) {
	int n;
	std::cin >> n;
	while (n!=0) {
		int cur=0;
		//std::cout << "n " << n << std::endl;
		for (int i=0; i<n-1; i++) {
			std::string line;
			std::cin >> line;
			int value = getValue(line);
			if (value!=-1) {
				cur = matrix[cur][value-2];
			}
			//std::cout << line << ", value " << value << ", cur " << cur << std::endl;
		}
		std::cout << dirs[cur] << std::endl;
		//std::cout << std::endl;
		std::cin >> n;
	}
	return 0;
}