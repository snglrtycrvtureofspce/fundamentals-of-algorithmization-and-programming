#include <chrono>
#include <iostream>
#include <vector>
#include "Functions.h"

int main()
{
    constexpr int size = 100;
    char array[size];
    int choice;

    // Выбор способа заполнения массива
    std::cout << "1. Entering data from the keyboard\n";
    std::cout << "2. Filling with random letters\n";
    std::cout << "Choose how to fill the array: ";
    std::cin >> choice;

    switch (choice)
    {
    case 1:
    {
        std::cout << "Enter 100 characters of the Latin alphabet:\n";
        for (int i = 0; i < size; ++i) {
            std::cin >> array[i];
            if (!isalpha(array[i])) {
                std::cout << "Input error: Invalid characters entered.\n";
                return 1;
            }
        }
        break;
    }
    case 2:
    {
        char a, b;
        std::cout << "Enter a range of random letters (A and B): ";
        std::cin >> a >> b;

        if (!isalpha(a) || !isalpha(b))
        {
            std::cout << "Input error: borders should be letters.\n";
            return 1;
        }

        // Arrange A and B
        if (a > b) std::swap(a, b);

        srand(time(0));
        for (int i = 0; i < size; ++i)
        {
            array[i] = a + rand() % (b - a + 1);
        }
        break;
    }
    default:
    {
        std::cout << "Wrong choice.\n";
        return 0;
    }
    }

    std::cout << "Source array:\n";
    for (int i = 0; i < size; ++i)
    {
        std::cout << array[i] << ' ';
    }
    std::cout << '\n';

    // Division into vowels and consonants
    std::vector<char> vowels, consonants;
    for (int i = 0; i < size; ++i)
    {
        if (is_vowel(array[i])) {
            vowels.push_back(array[i]);
        }
        else {
            consonants.push_back(array[i]);
        }
    }

    int sort_choice;

    std::cout << "1. Bubble sorting\n";
    std::cout << "2. Sorting by ‘comb’\n";
    std::cout << "Select a sorting algorithm: ";
    std::cin >> sort_choice;

    if (sort_choice == 1) {
        const auto start = std::chrono::high_resolution_clock::now();
        bubble_sort(vowels, true);  // Vowels in ascending order
        bubble_sort(consonants, false); // Consonants in descending order
        const auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> duration = end - start;
        std::cout << "Sorting runtime (‘Bubble’): " << duration.count() << " seconds\n";
    }
    else if (sort_choice == 2) {
        const auto start = std::chrono::high_resolution_clock::now();
        comb_sort(vowels, true);
        comb_sort(consonants, false);
        const auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> duration = end - start;
        std::cout << "Sorting runtime (‘Comb’): " << duration.count() << " seconds\n";
    }
    else {
	    std::cout << "Wrong sorting algorithm selection.\n";
        return 1;
    }

    // Restore the original order (vowels/consonants)
    int v_index = 0, c_index = 0;
    for (int i = 0; i < size; ++i)
    {
        if (is_vowel(array[i]))
        {
            array[i] = vowels[v_index++];
        }
        else
        {
            array[i] = consonants[c_index++];
        }
    }

    std::cout << "Array after sorting:\n";
    for (int i = 0; i < size; ++i)
    {
        std::cout << array[i] << ' ';
    }
    std::cout << '\n';

    return 0;
}
