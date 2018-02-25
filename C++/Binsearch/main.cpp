#include <iostream>
#include <vector>
#include "binsearch.h"

int main() {
	int n, x;
	std::vector<int> S;
	std::cin >> n;
	for (int i = 0; i < n; ++i) {
		int temp;
		std::cin >> temp;
		S.push_back(temp);
	}
	std::cin >> x;
	int index = binSearch(S, x, [](int a, int b) -> bool { return a < b; });
	if (index == -1) {
		std::cout << "Not found";
	} else {
		std::cout << index;
	}
	return 0;
}