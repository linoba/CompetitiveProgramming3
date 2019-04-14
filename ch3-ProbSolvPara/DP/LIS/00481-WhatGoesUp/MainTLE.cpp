#include <iostream>
#include <vector>
#include <cstdlib>
#include <stack>
// g++ Main.cpp -lm -lcrypt -O2 -std=c++11

/*void insertInVector(std::vector<int>* arr, int value) {
	int start = 0;
	int end = arr->size();
	while (start != end) {
		int middle = (start+end)/2;
		if (arr->at(middle) < value) {
			if (start == middle) { start++; } 
			else { start = middle; }
		} else if (arr->at(middle) == value) { 
			return; // must be strictly increasing
		}
		else {
			end = middle;
		}
	}
	if (value < arr->at(start)) {
		arr->at(start) = value;
	}
	return;
}*/

int main( int argc, const char* argv[]) {
	std::vector<int> arr_val, arr_lis, arr_prev;
	int value;
	while (std::cin >> value) {
		arr_val.push_back(value);
		if (arr_val.size() == 1) {
			arr_lis.push_back(1);
			arr_prev.push_back(-1);
		} else {
			int max_lis = -1;
			int id_max_prev = -1;
			for (int i=0; i<arr_val.size()-1; i++) {
				if (arr_val[i] < value) {
					if (arr_lis[i] >= max_lis) {
						max_lis = arr_lis[i];
						id_max_prev = i;
					}
				} 
			}
			if (max_lis == -1) {
				max_lis = 1;
			} else {
				max_lis++;
			}
			arr_lis.push_back(max_lis);
			arr_prev.push_back(id_max_prev);
		}
	}
	/*for (int i=0; i<arr_val.size(); i++) {
		std::cout << std::setw(5) << arr_val[i];
		std::cout << std::setw(5) << arr_lis[i];
		std::cout << std::setw(5) << arr_prev[i];
		std::cout << std::endl;
	}*/
	if (!arr_val.empty()) {
		int max_lis = 0;
		int end_element = 0;
		for (int i=0; i<arr_lis.size(); i++) {
			int cur_lis = arr_lis[i];
			if (cur_lis>=max_lis) {
				max_lis = cur_lis;
				end_element = i;
			}
		}
		std::stack<int> result_stack;
		while (end_element != -1) {
			result_stack.push(arr_val[end_element]);
			end_element = arr_prev[end_element];
		}
		std::cout << result_stack.size() << std::endl << "-" << std::endl;
		while (result_stack.size()) {
			std::cout << result_stack.top() << std::endl;
			result_stack.pop();
		}
	}
	return 0;
}