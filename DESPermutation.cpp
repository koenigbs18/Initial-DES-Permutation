#include "DESPermutation.hpp"

namespace DESPermutation {
/*
Function Permutate
input:       vector of 8 bit binaries as strings
output:      input binaries permutated with the initial DES algorithm
description: This function performs the intial DES permutation
	     on the passed binaries.  The vector of strings
	     acts as a 2D 8x8 array, where the index of the
	     string in the vector is the row, and the index
	     of the character in the string is the the column.
	     Two for loops are used, the first being used to
	     permute the even numbers of the passed binaries,
	     and the second permuting the odd numbers.
*/
void PermutateBinaryStrings(std::vector<std::string> inputBinaries, std::vector<std::string>& outputPermutatedBinaries) {
	// permutating evens ( top half )
	int inputRowIndex = 0, inputColumnIndex = 1; // initialize input row and col indexes for evens parsing
	for (int i = 7; i >= 0; i--) { // output column index
		for (int j = 0; j < 4; j++) { // output row index
			// [j][i] is the permutation output location
			outputPermutatedBinaries.at(j).at(i) = inputBinaries.at(inputRowIndex).at(inputColumnIndex);
			inputColumnIndex += 2; // increment input column counter
		}
		inputRowIndex++; // go to next row in input binaries
		inputColumnIndex = 1; // reset M column to 1 ( evens )
	}

	// permutating odds ( bottom half )
	inputRowIndex = 0, inputColumnIndex = 0; // reset input row and col indexes for odds parsing
	for (int i = 7; i >= 0; i--) { // output column index
		for (int j = 4; j < 8; j++) { // output row index
			// [j][i] is the permutation output location
			outputPermutatedBinaries.at(j).at(i) = inputBinaries.at(inputRowIndex).at(inputColumnIndex);
			inputColumnIndex += 2; // increment input column counter
		}
		inputRowIndex++; // go to next row in input binaries
		inputColumnIndex = 0; // reset M column to 0 ( odds )
	}
}

}
