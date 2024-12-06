#pragma once

// Function for calculating the degree of a number
inline double power(const double base, const int exponent) {
    double result = 1.0;
    for (int i = 0; i < abs(exponent); ++i) {
        result *= base;
    }
    return (exponent < 0) ? 1.0 / result : result;
}

// Function for calculating the factorial
inline unsigned long long factorial(const int n) {
    unsigned long long result = 1;
    for (int i = 2; i <= n; ++i) {
        result *= i;
    }
    return result;
}