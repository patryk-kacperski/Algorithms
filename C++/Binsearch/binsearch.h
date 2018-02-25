#ifndef BINSEARCH_H
#define BINSEARCH_H

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

#endif