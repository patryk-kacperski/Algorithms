#include <chrono>
#include "matrix.h"

typedef std::chrono::high_resolution_clock Clock;
typedef std::chrono::high_resolution_clock::time_point TimePoint;

int main() {
	int const size = 1024;
	Matrix<int> A(size, size), B(size, size);
	// Matrix<int> A, B;
	// std::cin >> A >> B;
	try {
		TimePoint t1 = Clock::now();
		Matrix<int> *C = A * B;
		TimePoint t2 = Clock::now();
		auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count();
		std::cout << duration << "\n";
		// std::cout << *C;
		delete C;
	} catch (std::invalid_argument &e) {
		std::cout << e.what();
	}
	
	return 0;
}