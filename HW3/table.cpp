#include <iostream>
#include <string>
#include <cmath>
#include <array>
#include <iomanip>

double square(double num) {
    // Return the square of the input
    return num * num;
}

template<size_t T>
double sum(std::array<double, T> nums) {
    double subtotal = 0.;
    for (double num : nums) {
        subtotal += num;
    }
    return subtotal;
}

template<size_t T>
double avg(std::array<double, T> nums) {
    return sum(nums) / T;
}

template<size_t T>
double covariance(std::array<double, T> x, std::array<double, T> y) {
    double x_avg = avg(x);
    double y_avg = avg(x);
    double subtotal = 0.;
    for (int i = 0; i < T; i++) {
        subtotal += (x[i] - x_avg) * (y[i] - y_avg);
    }
    return subtotal / (T - 1.);
}

template<size_t T>
double standard_deviation(std::array<double, T> nums) {
    // There's a much better way to define standard deviation,
    // but for this program, we don't care about efficiency or speed
    return sqrt(covariance(nums, nums));
}

int main() {
    std::array<double, 3> x, y = {0, 0, 0};
    std::cout << "Enter your first x- and y- values separated by a space: ";
    std::cin >> x[0] >> y[0];
    std::cout << "Enter your second x- and y- values separated by a space: ";
    std::cin >> x[1] >> y[1];
    std::cout << "Enter your third x- and y- values separated by a space: ";
    std::cin >> x[2] >> y[2];

    std::string x_label = "", y_label = "";
    std::cout << "Enter your x-label: ";
    // Clear buffer so that getline doesn't reread the \n from the last console input
    std::cin.ignore();
    std::getline(std::cin, x_label);
    std::cout << "Enter your y-label: ";
    std::getline(std::cin, y_label);

    int precision = 0;
    std::cout << "What level of precision would you like? ";
    std::cin >> precision;
    std::cout << std::fixed << std::setprecision(precision);

    // Print table
    std::cout << x_label << '|' << y_label << '\n';
    std::cout << std::string(x_label.size() + 1 + y_label.size(), '-') << '\n';
    for (int i = 0; i < 3; i++) {
        std::cout << std::setw(x_label.size()) << x[i] << '|';
        std::cout << y[i] << '\n';
    }

    // Calculate line of best fit (y=mx+b) and Pearson's correlation coefficient (r)
    double m = covariance(x, y) / square(standard_deviation(x));
    double b = avg(y) - m * avg(x);
    double r = covariance(x, y) / standard_deviation(x) / standard_deviation(y);
    std::cout << "The best fitting equation is: y = " << m << "x + " << b << '\n';
    std::cout << "The correlation coefficient is: " << r << '\n';

    return 0;
}
