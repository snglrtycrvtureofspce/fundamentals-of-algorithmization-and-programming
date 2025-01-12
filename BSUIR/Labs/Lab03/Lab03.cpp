#include <iostream>
#include <vector>
#include "Functions.h"

int main() {
    int n;
    std::cout << "Enter the matrix size (N x N): ";
    while (!(std::cin >> n) || n <= 0) {
        std::cout << "Error! Enter a positive integer: ";
        std::cin.clear();
        std::cin.ignore(10000, '\n');
    }

    std::vector<std::vector<int>> matrix(n, std::vector<int>(n));

    int choice;
    std::cout << "Choose how to fill the matrix:\n";
    std::cout << "1. Entering values manually\n";
    std::cout << "2. Filling with random numbers\n";
    std::cout << "Your choice: ";
    while (!(std::cin >> choice) || (choice != 1 && choice != 2)) {
        std::cout << "Error! Enter 1 or 2: ";
        std::cin.clear();
        std::cin.ignore(10000, '\n');
    }

    if (choice == 1) {
        std::cout << "Enter the elements of the matrix:\n";
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                while (!(std::cin >> matrix[i][j])) {
                    std::cout << "Error! Enter an integer: ";
                    std::cin.clear();
                    std::cin.ignore(10000, '\n');
                }
            }
        }
    }
    else {
        int a, b;
        std::cout << "Enter a range of random numbers [A, B]:\n";
        std::cout << "A: ";
        while (!(std::cin >> a)) {
            std::cout << "Error! Enter an integer: ";
            std::cin.clear();
            std::cin.ignore(10000, '\n');
        }
        std::cout << "B: ";
        while (!(std::cin >> b) || b < a) {
            std::cout << "Error! B must be greater than or equal to A: ";
            std::cin.clear();
            std::cin.ignore(10000, '\n');
        }

        std::srand(std::time(nullptr));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                matrix[i][j] = a + std::rand() % (b - a + 1);
            }
        }
    }

    std::cout << "Initial matrix:\n";
    printMatrix(matrix);

    rotateMatrix90Clockwise(matrix);

    std::cout << "Matrix after rotating 90 degrees clockwise:\n";
    printMatrix(matrix);

    return 0;
}
