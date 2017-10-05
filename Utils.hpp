#ifndef UTILS_HPP
#define UTILS_HPP
#include <string>
#include <vector>
#include <sstream>
#include <bitset>

namespace Utils {
	void HexToIntegers(_In_ std::string hex, _Out_ std::vector<unsigned long>& buffer);
	void IntegersToBinary(_In_ std::vector<unsigned long> numbers, _Out_ std::vector<std::string>& buffer);
	void BinaryToHex(_In_ std::vector<std::string> binaries, _Out_ std::string& buffer);
}

#endif