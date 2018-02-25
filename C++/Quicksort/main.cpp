#include <iostream>
#include <vector>
#include "quicksort.h"

int main() {
	int n;
	std::vector<int> S;
	std::cin >> n;
	for (int i = 0; i < n; ++i) {
		int temp;
		std::cin >> temp;
		S.push_back(temp);
	}
	quicksort(S, [](int a, int b) -> bool { return a < b; });
	for (unsigned int i = 0; i < S.size(); ++i) {
		std::cout << S[i] << " ";
	}
	return 0;
}