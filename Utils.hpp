#ifndef UTILS_HPP
#define UTILS_HPP
#include <string>
#include <vector>
#include <sstream>
#include <bitset>

namespace Utils {
	void HexToIntegers(std::string hex, std::vector<unsigned long>& buffer);
	void IntegersToBinary(std::vector<unsigned long> numbers, std::vector<std::string>& buffer);
	void BinaryToHex(std::vector<std::string> binaries, std::string& buffer);
}

#endif