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
	
	void strassenMul(Matrix &A, int rLow, int rHigh, int cLow, int cHigh, int scLow, int scHigh, Matrix &res, Matrix &M1, Matrix &M2, Matrix &M3, Matrix &M4, Matrix &M5,
		Matrix &M6, Matrix &M7, Matrix &M1T1, Matrix &M1T2, Matrix &M2T, Matrix &M3T, Matrix &M4T, Matrix &M5T, Matrix &M6T1, Matrix &M6T2, Matrix &M7T1, Matrix &M7T2) {
			int a1rLow = rLow, a1rHigh = (rHigh - rLow) / 2, a2rLow = (rHigh - rLow) / 2 + 1, a2rHigh = rHigh;
			int a1cLow = scLow, a1cHigh = (scHigh - scLow) / 2, a2cLow = (scHigh - scLow) / 2 + 1, a2cHigh = scHigh;
			int b1rLow = a1cLow, b1rHigh = a1cHigh, b2rLow = a2cLow, b2rHigh = a2cHigh;
			int b1cLow = cLow, b1cHigh = (cHigh - cLow) / 2, b2cLow = (cHigh - cLow) / 2 + 1, b2cHigh = cHigh;
		}
	
	void strassenMul(Matrix &A, int rLow, int rHigh, int cLow, int cHigh, int scLow, int scHigh, Matrix &res) const {
		if (rHigh - rLow <= 1 || cHigh - cLow <= 1) {
			classicMul(A, rLow, rHigh, cLow, cHigh, scLow, scHigh, res);
			return;
		}
		
		int tempRows = (rHigh - rLow) / 2;
		int tempColumns = (cHigh - cLow) / 2;
		Matrix<Type> *M1 = new Matrix(tempRows, tempColumns);
		Matrix<Type> *M2 = new Matrix(tempRows, tempColumns);
		Matrix<Type> *M3 = new Matrix(tempRows, tempColumns);
		Matrix<Type> *M4 = new Matrix(tempRows, tempColumns);
		Matrix<Type> *M5 = new Matrix(tempRows, tempColumns);
		Matrix<Type> *M6 = new Matrix(tempRows, tempColumns);
		Matrix<Type> *M7 = new Matrix(tempRows, tempColumns);
		Matrix<Type> *M1T1 = new Matrix(tempRows, tempColumns);
		Matrix<Type> *M1T2 = new Matrix(tempRows, tempColumns);
		Matrix<Type> *M2T = new Matrix(tempRows, tempColumns);
		Matrix<Type> *M3T = new Matrix(tempRows, tempColumns);
		Matrix<Type> *M4T = new Matrix(tempRows, tempColumns);
		Matrix<Type> *M5T = new Matrix(tempRows, tempColumns);
		Matrix<Type> *M6T1 = new Matrix(tempRows, tempColumns);
		Matrix<Type> *M6T2 = new Matrix(tempRows, tempColumns);
		Matrix<Type> *M7T1 = new Matrix(tempRows, tempColumns);
		Matrix<Type> *M7T2 = new Matrix(tempRows, tempColumns);
		
		strassenMul(A, rLow, rHigh, cLow, cHigh, scLow, scHigh, *M1, *M2, *M3, *M4, *M5, *M6, *M7, *M1T1, *M1T2, *M2T, *M3T, *M4T, *M5T, *M6T1, *M6T2, *M7T1, *M7T2);
		
		delete M1;
		delete M2;
		delete M3;
		delete M4;
		delete M5;
		delete M6;
		delete M7;
		delete M1T1;
		delete M1T2;
		delete M3T;
		delete M4T;
		delete M5T;
		delete M6T1;
		delete M6T2;
		delete M7T1;
		delete M7T2;
	}
	
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