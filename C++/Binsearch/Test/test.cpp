#include "test.h"
#include "../binsearch.h"

void prepareSortedVectorOfSize(int n, std::vector<int> &v) {
	v.resize(n);
	for (int i = 0; i < n; ++i) {
		v[i] = i;
	}
}

template<typename Type, typename IsEqual>
int linearSearch(std::vector<Type> const &A, Type x, IsEqual equal) {
	for (unsigned int i = 0; i < A.size(); ++i) {
		if (equal(A[i], x)) {
			return i;
		}
	}
	return -1;
}

BinSearchTest::BinSearchTest() {
	ascending = {3, 7, 14, 17, 25, 31, 32, 45, 64, 100, 121, 134, 137, 149, 151, 159};
	descending = {159, 151, 149, 137, 134, 121, 100, 64, 45, 32, 31, 25, 17, 14, 7, 3};
	nonPow2 = {3, 7, 14, 17, 25, 31, 32, 45, 64, 100, 121, 134, 137, 149, 151, 159, 161, 172, 189};
}

bool BinSearchTest::test1() {
	std::cout << "Starting test 1: finding first element in array of size 16 sorted in ascending order\n";
	int x = 3;
	int expected = 0;
	int actual = binSearch(ascending, x, [](int a, int b) -> bool { return a < b; });
	std::cout << "Test 1 result:\n\tExpected value: " << expected << "\n\tActual value: " << actual << "\n";
	return expected == actual;
}

bool BinSearchTest::test2() {
	std::cout << "Starting test 2: finding middle element in array of size 16 sorted in ascending order\n";
	int x = 45;
	int expected = 7;
	int actual = binSearch(ascending, x, [](int a, int b) -> bool { return a < b; });
	std::cout << "Test 2 result:\n\tExpected value: " << expected << "\n\tActual value: " << actual << "\n";
	return expected == actual;
}

bool BinSearchTest::test3() {
	std::cout << "Starting test 3: finding last element in array of size 16 sorted in ascending order\n";
	int x = 159;
	int expected = 15;
	int actual = binSearch(ascending, x, [](int a, int b) -> bool { return a < b; });
	std::cout << "Test 3 result:\n\tExpected value: " << expected << "\n\tActual value: " << actual << "\n";
	return expected == actual;
}

bool BinSearchTest::test4() {
	std::cout << "Starting test 4: trying to find element smaller than first in array of size 16 sorted in ascending order\n";
	int x = 1;
	int expected = -1;
	int actual = binSearch(ascending, x, [](int a, int b) -> bool { return a < b; });
	std::cout << "Test 4 result:\n\tExpected value: " << expected << "\n\tActual value: " << actual << "\n";
	return expected == actual;
}

bool BinSearchTest::test5() {
	std::cout << "Starting test 5: trying to find non existing element in the middle of array of size 16 sorted in ascending order\n";
	int x = 70;
	int expected = -1;
	int actual = binSearch(ascending, x, [](int a, int b) -> bool { return a < b; });
	std::cout << "Test 5 result:\n\tExpected value: " << expected << "\n\tActual value: " << actual << "\n";
	return expected == actual;
}

bool BinSearchTest::test6() {
	std::cout << "Starting test 6: trying to find element bigger than last in array of size 16 sorted in ascending order\n";
	int x = 215;
	int expected = -1;
	int actual = binSearch(ascending, x, [](int a, int b) -> bool { return a < b; });
	std::cout << "Test 6 result:\n\tExpected value: " << expected << "\n\tActual value: " << actual << "\n";
	return expected == actual;
}

bool BinSearchTest::test7() {
	std::cout << "Starting test 7: finding first element in array of size 16 sorted in descending order\n";
	int x = 159;
	int expected = 0;
	int actual = binSearch(descending, x, [](int a, int b) -> bool { return a > b; });
	std::cout << "Test 7 result:\n\tExpected value: " << expected << "\n\tActual value: " << actual << "\n";
	return expected == actual;
}

bool BinSearchTest::test8() {
	std::cout << "Starting test 8: finding middle element in array of size 16 sorted in descending order\n";
	int x = 64;
	int expected = 7;
	int actual = binSearch(descending, x, [](int a, int b) -> bool { return a > b; });
	std::cout << "Test 8 result:\n\tExpected value: " << expected << "\n\tActual value: " << actual << "\n";
	return expected == actual;
}

bool BinSearchTest::test9() {
	std::cout << "Starting test 9: finding last element in array of size 16 sorted in descending order\n";
	int x = 3;
	int expected = 15;
	int actual = binSearch(descending, x, [](int a, int b) -> bool { return a > b; });
	std::cout << "Test 9 result:\n\tExpected value: " << expected << "\n\tActual value: " << actual << "\n";
	return expected == actual;
}

bool BinSearchTest::test10() {
	std::cout << "Starting test 10: trying to find element bigger than first in array of size 16 sorted in descending order\n";
	int x = 215;
	int expected = -1;
	int actual = binSearch(descending, x, [](int a, int b) -> bool { return a > b; });
	std::cout << "Test 10 result:\n\tExpected value: " << expected << "\n\tActual value: " << actual << "\n";
	return expected == actual;
}

bool BinSearchTest::test11() {
	std::cout << "Starting test 11: trying to find non existing element in the middle of array of size 16 sorted in descending order\n";
	int x = 70;
	int expected = -1;
	int actual = binSearch(descending, x, [](int a, int b) -> bool { return a > b; });
	std::cout << "Test 11 result:\n\tExpected value: " << expected << "\n\tActual value: " << actual << "\n";
	return expected == actual;
}

bool BinSearchTest::test12() {
	std::cout << "Starting test 12: trying to find element smaller than last in array of size 16 sorted in descending order\n";
	int x = 1;
	int expected = -1;
	int actual = binSearch(descending, x, [](int a, int b) -> bool { return a > b; });
	std::cout << "Test 12 result:\n\tExpected value: " << expected << "\n\tActual value: " << actual << "\n";
	return expected == actual;
}

bool BinSearchTest::test13() {
	std::cout << "Starting test 13: finding first element in array of size 19 sorted in ascending order\n";
	int x = 3;
	int expected = 0;
	int actual = binSearch(nonPow2, x, [](int a, int b) -> bool { return a < b; });
	std::cout << "Test 13 result:\n\tExpected value: " << expected << "\n\tActual value: " << actual << "\n";
	return expected == actual;
}

bool BinSearchTest::test14() {
	std::cout << "Starting test 14: finding middle element in array of size 19 sorted in ascending order\n";
	int x = 100;
	int expected = 9;
	int actual = binSearch(nonPow2, x, [](int a, int b) -> bool { return a < b; });
	std::cout << "Test 14 result:\n\tExpected value: " << expected << "\n\tActual value: " << actual << "\n";
	return expected == actual;
}

bool BinSearchTest::test15() {
	std::cout << "Starting test 15: finding last element in array of size 19 sorted in ascending order\n";
	int x = 189;
	int expected = 18;
	int actual = binSearch(nonPow2, x, [](int a, int b) -> bool { return a < b; });
	std::cout << "Test 15 result:\n\tExpected value: " << expected << "\n\tActual value: " << actual << "\n";
	return expected == actual;
}

bool BinSearchTest::test16() {
	std::cout << "Starting test 16: trying to find element smaller than first in array of size 19 sorted in ascending order\n";
	int x = 1;
	int expected = -1;
	int actual = binSearch(nonPow2, x, [](int a, int b) -> bool { return a < b; });
	std::cout << "Test 16 result:\n\tExpected value: " << expected << "\n\tActual value: " << actual << "\n";
	return expected == actual;
}

bool BinSearchTest::test17() {
	std::cout << "Starting test 17: trying to find non existing element in the middle of array of size 19 sorted in ascending order\n";
	int x = 70;
	int expected = -1;
	int actual = binSearch(nonPow2, x, [](int a, int b) -> bool { return a < b; });
	std::cout << "Test 17 result:\n\tExpected value: " << expected << "\n\tActual value: " << actual << "\n";
	return expected == actual;
}

bool BinSearchTest::test18() {
	std::cout << "Starting test 18: trying to find element bigger than last in array of size 19 sorted in ascending order\n";
	int x = 215;
	int expected = -1;
	int actual = binSearch(nonPow2, x, [](int a, int b) -> bool { return a < b; });
	std::cout << "Test 18 result:\n\tExpected value: " << expected << "\n\tActual value: " << actual << "\n";
	return expected == actual;
}

bool BinSearchTest::test19() {
	std::cout << "Starting test 19: finding element in array of size 1\n";
	std::vector<int> v = {3};
	int x = 3;
	int expected = 0;
	int actual = binSearch(v, x, [](int a, int b) -> bool { return a < b; });
	std::cout << "Test 19 result:\n\tExpected value: " << expected << "\n\tActual value: " << actual << "\n";
	return expected == actual;
}

bool BinSearchTest::test20() {
	std::cout << "Starting test 20: trying to find element in empty array\n";
	std::vector<int> v;
	int x = 3;
	int expected = -1;
	int actual = binSearch(v, x, [](int a, int b) -> bool { return a < b; });
	std::cout << "Test 20 result:\n\tExpected value: " << expected << "\n\tActual value: " << actual << "\n";
	return expected == actual;
}

bool BinSearchTest::test21() {
	std::cout << "Starting test 21: comparing run time of binary search and linear search when looking for last element in array of size 1 048 576.\nTaking average time from 100 invocations\n";
	std::vector<int> v;
	prepareSortedVectorOfSize(1048576, v);
	int const numberOfIterations = 100;
	int x = 1048575;
	int64_t binSearchTime = 0;
	for (int i = 0; i < numberOfIterations; ++i) {
		auto start = std::chrono::high_resolution_clock::now();
		binSearch(v, x, [](int a, int b) -> bool { return a < b; });
		auto end = std::chrono::high_resolution_clock::now();
		auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
		binSearchTime += duration;
	}
	std::cout << "Test 21 result:\n\tBinary search time: " << binSearchTime * 1.0 / numberOfIterations << " nanoseconds";
	int64_t linearSearchTime = 0;
	for (int i = 0; i < numberOfIterations; ++i) {
		auto start = std::chrono::high_resolution_clock::now();
		linearSearch(v, x, [](int a, int b) -> bool { return a == b; });
		auto end = std::chrono::high_resolution_clock::now();
		auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
		linearSearchTime += duration;
	}
	std::cout << "\n\tLinear search time: " << linearSearchTime * 1.0 / numberOfIterations << " milliseconds\n";
	return true;
}

void BinSearchTest::runTests() {
	std::cout << "Testing binary search algorithm\n\n";
	assert(test1());
	std::cout << "Test 1 passed\n\n";
	assert(test2());
	std::cout << "Test 2 passed\n\n";
	assert(test3());
	std::cout << "Test 3 passed\n\n";
	assert(test4());
	std::cout << "Test 4 passed\n\n";
	assert(test5());
	std::cout << "Test 5 passed\n\n";
	assert(test6());
	std::cout << "Test 6 passed\n\n";
	assert(test7());
	std::cout << "Test 7 passed\n\n";
	assert(test8());
	std::cout << "Test 8 passed\n\n";
	assert(test9());
	std::cout << "Test 9 passed\n\n";
	assert(test10());
	std::cout << "Test 10 passed\n\n";
	assert(test11());
	std::cout << "Test 11 passed\n\n";
	assert(test12());
	std::cout << "Test 12 passed\n\n";
	assert(test13());
	std::cout << "Test 13 passed\n\n";
	assert(test14());
	std::cout << "Test 14 passed\n\n";
	assert(test15());
	std::cout << "Test 15 passed\n\n";
	assert(test16());
	std::cout << "Test 16 passed\n\n";
	assert(test17());
	std::cout << "Test 17 passed\n\n";
	assert(test18());
	std::cout << "Test 18 passed\n\n";
	assert(test19());
	std::cout << "Test 19 passed\n\n";
	assert(test20());
	std::cout << "Test 20 passed\n\n";

	// Efficiency tests
	test21();
	std::cout << "\n\n";
}