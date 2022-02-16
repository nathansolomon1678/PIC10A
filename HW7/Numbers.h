#ifndef _NUMBERS_
#define _NUMBERS_

#include<string>
#include<cstddef>

/**
This function takes a single character and returns an unsigned char for its value from 0-9

@param c the character to convert
@return its value from 0-9
*/
unsigned char charToDigit(char c);

/**
This function converts an unsigned char from 0-9 and returns a char '0' to '9'

@param u the unsigned char to convert
@return its digit representation as a char
*/
char digitToChar(unsigned char u);

/**
This function adds two unsigned integer types, represented as strings, given a base to work in.
The return format will be a sum, computed in whatever base is specified, where 2 <= base <= 10.

For example,
std::string sum1 = add("116", "14", 10); // sum1 == "130"
std::string sum2 = add("11", "10", 2); // sum == "101"

@param first the first addend
@param second the second addend
@param base the base being used: from 2-10

@return the sum, num1+num2 in the base
*/
std::string add(const std::string& first, const std::string& second, unsigned char base);


/**
This function subtracts two unsigned integer types, represented as strings, given a base to work in.
The return format will be a difference, computed in whatever base is specified, with as few digits as possible,
i.e., "0010" would be returned as "10", etc. We require 2 <= base <= 10.

The result is not defined if the minuend is less than the subtrahend!

For example,
std::string diff1 = subtract("130", "14", 10); // diff1 == "116"
std::string diff2 = subtract("101", "10", 2); // diff == "11"
subtract("30", "108", 10); // Do not do this!

@param minuend the term being subtracted from
@param subtrahend the value being subtracted
@param base the base being used

@return the difference, minuend-subtrahend in the base given
*/
std::string subtract(const std::string& minuend, std::string subtrahend, unsigned char base);


/**
This function determines whether two string representations of unsigned integers satisfy <= numerically

For example,
lessThanOrEqual("12", "108"); // true
lessThanOrEqual("100", "100"); // true
lessThanOrEqual("19", "6"); // false

@param first the first number
@param second the second number

@return whether first <= second as unsigned integer types
*/
bool lessThanOrEqual(const std::string& first, const std::string& second);


/**
This function computes 2 to a given nonnegative integer power with the output as an std::string, in base 10

@param pow the power
@return 2 to that power
*/
std::string twoPower(size_t pow);

/**
Reverses the characters of the given string

@param str the string to be reversed
@return the reversed string
*/
void reverseString(std::string& str);

/**
Converts a number in binary to base 10

@param binary_string the number represented in binary, as an std::string
@return the value in base 10, as an std::string
*/
std::string binaryToDecimal(const std::string& binary_string);

/**
Converts a number in base 10 to binary

Note that it passes by value. That's because calculating the binary representation requires
modifying a copy of the decimal representation.

@param num the number represented in base 10, as an std::string
@return the value of num but represented in binary, as an std::string
*/
std::string decimalToBinary(std::string num);

#endif // _NUMBERS_
