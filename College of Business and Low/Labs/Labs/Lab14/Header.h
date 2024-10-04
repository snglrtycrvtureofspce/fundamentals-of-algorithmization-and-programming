#include <iostream>
#include <cmath>

double Rec(int i, int n) {
    return i == n ? sqrt(2 * n) : sqrt(2 * i + Rec(i + 1, n));
}

double srZnachMas(int* arr, int n) {
    if (n == 1) {
        return arr[n - 1];
    }
    return ((n - 1) * srZnachMas(arr, n - 1) + arr[n - 1]) / n;
}

double proizvMas(int* arr, int i)
{
    if (i == 0) {
        return arr[0];
    }
    else {
        return arr[i] * proizvMas(arr, i - 1);
    }
}

int countNubmers(int Number)
{
    if (Number != 0) {
        return 1 + countNubmers(Number / 10);
    }
    else {
        return 0;
    }
}
