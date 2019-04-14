#include <iostream>
#include <vector>
#include <cstdlib>
#include <stack>
//#include <iomanip>
// g++ Main.cpp -lm -lcrypt -O2 -std=c++11

int insertInVector(std::vector<int>* arr, int value) {
	int start = 0;
	int end = arr->size();
	while (start != end) {
		int middle = (start+end)/2;
		if (arr->at(middle) < value) {
			if (start == middle) { start++; } 
			else { start = middle; }
		} else if (arr->at(middle) == value) { 
			return middle; // must be strictly increasing
		}
		else {
			end = middle;
		}
	}
	if (value < arr->at(start)) {
		arr->at(start) = value;
	}
	return start;
}

int main( int argc, const char* argv[]) {
	std::vector<int> arr_val, arr_prev;
	std::vector<int> sorted_val, sorted_id;
	int value;
	while (std::cin >> value) {
		arr_val.push_back(value);
		if (arr_val.size() == 1) {
			arr_prev.push_back(-1);
			sorted_val.push_back(value);
			sorted_id.push_back(0);
		} else {
			if (sorted_val.back() < value) {
				arr_prev.push_back(sorted_id.back());
				sorted_val.push_back(value);
				sorted_id.push_back(arr_val.size()-1);
			} else if (sorted_val.back() == value) {
				//arr_prev.push_back(sorted_id[sorted_id.size()-2]); // possibly unneccessary
				arr_prev.push_back(-1);
			} else {
				// replace some value in sorted array
				int insert_pos = insertInVector(&sorted_val, value);
				arr_prev.push_back(sorted_id[insert_pos-1]);
				sorted_id[insert_pos] = arr_val.size()-1;
			}
		}
	}
	/*for (int i=0; i<arr_val.size(); i++) {
		std::cout << std::setw(4) << i;
		std::cout << std::setw(4) << arr_val[i];
		std::cout << std::setw(4) << arr_prev[i];
		std::cout << std::endl;
	}
	std::cout << std::endl;
	for (int i=0; i<sorted_val.size(); i++) {
		std::cout << std::setw(4) << i;
		std::cout << std::setw(4) << sorted_val[i];
		std::cout << std::setw(4) << sorted_id[i];
		std::cout << std::endl;
	}*/
	if (!arr_val.empty()) {
		std::stack<int> result_stack;
		int cur_index = sorted_id.back();
		while (cur_index != -1) {
			int cur_value = arr_val[cur_index];
			result_stack.push(cur_value);
			cur_index = arr_prev[cur_index];
		}
		std::cout << result_stack.size() << std::endl << "-" << std::endl;
		while (result_stack.size()) {
			std::cout << result_stack.top() << std::endl;
			result_stack.pop();
		}
	}
	return 0;
}