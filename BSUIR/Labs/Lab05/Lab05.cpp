#include <iostream>
#include "Functions.h"

int main() {
    int64_t m, n;
    std::cout << "Enter m and n (e.g., 3 5): ";
    std::cin >> m >> n;

    int max_depth = 0;
    std::cout << "\n[Recursive option]:\n";
    int64_t result_recursive = ackermann_recursive(m, n, max_depth);
    std::cout << "Result: " << result_recursive << std::endl;
    std::cout << "Maximum depth of recursive descent: " << max_depth << std::endl;

    std::cout << "\n[Iterative option]:\n";
    int64_t result_iterative = ackermann_iterative(m, n);
    std::cout << "Result: " << result_iterative << std::endl;

    return 0;
}