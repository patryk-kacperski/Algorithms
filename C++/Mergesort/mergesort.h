#ifndef MERGESORT_H
#define MERGESORT_H

#include <vector>

template<typename Type, typename IsLess>
void merge(std::vector<Type> &S, int low, int mid, int high, IsLess less) {
	std::vector<Type> temp(high - low + 1);
	int i = low, j = mid + 1, k = 0;
	while (i <= mid && j <= high) {
		if (less(S[i], S[j])) {
			temp[k++] = S[i++];
		} else {
			temp[k++] = S[j++];
		}
	}
	if (i > mid) {
		while (j <= high) {
			temp[k++] = S[j++];
		}
	} else {
		while (i <= mid) {
			temp[k++] = S[i++];
		}
	}
	k = 0;
	for (i = low; i <= high; ++i) {
		S[i] = temp[k++];
	}
}

template<typename Type, typename IsLess>
void mergesort(std::vector<Type> &S, int low, int high, IsLess less) {
	if (low >= high) { return; }
	int mid = (low + high) / 2;
	mergesort(S, low, mid, less);
	mergesort(S, mid + 1, high, less);
	merge(S, low, mid, high, less);
}

template<typename Type, typename IsLess>
void mergesort(std::vector<Type> &S, IsLess less) {
	int low = 0, high = S.size() - 1;
	mergesort(S, low, high, less);
}

#endif