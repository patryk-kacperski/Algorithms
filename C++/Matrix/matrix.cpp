#include <iostream>
#include "matrix.h"

Range::Range(int startRow, int endRow, int startColumn, int endColumn) : 
	startRow(startRow),
	endRow(endRow),
	startColumn(startColumn),
	endColumn(endColumn) { }

std::ostream& operator<<(std::ostream& os, const Range &range) {
	os << range.startRow << "\n" << range.endRow << "\n" << range.startColumn << "\n" << range.endColumn << "\n";
	return os;
}