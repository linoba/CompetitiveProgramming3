#include <iostream>
#include <cstdlib>
// g++ Main.cpp -lm -lcrypt -O2 -std=c++11

int main( int argc, const char* argv[]) {
	int loan_duration;
	double down_payment;
	double loan_amount;
	int num_records;
	double owing, value;
	while (true) {
		std::cin >> loan_duration >> down_payment >> loan_amount >> num_records;
		if (loan_duration < 0) { return 0; }
		double monthly = 1.0 * loan_amount / loan_duration;
		owing = loan_amount;
		value = down_payment + loan_amount;
		int rec_month, next_month;
		double rec_depr, next_rec_depr;
		std::cin >> rec_month >> rec_depr;
		value = value * (1.0 - rec_depr);
		int cur_month = 0;
		int cur_rec = 1;
		while (value <= owing) {
			if (cur_rec < num_records) {
				cur_rec ++;
				std::cin >> next_month >> next_rec_depr;
				while (value <= owing && (cur_month+1) < next_month) {
					// simulate
					cur_month++;
					value = value * (1.0 - rec_depr);
					owing -= monthly;
				} 
				rec_month = next_month;
				rec_depr = next_rec_depr;
			} else {
				cur_month++;
				value = value * (1.0 - rec_depr);
				owing -= monthly;
			}
		}
		std::cout << cur_month << " month";	
		if (cur_month != 1) { std::cout << "s"; }
		std::cout << std::endl;
		while (cur_rec < num_records) {
			std::cin >> next_month >> next_rec_depr;
			cur_rec ++;
		}
	}
	return 0;
}