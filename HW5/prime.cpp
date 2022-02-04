#include <iostream>
#include <vector>
#include <cmath>

std::vector<long> prime_factorization(long num) {
    // Assume the input is positive
    std::vector<long> prime_factors = {};
    // Continue testing potential divisors to find prime factors until num is 1,
    // at which point all prime factors have been found.
    // num can be as large as 10 billion, but since we only need to test divisors up to
    // (and including) sqrt(10 billion), potential_divisor can be an int.
    int potential_divisor = 2;
    while (num > 1) {
        // Use static cast just to avoid any weird floating point errors
        if (potential_divisor > static_cast<int>(sqrt(num))) {
            // num isn't divisible by anything less than potential_divisor,
            // that means num is the last prime to be found
            prime_factors.push_back(num);
            break;
        } else if (num % potential_divisor == 0) {
            // This means that potential_divisor is a prime factor of num, so add that prime factor
            // to the list and reset potential_divisor to try to find more prime factors
            prime_factors.push_back(potential_divisor);
            num /= potential_divisor;
            potential_divisor = 2;
        } else {
            potential_divisor++;
        }
    }
    return prime_factors;
}

void print_prime_factors(long num) {
    std::cout << num << ": ";
    std::vector<long> factors = prime_factorization(num);

    if (factors.size() == 0) {
        std::cout << "unit!\n";
    } else if (factors.size() == 1) {
        std::cout << "prime!\n";
    } else {
        // Iterate through the list of factors, printing all of them separated by " x "
        // and end with "\n"
        for (long i = 0; i < factors.size(); i++) {
            if (i < factors.size() - 1) {
                std::cout << factors[i] << " x ";
            } else {
                std::cout << factors[i] << "\n";
            }
        }
    }
}

int main() {
    std::cout << "Enter a range of numbers to factorize. "
              << "Enter lower bound and upper bound separated by a space: ";
    long lower_bound, upper_bound;
    std::cin >> lower_bound >> upper_bound;

    for (long i = lower_bound; i <= upper_bound; i++) {
        print_prime_factors(i);
    }

    return 0;
}
