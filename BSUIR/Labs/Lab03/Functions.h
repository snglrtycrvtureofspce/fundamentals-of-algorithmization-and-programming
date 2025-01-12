#pragma once
#include <iomanip>
#include <iostream>
#include <ostream>
#include <vector>

void printMatrix(const std::vector<std::vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (const int value : row) {
            std::cout << std::setw(4) << value;
        }
        std::cout << std::endl;
    }
}

void rotateMatrix90Clockwise(std::vector<std::vector<int>>& matrix) {
    const int n = matrix.size();
    for (int i = 0; i < n / 2; ++i) {
        for (int j = i; j < n - i - 1; ++j) {
            const int temp = matrix[i][j];
            matrix[i][j] = matrix[n - j - 1][i];
            matrix[n - j - 1][i] = matrix[n - i - 1][n - j - 1];
            matrix[n - i - 1][n - j - 1] = matrix[j][n - i - 1];
            matrix[j][n - i - 1] = temp;
        }
    }
}