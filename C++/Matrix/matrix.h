#include <vector>
#include <exception>
#include <iostream>

#ifndef MATRIX_H
#define MATRIX_H

struct Range {
	int startRow;
	int endRow;
	int startColumn;
	int endColumn;
	
	Range(int startRow, int endRow, int startColumn, int endColumn);
};
std::ostream& operator<<(std::ostream& os, const Range &range);

template<typename Type>
class Matrix {
private:
	int rows;
	int columns;
	std::vector<std::vector<Type> > data;
	bool shouldCheck;
	
	void add(Matrix const &A, Range firstRange, Range secondRange, Range resRange, Matrix &res) const {
		for (int fi = firstRange.startRow, si = secondRange.startRow, ri = resRange.startRow; fi <= firstRange.endRow; ++fi, ++si, ++ri) {
			for (int fj = firstRange.startColumn, sj = secondRange.startColumn, rj = resRange.startColumn; fj <= firstRange.endColumn; ++fj, ++sj, ++rj) {
				// bool firstCheck = (fi >= data.size() || si >= A.data.size() || fi >= res.data.size());
				// bool secondCheck = (fj >= data[0].size() || sj >= A.data[0].size() || res.data[0].size());
				// if (firstCheck || secondCheck) { continue; }
				res[ri][rj] = data[fi][fj] + A.data[si][sj];
			}
		}
	}
	
	void subtract(Matrix const &A, Range firstRange, Range secondRange, Range resRange, Matrix &res) const {
		for (int fi = firstRange.startRow, si = secondRange.startRow, ri = resRange.startRow; fi <= firstRange.endRow; ++fi, ++si, ++ri) {
			for (int fj = firstRange.startColumn, sj = secondRange.startColumn, rj = resRange.startColumn; fj <= firstRange.endColumn; ++fj, ++sj, ++rj) {
				// bool firstCheck = (fi >= data.size() || si >= A.data.size() || fi >= res.data.size());
				// bool secondCheck = (fj >= data[0].size() || sj >= A.data[0].size() || res.data[0].size());
				// if (firstCheck || secondCheck) { continue; }
				res[ri][rj] = data[fi][fj] - A.data[si][sj];
			}
		}
	}
	
	void add(Matrix const &A, Range range, Matrix &res) const {
		add(A, range, range, range, res);
	}
	
	void subtract(Matrix const &A, Range range, Matrix &res) const {
		subtract(A, range, range, range, res);
	}
	
	void classicMul(Matrix const &A, Range firstRange, Range secondRange, Range resRange, Matrix &res) const {
		for (int fi = firstRange.startRow, ri = resRange.startRow; fi <= firstRange.endRow; ++fi, ++ri) {
			for (int sj = secondRange.startColumn, rj = resRange.startColumn; sj <= secondRange.endColumn; ++sj, ++rj) {
				for (int fk = firstRange.startColumn, sk = secondRange.startRow; fk <= firstRange.endColumn; ++fk, ++sk) {
					// bool firstCheck = (fi >= data.size() || ri >= res.data.size());
					// bool secondCheck = (sj >= A.data[0].size() || rj >= res.data[0].size());
					// bool thirdCheck = (fk >= data[0].size() || sk >= A.data.size());
					// if (firstCheck || secondCheck || thirdCheck) { continue; }
					res[ri][rj] += data[fi][fk] * A.data[sk][sj];
				}
			}
		}
	}
	
	void classicMul(Matrix const &A, Range firstRange, Range secondRange, Matrix &res) const {
		Range resRange(0, firstRange.endRow - firstRange.startRow, 0, secondRange.endColumn - secondRange.startColumn);
		classicMul(A, firstRange, secondRange, resRange, res);
	}
	
	void strassenMul(Matrix const &A, Range firstRange, Range secondRange, Matrix &res) const {
		extend()
		
		if (firstRange.endRow - firstRange.startRow <= 1 || secondRange.endColumn - secondRange.startColumn <= 1) {
			classicMul(A, firstRange, secondRange, res);
			return;
		}
		
		int resRows = res.data.size(), resColumns = res.data[0].size();
		
		int a1rLow = firstRange.startRow, a1rHigh = a1rLow + ((firstRange.endRow - firstRange.startRow) / 2), a2rLow = a1rHigh + 1, a2rHigh = firstRange.endRow;
		int a1cLow = firstRange.startColumn, a1cHigh = a1cLow + ((firstRange.endColumn - firstRange.startColumn) / 2), a2cLow = a1cHigh + 1, a2cHigh = firstRange.endColumn;
		int b1rLow = secondRange.startRow, b1rHigh = b1rLow + ((secondRange.endRow - secondRange.startRow) / 2), b2rLow = b1rHigh + 1, b2rHigh = secondRange.endRow;
		int b1cLow = secondRange.startColumn, b1cHigh = b1cLow + ((secondRange.endColumn - secondRange.startColumn) / 2), b2cLow = b1cHigh + 1, b2cHigh = secondRange.endColumn;
		int res1rLow = 0, res1rHigh = (resRows / 2) - 1, res2rLow = res1rHigh + 1, res2rHigh = resRows - 1;
		int res1cLow = 0, res1cHigh = (resColumns / 2) - 1, res2cLow = res1cHigh + 1, res2cHigh = resColumns - 1;
		
		int tempRows = (firstRange.endRow - firstRange.startRow) / 2 + 1;
		int tempColumns = (secondRange.endColumn - secondRange.startColumn) / 2 + 1;
		int aTempRows = tempRows;
		int aTempColumns = (firstRange.endColumn - firstRange.startColumn) / 2 + 1;
		int bTempRows = aTempColumns;
		int bTempColumns = tempColumns;
		
		Matrix<Type> *M1 = new Matrix(tempRows, tempColumns);
		Matrix<Type> *M2 = new Matrix(tempRows, tempColumns);
		Matrix<Type> *M3 = new Matrix(tempRows, tempColumns);
		Matrix<Type> *M4 = new Matrix(tempRows, tempColumns);
		Matrix<Type> *M5 = new Matrix(tempRows, tempColumns);
		Matrix<Type> *M6 = new Matrix(tempRows, tempColumns);
		Matrix<Type> *M7 = new Matrix(tempRows, tempColumns);
		Matrix<Type> *M1T1 = new Matrix(aTempRows, aTempColumns);
		Matrix<Type> *M1T2 = new Matrix(bTempRows, bTempColumns);
		Matrix<Type> *M2T = new Matrix(aTempRows, aTempColumns);
		Matrix<Type> *M3T = new Matrix(bTempRows, bTempColumns);
		Matrix<Type> *M4T = new Matrix(bTempRows, bTempColumns);
		Matrix<Type> *M5T = new Matrix(aTempRows, aTempColumns);
		Matrix<Type> *M6T1 = new Matrix(aTempRows, aTempColumns);
		Matrix<Type> *M6T2 = new Matrix(bTempRows, bTempColumns);
		Matrix<Type> *M7T1 = new Matrix(aTempRows, aTempColumns);
		Matrix<Type> *M7T2 = new Matrix(bTempRows, bTempColumns);
		
		Range a11Range(a1rLow, a1rHigh, a1cLow, a1cHigh), b11Range(b1rLow, b1rHigh, b1cLow, b1cHigh);
		Range a12Range(a1rLow, a1rHigh, a2cLow, a2cHigh), b12Range(b1rLow, b1rHigh, b2cLow, b2cHigh);
		Range a21Range(a2rLow, a2rHigh, a1cLow, a1cHigh), b21Range(b2rLow, b2rHigh, b1cLow, b1cHigh);
		Range a22Range(a2rLow, a2rHigh, a2cLow, a2cHigh), b22Range(b2rLow, b2rHigh, b2cLow, b2cHigh);
		Range aResRange(0, aTempRows - 1, 0, aTempColumns - 1), bResRange(0, bTempRows - 1, 0, bTempColumns - 1);
		
		Range resMulRange(0, aTempRows - 1, 0, bTempColumns - 1);
		Range res11Range(res1rLow, res1rHigh, res1cLow, res1cHigh);
		Range res12Range(res1rLow, res1rHigh, res2cLow, res2cHigh);
		Range res21Range(res2rLow, res2rHigh, res1cLow, res1cHigh);
		Range res22Range(res2rLow, res2rHigh, res2cLow, res2cHigh);
		
		// M1
		this->add(*this, a11Range, a22Range, aResRange, *M1T1);
		A.add(A, b11Range, b22Range, bResRange, *M1T2);
		M1T1->classicMul(*M1T2, aResRange, bResRange, *M1);
		// std::cerr << "M1:\n" << *M1 << "\n";
		
		// M2
		this->add(*this, a21Range, a22Range, aResRange, *M2T);
		M2T->classicMul(A, aResRange, b11Range, *M2);
		// std::cerr << "M2:\n" << *M2 << "\n";
		
		// M3
		A.subtract(A, b12Range, b22Range, bResRange, *M3T);
		this->classicMul(*M3T, a11Range, bResRange, *M3);
		// std::cerr << "M3:\n" << *M3 << "\n";
		
		// M4
		A.subtract(A, b21Range, b11Range, bResRange, *M4T);
		this->classicMul(*M4T, a22Range, bResRange, *M4);
		// std::cerr << "M4:\n" << *M4 << "\n";
		
		// M5
		this->add(*this, a11Range, a12Range, aResRange, *M5T);
		M5T->classicMul(A, aResRange, b22Range, *M5);
		// std::cerr << "M5:\n" << *M5 << "\n";
		
		// M6
		this->subtract(*this, a21Range, a11Range, aResRange, *M6T1);
		A.add(A, b11Range, b12Range, bResRange, *M6T2);
		M6T1->classicMul(*M6T2, aResRange, bResRange, *M6);
		// std::cerr << "M6:\n" << *M6 << "\n";
		
		// M7
		this->subtract(*this, a12Range, a22Range, aResRange, *M7T1);
		A.add(A, b21Range, b22Range, bResRange, *M7T2);
		M7T1->classicMul(*M7T2, aResRange, bResRange, *M7);
		// std::cerr << "M7:\n" << *M7 << "\n";
		
		// res11
		res.add(*M1, res11Range, resMulRange, res11Range, res);
		res.add(*M4, res11Range, resMulRange, res11Range, res);
		res.subtract(*M5, res11Range, resMulRange, res11Range, res);
		res.add(*M7, res11Range, resMulRange, res11Range, res);
		
		// res12
		res.add(*M3, res12Range, resMulRange, res12Range, res);
		res.add(*M5, res12Range, resMulRange, res12Range, res);
		
		// res21
		res.add(*M2, res21Range, resMulRange, res21Range, res);
		res.add(*M4, res21Range, resMulRange, res21Range, res);
		
		// res22
		res.add(*M1, res22Range, resMulRange, res22Range, res);
		res.add(*M3, res22Range, resMulRange, res22Range, res);
		res.subtract(*M2, res22Range, resMulRange, res22Range, res);
		res.add(*M6, res22Range, resMulRange, res22Range, res);
		
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
	
	void extend(bool vertically, bool horizontally) {
		if (vertically) {
			std::vector<Type> row(data[0].size());
			data.push_back(row);
		}
		if (horizontally) {
			for (int i = 0; i < data.size(); ++i) {
				Type elem(0);
				data[i].push_back(elem);
			}
		}
	}
	
public:
	// MARK: constructors
	Matrix(std::vector<std::vector<Type> > data) : data(data), rows(data.size()), columns(data[0].size()), shouldCheck(false) { }
	
	Matrix(int rows, int columns) : rows(rows), columns(columns), shouldCheck(false) { 
		for (int i = 0; i < rows; ++i) {
			std::vector<Type> v(columns);
			data.push_back(v);
		}
	}
	
	Matrix() { }
	
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
		Range range(0, rows - 1, 0, columns - 1);
		add(A, range, *res);
		return res;
	}
	
	Matrix* operator*(Matrix &A) {
		if (this->columns != A.rows) {
			throw std::invalid_argument("Invalid matrix passed as a multiplication argument");
		}
		Matrix *res = new Matrix(rows, A.columns);
		Range firstRange(0, rows - 1, 0, columns -1), secondRange(0, A.rows - 1, 0, A.columns - 1);
		
		strassenMul(A, firstRange, secondRange, *res);
		return res;
	}
};

#endif