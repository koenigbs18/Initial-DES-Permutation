#include "Utils.hpp"

namespace Utils {

// Converts a vector of binaries into one hex string
void BinaryToHex(_In_ std::vector<std::string> binaries, _Out_ std::string& hexOut) {
	for (int i = 0; i < binaries.size(); i++) {
		std::stringstream s;
		std::bitset<8> bits(binaries.at(i)); // convert string binaries to bitset for conversion functions
		s << std::hex << bits.to_ulong();
		hexOut.append(s.str());
	}
}

// Converts a vector of unsigned long's into binaries using bitset
void IntegersToBinary(_In_ std::vector<unsigned long> numbers, _Out_ std::vector<std::string>& binariesOut) {
	for (int i = 0; i < 8; i++) {
		std::bitset<8> binary(numbers.at(i)); // conversion to 8 bit binary
		binariesOut.at(i).assign(binary.to_string());
	}
}

// Converts a hex string into a vector of integers
void HexToIntegers(_In_ std::string hex, _Out_ std::vector<unsigned long>& numbersOut) {
	for (int i = 2; i < hex.length() + 2; i += 2) {
		std::stringstream ss;
		ss << std::hex << hex.substr(i - 2, 2);
		unsigned num;
		ss >> num;
		int index = (i / 2) - 1;
		numbersOut.at(index) = num;
	}
}

}