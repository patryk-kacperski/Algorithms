#include <iostream>
#include <vector>
#include <exception>

template<typename Type>
class Matrix {
private:
	int rows;
	int columns;
	std::vector<std::vector<Type> > data;
	
	void add(Matrix &A, int rLow, int rHigh, int cLow, int cHigh, Matrix &res) const {
		for (int i = rLow; i <= rHigh; ++i) {
			for (int j = cLow; j <= cHigh; ++j) {
				res[i][j] += data[i][j] + A[i][j];
			}
		}
	}
	
	void classicMul(Matrix &A, int rLow, int rHigh, int cLow, int cHigh, int scLow, int scHigh, Matrix &res) const {
		for (int i = rLow; i <= rHigh; ++i) {
			for (int j = cLow; j <= cHigh; ++j) {
				for (int k = scLow; k <= scHigh; ++k) {
					res[i][j] += data[i][k] * A[k][j];
				}
			}
		}
	}
	
	// void *strassenMul(Matrix const &A, int firstRowLow, int firstRowHigh, int firstColumnLow, int firstColumnHigh, int secondRowLow, int secondRowHigh, int secondColumnLow, int secondColumnHigh, Matrix &res) {
		
	// }
	
	Matrix *strassenMul(Matrix const &A) const {
		if (rows <= 2 || columns <= 2 || A.rows <= 2 || A.columns <= 2) {
			return classicMul(A);
		}
		Matrix *mat1 = NULL, *mat2 = NULL;
		// mat1 = (rows & 1 || columns & 1) ? this->expanded() : this;
		// mat2 = (A.rows & 1 || A.columns & 1) ? A.expanded() : *A;
	}
	
	Matrix *coppersmithWinogradMul(Matrix const &A) const {
		// Maybe one day
		return NULL;
	}
	
	Matrix *expanded() {
		
		return NULL;
		
	}
	
public:
	// MARK: constructors
	Matrix(std::vector<std::vector<Type> > data) : data(data), rows(data.size()), columns(data[0].size()) { }
	
	Matrix(int rows, int columns) : rows(rows), columns(columns) { 
		for (int i = 0; i < rows; ++i) {
			std::vector<Type> v(columns);
			data.push_back(v);
		}
	}
	
	Matrix() { }
	
	Matrix(const Matrix &other) {
		
	}
	
	// MARK: getters
	int getRows() { return rows; }
	int getColumns() { return columns; }
	
	// MARK: operator overloads
	std::vector<Type>& operator [](int index) { return data[index]; }
	
	friend std::ostream& operator<<(std::ostream& os, const Matrix &A) {
		os << "[";
		for (int i = 0; i < A.rows; ++i) {
			for (int j = 0; j < A.columns; ++j) {
				os << A.data[i][j];
				if (j != A.columns - 1) os << " ";
			}
			if (i != A.rows - 1) os << "\n";
		}
		os << "]";
		return os;
	}
	
	friend std::istream& operator>>(std::istream& is, Matrix &A) {
		is >> A.rows >> A.columns;
		for (int i = 0; i < A.rows; ++i) {
			std::vector<Type> v;
			A.data.push_back(v);
			for (int j = 0; j < A.columns; ++j) {
				Type temp;
				is >> temp;
				A.data[i].push_back(temp);
			}
		}
		return is;
	}
	
	Matrix* operator+(Matrix &A) {
		if (this->rows != A.rows || this->columns != A.columns) {
			throw std::invalid_argument("Invalid matrix passed as an addition argument");
		}
		Matrix<Type> *res = new Matrix(rows, columns);
		int rLow = 0, rHigh = rows - 1, cLow = 0, cHigh = columns - 1; 
		add(A, rLow, rHigh, cLow, cHigh, *res);
		return res;
	}
	
	Matrix* operator*(Matrix &A) {
		if (this->columns != A.rows) {
			throw std::invalid_argument("Invalid matrix passed as a multiplication argument");
		}
		Matrix *res = new Matrix(rows, A.columns);
		int rLow = 0, rHigh = rows - 1, cLow = 0, cHigh = A.columns - 1, scLow = 0, scHigh = columns - 1;
		classicMul(A, rLow, rHigh, cLow, cHigh, scLow, scHigh, *res);
		return res;
	}
};

int main() {
	Matrix<int> A, B;
	std::cin >> A >> B;
	try {
		Matrix<int> *C = A * B;
		std::cout << (*C);
		delete C;
	} catch (std::invalid_argument &e) {
		std::cout << e.what();
	}
	
	return 0;
}