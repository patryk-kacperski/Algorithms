#ifndef BINSEARCH_H
#define BINSEARCH_H

#include <vector>

template<typename Type, typename IsLesser>
int binSearch(std::vector<Type> const &A, Type x, IsLesser less) {
	if (A.empty()) {
		return -1;
	}
	int n = A.size();
	int low, high, mid;
	low = 0;
	high = n - 1;
	while(low < high) {
		mid = (low + high) / 2;
		if (less(A[mid], x)) {
			low = mid + 1;
		} else {
			high = mid;
		}
	}
	return less(A[low], x) || less(x, A[low]) ? -1 : low;
}

#endif