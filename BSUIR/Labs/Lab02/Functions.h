#pragma once

// Checking if the symbol is a vowel letter
inline bool is_vowel(char c) {
    if (!isalpha(c)) return false;
    c = tolower(c);
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

// Bubble sorting
inline void bubble_sort(std::vector<char>& arr, const bool ascending) {
    const int n = arr.size();
    if (n == 0) return;
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if ((ascending && arr[j] > arr[j + 1]) || (!ascending && arr[j] < arr[j + 1])) {
	            std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// Sorting by ‘comb’
inline void comb_sort(std::vector<char>& arr, const bool ascending) {
    const int n = arr.size();
    int gap = n;
    const double shrink = 1.3;
    bool sorted = false;

    while (!sorted) {
        gap = int(gap / shrink);
        if (gap <= 1) {
            gap = 1;
            sorted = true;
        }

        for (int i = 0; i + gap < n; ++i) {
            if ((ascending && arr[i] > arr[i + gap]) || (!ascending && arr[i] < arr[i + gap])) {
	            std::swap(arr[i], arr[i + gap]);
                sorted = false;
            }
        }
    }
}
