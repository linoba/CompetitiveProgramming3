#include <iostream>
#include <cstdlib>
#include <string>
// g++ Main.cpp -lm -lcrypt -O2 -std=c++11

int main( int argc, const char* argv[]) {
	int n, p;
	std::cin >> n >> p;
	int test_case = 0;
	while (n!=0 && p!=0) {
		std::string name, best_name;
		double price, best_price;
		int req, best_req;
		std::getline(std::cin, name); // line break
		for (int i=0; i<n; i++) { 
			std::getline(std::cin, name); 
		}
		for (int i=0; i<p; i++) { 
			std::getline(std::cin, name); 
			std::cin >> price;
			std::cin >> req;
			if (i==0 || (req > best_req)) {
				best_req = req;
				best_price = price;
				best_name = name;
			} else if ((req == best_req) && (price<best_price)) {
				best_price = price;
				best_name = name;
			}
			std::getline(std::cin, name); // line break
			for (int i=0; i<req; i++) { std::getline(std::cin, name); }
		}
		if (test_case > 0) {
			std::cout << std::endl;
		}
		std::cout << "RFP #" << (test_case+1) << std::endl;
		std::cout << best_name << std::endl;
		test_case++;
		std::cin >> n >> p;
	}

	return 0;
}