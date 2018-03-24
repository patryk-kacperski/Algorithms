#include "test.h"
#include "../binsearch.h"

bool test1() {
	std::cout << "Starting test 1: finding first element in array of size 16 sorted in ascending order\n";
	std::vector<int> v = {3, 7, 14, 17, 25, 31, 32, 45, 64, 100, 121, 134, 137, 149, 151, 159};
	int x = 3;
	int expected = 0;
	int actual = binSearch(v, x, [](int a, int b) -> bool { return a < b; });
	std::cout << "Test 1 result:\n\tExpected value: " << expected << "\n\tActual value: " << actual << "\n";
	return expected == actual;
}

bool test2() {
	std::cout << "Starting test 2: finding middle element in array of size 16 sorted in ascending order\n";
	std::vector<int> v = {3, 7, 14, 17, 25, 31, 32, 45, 64, 100, 121, 134, 137, 149, 151, 159};
	int x = 45;
	int expected = 7;
	int actual = binSearch(v, x, [](int a, int b) -> bool { return a < b; });
	std::cout << "Test 2 result:\n\tExpected value: " << expected << "\n\tActual value: " << actual << "\n";
	return expected == actual;
}

bool test3() {
	std::cout << "Starting test 3: finding last element in array of size 16 sorted in ascending order\n";
	std::vector<int> v = {3, 7, 14, 17, 25, 31, 32, 45, 64, 100, 121, 134, 137, 149, 151, 159};
	int x = 159;
	int expected = 15;
	int actual = binSearch(v, x, [](int a, int b) -> bool { return a < b; });
	std::cout << "Test 3 result:\n\tExpected value: " << expected << "\n\tActual value: " << actual << "\n";
	return expected == actual;
}

bool test4() {
	std::cout << "Starting test 4: trying to find element smaller than first in array of size 16 sorted in ascending order\n";
	std::vector<int> v = {3, 7, 14, 17, 25, 31, 32, 45, 64, 100, 121, 134, 137, 149, 151, 159};
	int x = 1;
	int expected = -1;
	int actual = binSearch(v, x, [](int a, int b) -> bool { return a < b; });
	std::cout << "Test 4 result:\n\tExpected value: " << expected << "\n\tActual value: " << actual << "\n";
	return expected == actual;
}

bool test5() {
	std::cout << "Starting test 5: trying to find non existing element in the middle of array of size 16 sorted in ascending order\n";
	std::vector<int> v = {3, 7, 14, 17, 25, 31, 32, 45, 64, 100, 121, 134, 137, 149, 151, 159};
	int x = 70;
	int expected = -1;
	int actual = binSearch(v, x, [](int a, int b) -> bool { return a < b; });
	std::cout << "Test 5 result:\n\tExpected value: " << expected << "\n\tActual value: " << actual << "\n";
	return expected == actual;
}

bool test6() {
	std::cout << "Starting test 6: trying to find element bigger than last in array of size 16 sorted in ascending order\n";
	std::vector<int> v = {3, 7, 14, 17, 25, 31, 32, 45, 64, 100, 121, 134, 137, 149, 151, 159};
	int x = 215;
	int expected = -1;
	int actual = binSearch(v, x, [](int a, int b) -> bool { return a < b; });
	std::cout << "Test 6 result:\n\tExpected value: " << expected << "\n\tActual value: " << actual << "\n";
	return expected == actual;
}

bool test7() {
	std::cout << "Starting test 7: finding first element in array of size 16 sorted in descending order\n";
	std::vector<int> v = {159, 151, 149, 137, 134, 121, 100, 64, 45, 32, 31, 25, 17, 14, 7, 3};
	int x = 159;
	int expected = 0;
	int actual = binSearch(v, x, [](int a, int b) -> bool { return a > b; });
	std::cout << "Test 7 result:\n\tExpected value: " << expected << "\n\tActual value: " << actual << "\n";
	return expected == actual;
}

bool test8() {
	std::cout << "Starting test 8: finding middle element in array of size 16 sorted in descending order\n";
	std::vector<int> v = {159, 151, 149, 137, 134, 121, 100, 64, 45, 32, 31, 25, 17, 14, 7, 3};
	int x = 64;
	int expected = 7;
	int actual = binSearch(v, x, [](int a, int b) -> bool { return a > b; });
	std::cout << "Test 8 result:\n\tExpected value: " << expected << "\n\tActual value: " << actual << "\n";
	return expected == actual;
}

bool test9() {
	std::cout << "Starting test 9: finding last element in array of size 16 sorted in descending order\n";
	std::vector<int> v = {159, 151, 149, 137, 134, 121, 100, 64, 45, 32, 31, 25, 17, 14, 7, 3};
	int x = 3;
	int expected = 15;
	int actual = binSearch(v, x, [](int a, int b) -> bool { return a > b; });
	std::cout << "Test 9 result:\n\tExpected value: " << expected << "\n\tActual value: " << actual << "\n";
	return expected == actual;
}

bool test10() {
	std::cout << "Starting test 10: trying to find element bigger than first in array of size 16 sorted in descending order\n";
	std::vector<int> v = {159, 151, 149, 137, 134, 121, 100, 64, 45, 32, 31, 25, 17, 14, 7, 3};
	int x = 215;
	int expected = -1;
	int actual = binSearch(v, x, [](int a, int b) -> bool { return a > b; });
	std::cout << "Test 10 result:\n\tExpected value: " << expected << "\n\tActual value: " << actual << "\n";
	return expected == actual;
}

bool test11() {
	std::cout << "Starting test 11: trying to find non existing element in the middle of array of size 16 sorted in descending order\n";
	std::vector<int> v = {159, 151, 149, 137, 134, 121, 100, 64, 45, 32, 31, 25, 17, 14, 7, 3};
	int x = 70;
	int expected = -1;
	int actual = binSearch(v, x, [](int a, int b) -> bool { return a > b; });
	std::cout << "Test 11 result:\n\tExpected value: " << expected << "\n\tActual value: " << actual << "\n";
	return expected == actual;
}

bool test12() {
	std::cout << "Starting test 12: trying to find element smaller than last in array of size 16 sorted in descending order\n";
	std::vector<int> v = {159, 151, 149, 137, 134, 121, 100, 64, 45, 32, 31, 25, 17, 14, 7, 3};
	int x = 1;
	int expected = -1;
	int actual = binSearch(v, x, [](int a, int b) -> bool { return a > b; });
	std::cout << "Test 12 result:\n\tExpected value: " << expected << "\n\tActual value: " << actual << "\n";
	return expected == actual;
}
