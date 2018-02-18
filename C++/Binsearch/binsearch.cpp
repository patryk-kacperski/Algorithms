#include <iostream>
#include <vector>

template<typename Type, typename IsLesser>
int binSearch(std::vector<Type> const &S, Type x, IsLesser less) {
	int n = S.size();
	int low, high, mid;
	low = 0;
	high = n - 1;
	while(low < high) {
		mid = (low + high + 1) / 2;
		if (less(x, S[mid])) {
			high = mid - 1;
		} else {
			low = mid;
		}
	}
	return less(S[low], x) || less(x, S[low]) ? -1 : low;
}

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