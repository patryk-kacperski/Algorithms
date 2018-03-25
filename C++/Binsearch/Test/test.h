#ifndef TEST_H
#define TEST_H

#include <iostream>
#include <vector>
#include <cassert>

class BinSearchTest {
private:
	std::vector<int> ascending;
	std::vector<int> descending;
	std::vector<int> nonPow2;

public:
	BinSearchTest();
	bool test1();
	bool test2();
	bool test3();
	bool test4();
	bool test5();
	bool test6();
	bool test7();
	bool test8();
	bool test9();
	bool test10();
	bool test11();
	bool test12();
	bool test13();
	bool test14();
	bool test15();
	bool test16();
	bool test17();
	bool test18();
	bool test19();
	bool test20();	
	void runTests();
};



#endif