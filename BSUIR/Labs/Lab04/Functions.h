#pragma once
#include <iostream>
#include <cstring>

void input(char* str, int size, const char* prompt) {
    std::cout << prompt;
    std::cin.getline(str, size);
}

void output(int result) {
    if (result == 0)
        std::cout << "The rows are equal." << std::endl;
    else if (result > 0)
        std::cout << "The first line is larger than the second line." << std::endl;
    else
        std::cout << "The first line is smaller than the second line." << std::endl;
}

int strcmp_wrapper(const char* str1, const char* str2) {
    return strcmp(str1, str2);
}

int my_strcmp(const char* str1, const char* str2) {
    while (*str1 && (*str1 == *str2)) {
        ++str1;
        ++str2;
    }

    return static_cast<unsigned char>(*str1) - static_cast<unsigned char>(*str2);
}