#include "Numbers.h"

#include <stdexcept>
#include <string>

// Pass subtrahend by value, because we need to modify it during calculations
std::string subtract(const std::string& minuend, std::string subtrahend, unsigned char base) {	
	// Pad left side of subtrahend so it has as many digits as minuend
	if (subtrahend.size() < minuend.size()) {
		subtrahend = std::string(minuend.size() - subtrahend.size(), '0') + subtrahend;
	}
    // First, convert subtrahend into its complement
    // For example, if the base is 10 and subtrahend is "000254", turn it into "999745"
	for (char& c : subtrahend) {
		c = digitToChar(base - 1 - charToDigit(c));
	}
	// Continuing that example, subtracting 000254 is equivalent to
    // adding 1, then adding 999745, then subtracting 1000000
    // In other words, add one, add complement of subtrahend, then remove the first digit
    // of the sum (which will at that point be 1)
	subtrahend = add(subtrahend, "1", base);
	std::string difference = add(minuend, subtrahend, base);
    // Remove the leading 1
    difference = difference.substr(1);

    // Remove leading zeroes next, making sure as we go that the string is never empty
    while (difference.size() > 0 && difference[0] == '0') {
        difference = difference.substr(1);
    }
    // To avoid ugliness, return "0" instead of ""
    return difference.size() == 0 ? "0" : difference;
}


bool lessThanOrEqual(const std::string& first, const std::string& second) {
    // Assume first and second are in the same base, and that neither have leading zeroes
    // Then if one is longer than the other, it must be larger
	if (first.size() < second.size()) {
		return true;
	} else if (second.size() < first.size()) {
		return false;
	} else {
        // If the numbers have the same length, we can compare digit by digit because the chars 0-9 are ordered
		return first <= second;
	}
}

void reverseString(std::string& str) {
    std::string backwards_string = "";
    for (size_t index = str.size() - 1; index != -1; --index) {
        backwards_string.push_back(str[index]);
    }
    str = backwards_string;
}

std::string add(const std::string& first, const std::string& second, unsigned char base) {
    std::string backwards_sum = "";
    // While adding digit by digit, carry represents the value to be carried over to the next sum
    int carry = 0;
    for (size_t log_place_value = 0; log_place_value < std::max(first.size(), second.size()); ++log_place_value) {
        // Get the digits of the first number and of the second number for the current place value
        // If there's nothing in that position, pretend there was a leading zero
        const int first_digit  = log_place_value <  first.size()
                               ? charToDigit( first[ first.size() - log_place_value - 1])
                               : 0;
        const int second_digit = log_place_value < second.size()
                               ? charToDigit(second[second.size() - log_place_value - 1])
                               : 0;
        const int sum_of_digits = carry + first_digit + second_digit;
        // Modulo gives the part of the sum in the ones' place, which isn't carried over, and
        // integer division gives the part in the tens' place, to be carried over
        backwards_sum.push_back(digitToChar(sum_of_digits % base));
        carry = sum_of_digits / base;
    }
    if (carry != 0) {
        backwards_sum.push_back(digitToChar(carry));
    }
    reverseString(backwards_sum);
    return backwards_sum;
}

char digitToChar(unsigned char u) { return u + '0'; }
unsigned char charToDigit(char c) { return c - '0'; }

std::string twoPower(size_t pow) {
    // Returns 2^pow represented in base 10
    std::string result = "1";
    for (size_t i = 0; i < pow; ++i) {
        result = add(result, result, 10);
    }
    return result;
}

std::string binaryToDecimal(const std::string& binary_string) {
    std::string result = "";
    // For each digit in binary_string (starting from left), add corresponding place value to sum
    for (size_t index = 0; index < binary_string.size(); ++index) {
        std::string place_value = twoPower(binary_string.size() - index - 1);
        if (binary_string[index] == '1') {
            result = add(result, place_value, 10);
        }
    }
    return result;
}

std::string decimalToBinary(std::string num) {
    // Step 1: find the base 2 log of the place value of the first digit of num in binary
    unsigned int max_power = 0;
    while (lessThanOrEqual(twoPower(max_power), num)) {
        max_power++;
    }
    // That incremented max_power so that it is one more than the place value of the first digit of
    // num in binary, so decrement it to make up for that
    max_power--;
    // Step 2: for each power from max_power to zero, subtract 2**power if possible, and if it is
    // possible, record it in the binary string
    std::string binary_str = "";
    for (unsigned int pow = max_power; pow != -1; --pow) {
        if (lessThanOrEqual(twoPower(pow), num)) {
            binary_str.push_back('1');
            num = subtract(num, twoPower(pow), 10);
        } else {
            binary_str.push_back('0');
        }
    }
    return binary_str;
}
