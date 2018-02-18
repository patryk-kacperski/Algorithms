#include <iostream>
#include <vector>
#include <utility>

static int counter = 0;

template<typename Type, typename IsLess>
int partition(std::vector<Type> &S, IsLess less, int low, int high) {
	int pivotItem = S[low];
	int i = low + 1, j = low;
	for (; i <= high; ++i) {
		if (less(S[i], pivotItem)) {
			std::swap(S[i], S[++j]);
		}
	}
	std::swap(S[low], S[j]);
	return j;
}

template<typename Type, typename IsLess>
void quicksort(std::vector<Type> &S, IsLess less, int low, int high) {
	if (low >= high) { return; }
	int mid = partition(S, less, low, high);
	quicksort(S, less, low, mid - 1);
	quicksort(S, less, mid + 1, high);
}

template<typename Type, typename IsLess>
void quicksort(std::vector<Type> &S, IsLess less) {
	int low = 0, high = S.size() - 1;
	quicksort(S, less, low, high);
}

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
	for (int i = 0; i < S.size(); ++i) {
		std::cout << S[i] << " ";
	}
	return 0;
}
