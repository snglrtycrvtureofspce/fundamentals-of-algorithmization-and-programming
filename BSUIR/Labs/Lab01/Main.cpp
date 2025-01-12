#include <iostream>
#include <cmath>
#include <iomanip>
#include "Functions.h"

int main() 
{
    double x, epsilon;
    int a;

    std::cout << "Enter x (x != 0): ";
    std::cin >> x;
    if (x == 0) 
    {
        std::cout << "Error: x must not equal 0." << '\n';
        return 1;
    }

    std::cout << "Enter a (|a| < 10^6): ";
    std::cin >> a;
    if (abs(a) >= pow(10, 6)) 
    {
        std::cout << "Error: |a| should be less 10^6." << '\n';
        return 1;
    }

    std::cout << "Enter the accuracy of epsilon (e > 0): ";
    std::cin >> epsilon;
    if (epsilon <= 0) 
    {
        std::cout << "Error: epsilon should be bigger 0." << '\n';
        return 1;
    }

    const double b = (epsilon < 1) ? a : 3;

    double s = 0.0;
    int summands_count = 0;
    int k = 0;

    while (true)
    {
        const double summand = power(-1, k + 1) / factorial(2 * k) * power(x / b, 4 * k);

        if (abs(summand) < epsilon) {
            break;
        }

        if (isfinite(summand) && summand != 0) {
            s += summand;
            ++summands_count;
        }

        ++k;
    }

    if (summands_count > 0)
    {
        std::cout << "Sum S: " << std::fixed << std::setprecision(8) << s << '\n';
        std::cout << "Number of counted summations: " << summands_count << '\n';
    }
    else 
    {
        std::cout << "Not a single summand has been accounted for." << '\n';
    }

    return 0;
}
