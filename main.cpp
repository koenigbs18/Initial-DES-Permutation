/*
************************************
@Title:  Initial-DES-Permutation
@Author: Brett Koenig
@Date:   10/4/17
************************************
*/
#include "Utils.hpp"
#include "DESPermutation.hpp"
#include <Windows.h>
#include <iostream>
#include <iomanip>

void PrintPermutation(std::string hex, int index);

// Hex strings to permute
const std::string hex1 = "3a456b73e24d2537";
const std::string hex2 = "624b3a2d92345f3d";

int main()

{
	// Clear system
	system("clear");
	// Print each hex permutation
	PrintPermutation(hex1, 1);
	PrintPermutation(hex2, 2);
	return 0;
}

void PrintPermutation(std::string hex, int index) {
	// Populate numbers array by converting hex string to unsigned longs in a vector
	std::vector<unsigned long> numbers(8);
	Utils::HexToIntegers(hex, numbers);
	// Convert the vector of unsigned long's to a vector of binary strings
	std::vector<std::string> binaries(8);
	Utils::IntegersToBinary(numbers, binaries);
	// Permutate the binary strings
	std::vector<std::string> permutatedBinaries(8, "00000000"); // initialize permutated binaries vector
	DESPermutation::PermutateBinaryStrings(binaries, permutatedBinaries);
	// Convert the binary strings back into a hex string
	std::string hexResult;
	Utils::BinaryToHex(permutatedBinaries, hexResult);
	// Print results
	for (int i = 0; i < 8; i++)
		std::cout << "OG Binary1 " << i << ": " << binaries.at(i) << std::endl; // original binary
	std::cout << std::endl;
	for (int i = 0; i < 8; i++)
		std::cout << "PM Binary1 " << i << ": " << permutatedBinaries.at(i) << std::endl; // permutated binary

	std::cout << "\n" << "Original Hex"  << index << std::setw(5) << ": " << hex;
	std::cout << "\n" << "Permutated Hex" << index << std::setw(3) << ": " << hexResult;
	std::cout << std::endl << std::endl;
}