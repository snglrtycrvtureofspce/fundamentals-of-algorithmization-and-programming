#include "Functions.h"

int main() {
    const int SIZE = 100;
    char str1[SIZE];
    char str2[SIZE];

    input(str1, SIZE, "Enter the first line: ");
    input(str2, SIZE, "Enter the second line: ");

    std::cout << "\n[Result of standard strcmp]:\n";
    int res_std = strcmp_wrapper(str1, str2);
    output(res_std);

    std::cout << "\n[Result of custom my_strcmp]:\n";
    int res_custom = my_strcmp(str1, str2);
    output(res_custom);

    return 0;
}
