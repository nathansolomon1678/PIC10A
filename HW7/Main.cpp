#include <iostream>
#include <vector>
#include <string>

#include "Numbers.h"

int main() {
	// obtain two binary numbers to add and convert
	std::cout << "Please enter two nonnegative binary integers: ";
	std::string bin1, bin2;
	std::cin >> bin1 >> bin2;

	// convert each to decimal
	std::string bin1AsDecimal = binaryToDecimal(bin1);
	std::string bin2AsDecimal = binaryToDecimal(bin2);

	// compute sum in binary and decimal
	std::string binarySum = add(bin1, bin2, 2);
	std::string decimalSum = add(bin1AsDecimal, bin2AsDecimal, 10);

	// give the results
	std::cout << "Your first number in decimal is: " << bin1AsDecimal  << '\n';
	std::cout << "Your second number in decimal is: " << bin2AsDecimal  << '\n';
	std::cout << "Their sum in binary is: " << binarySum  << '\n';
	std::cout << "Their sum in decimal is: " << decimalSum << "\n\n";

	// obtain two decimal numbers to add and convert
	std::cout << "Now enter two nonnegative decimal integers: ";
	std::string dec1, dec2;
	std::cin >> dec1 >> dec2;

	// convert each to binary
	std::string dec1AsBinary = decimalToBinary(dec1);
	std::string dec2AsBinary = decimalToBinary(dec2);

	// compute sum in binary and decimal
	decimalSum = add(dec1, dec2, 10);
	binarySum = add(dec1AsBinary, dec2AsBinary, 2);

	// give the results
	std::cout << "Your first number in binary is: " << dec1AsBinary  << '\n';
	std::cout << "Your second number in binary is: " << dec2AsBinary  << '\n';
	std::cout << "Their sum in decimal is: " << decimalSum  << '\n';
	std::cout << "Their sum in binary is: " << binarySum  << '\n';

	return 0;
}
